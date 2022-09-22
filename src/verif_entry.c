/*
** EPITECH PROJECT, 2018
** verif_entry
** File description:
** entry
*/

#include "my.h"

void verif_line(char *s, st_var *st)
{
	if (my_str_isnum(s) == -1 || s[0] == '\0') {
		st->verif = -1;
		my_putstr("Error: invalid input (positive number expected)\n");
		return;
	}
	st->entry_line = my_getnbr(s);
	if (st->entry_line > st->line || st->entry_line == 0) {
		my_putstr("Error: this line is out of range\n");
		st->verif = -1;
		return;
	}
	st->verif = 0;
}

void verif_matches2(st_var *st)
{
	int count  = 0;

	if (st->entry_match > st->max) {
		st->verif = -1;
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(st->max);
		my_putstr(" matches per turn\n");
		return;
	}
	count = count_matchs(st);
	if (count < st->entry_match) {
		st->verif = -1;
		my_putstr("Error: not enough matches on this line\n");
	}
}

void verif_matches(char *s, st_var *st)
{
	if (my_str_isnum(s) == -1 || s[0] == '\0') {
		st->verif = -1;
		my_putstr("Error: invalid input (positive number expected)\n");
		return;
	}
	st->entry_match = my_getnbr(s);
	if (st->entry_match == 0) {
		st->verif = -1;
		my_putstr("Error: you have to remove at least one match\n");
		return;
	}
	verif_matches2(st);
}

int count_matchs(st_var *st)
{
	int count = 0;

	for (int i = 0; i < st->col; i++) {
		if (st->map[st->entry_line - 1][i] == '|')
			count++;
	}
	return (count);
}
