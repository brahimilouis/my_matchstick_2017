/*
** EPITECH PROJECT, 2018
** display_player
** File description:
** display_play
*/

#include "my.h"

void display_player(st_var *st)
{
	my_putstr("Player removed ");
	my_put_nbr(st->entry_match);
	my_putstr(" match(es) from line ");
	my_put_nbr(st->entry_line);
	my_putchar('\n');
}
