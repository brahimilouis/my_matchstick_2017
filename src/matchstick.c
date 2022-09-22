/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matches
*/

#include "my.h"

void matchstick(st_var *st)
{
	char *line;
	char *matches;

	while (st->win == 0) {
		my_putstr("Line: ");
		line = get_next_line(0);
		if (line == NULL)
			return;
		verif_line(line, st);
		free(line);
		if (st->verif == 0) {
			my_putstr("Matches: ");
			matches = get_next_line(0);
		}
		if (st->verif == 0 && matches == NULL)
			return;
		else if (st->verif == 0)
			verif_matches(matches, st);
		if (st->verif == 0)
			play_ia(st);
	}
}
