/*
** EPITECH PROJECT, 2018
** my_put_arrau
** File description:
** array
*/

#include "my.h"

void my_put_array(char **tab, int line)
{
	int j = 0;
	int size_line = my_strlen(tab[0]);

	for (int i = 0; i < size_line + 2; i++)
		my_putchar('*');
	my_putchar('\n');
	while (j < line) {
		my_putchar('*');
		my_putstr(tab[j]);
		my_putchar('*');
		my_putchar('\n');
		j++;
	}
	for (int i = 0; i < size_line + 2; i++)
		my_putchar('*');
	my_putchar('\n');
}
