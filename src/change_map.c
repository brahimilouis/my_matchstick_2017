/*
** EPITECH PROJECT, 2018
** change_map
** File description:
** change
*/

#include "my.h"

void check_win(st_var *st)
{
	int i = 0;
	int verif = 0;

	while (i < st->line) {
		if (st->nb_matches[i] != 0)
			verif = 1;
		i++;
	}
	if (verif == 1)
		return;
	else if (st->win == 0)
		st->win = 2;
}

void change_map(st_var *st)
{
	int i = 0;
	int count = 0;

	st->nb_matches[st->entry_line - 1] -= st->entry_match;
	check_win(st);
	if (st->nb_matches[st->entry_line - 1] == 0)
		st->line_remaining--;
	while (st->map[st->entry_line - 1][i] != '|')
		i++;
	while (st->map[st->entry_line - 1][i] != ' '
		&& st->map[st->entry_line - 1][i] != '\0')
		i++;
	i--;
	while (st->entry_match > count) {
		st->map[st->entry_line - 1][i] = ' ';
		i--;
		count++;
	}
}
