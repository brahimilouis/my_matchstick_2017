/*
** EPITECH PROJECT, 2018
** play_ia
** File description:
** ia
*/

#include "my.h"

void many_line(st_var *st)
{
	int j = st->nb_matches[0];
	int nb;

	st->entry_line = 1;
	for (int i = 0; i < st->line; i++) {
		nb = st->nb_matches[i];
		if ((j > nb || j == 0) && nb != 0) {
			st->entry_line = i + 1;
			j = st->nb_matches[i];
		}
	}
	if (j <= st->max)
		st->entry_match = j;
	else
		st->entry_match = st->max;
}

void one_line(st_var *st)
{
	int i = 0;
	int j = 1;

	while (i < st->line && st->nb_matches[i] == 0)
		i++;
	st->entry_line = i + 1;
	if (st->nb_matches[i] == 1)
		st->win = 1;
	while ((st->nb_matches[i] - j) % (st->max + 1) != 0 && j != 4)
		j++;
	if (j != 1)
		st->entry_match = j - 1;
	else
		st->entry_match = 1;
}

void play_ia(st_var *st)
{
	display_player(st);
	change_map(st);
	my_put_array(st->map, st->line);
	if (st->win == 2)
		return;
	if (st->line_remaining != 1)
		many_line(st);
	else
		one_line(st);
	change_map(st);
	my_putstr("\nAI's turn...\nAI removed ");
	my_put_nbr(st->entry_match);
	my_putstr(" match(es) from line ");
	my_put_nbr(st->entry_line);
	my_putchar('\n');
	my_put_array(st->map, st->line);
	if (st->win == 0)
		my_putstr("\nYour turn:\n");
}
