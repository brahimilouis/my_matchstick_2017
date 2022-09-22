/*
** EPITECH PROJECT, 2018
** str_isnum
** File description:
** isnum
*/

#include <stdlib.h>

char my_str_isnum(char const *str)
{
	int i = 0;
	int isnum = 0;

	while (str[i] != '\0') {
		if ((str[i] < '0' && str[i] >= 0) || str[i] > '9')
			isnum = -1;
		i = i + 1;
	}
	return (isnum);
}
