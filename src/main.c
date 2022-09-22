/*
** EPITECH PROJECT, 2018
** main
** File description:
** mai
*/

#include "my.h"

char **prepare_matchstick(int line, st_var *st)
{
	int i = 0;
	int j = 0;
	char **map = malloc(sizeof(char *) * (line + 1));

	st->col = 1 + ((line - 1) * 2);
	map[0] = malloc(sizeof(char) * (st->col + 1));
	while (j < line) {
		if (i < st->col / 2 - j || i > st->col / 2 + j)
			map[j][i] = ' ';
		else
			map[j][i] = '|';
		i++;
		if (i >= st->col) {
			map[j][i] = '\0';
			j++;
			i = 0;
		}
		if (i == 0)
			map[j] = malloc(sizeof(char) * (st->col + 1));
	}
	return (map);
}

int verif_error(int ac, char **av)
{
	int nb;

	if (ac != 3)
		return (-1);
	if (my_str_isnum(av[1]) == -1 || my_str_isnum(av[2]) == -1)
		return (-1);
	nb = my_getnbr(av[1]);
	if (nb < 1 || nb >= 100)
		return (-1);
	if (my_getnbr(av[2]) < 1)
		return (-1);
	return (0);
}

void prepare_nb_matches(st_var *st)
{
	int i = 0;
	int count = 1;

	st->nb_matches = malloc(sizeof(int) * (st->line + 1));
	while (i < st->line) {
		st->nb_matches[i] = count;
		count += 2;
		i++;
	}
}

int main(int ac, char **av)
{
	st_var st;

	if (verif_error(ac, av) == -1)
		return (84);
	st.max = my_getnbr(av[2]);
	st.line = my_getnbr(av[1]);
	st.line_remaining = st.line;
	st.map = prepare_matchstick(st.line, &st);
	prepare_nb_matches(&st);
	st.win = 0;
	my_put_array(st.map, st.line);
	my_putstr("\nYour turn:\n");
	matchstick(&st);
	if (st.win == 1)
		my_putstr("I lost... snif... but I'll get you next time!!\n");
	else if (st.win == 0) {
		my_putchar('\n');
		return (0);
	} else
		my_putstr("You lost, too bad...\n");
	return (st.win);
}
