/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:02:57 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/10 18:15:14 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
** Checks if all input parameters have number formatting,
** no duplicates are within the int value rangeß
*/
int	ft_argvalidcheck(char **argv, int nvalues)
{
	int	i;
	int	j;

	i = 0;
	while (i < nvalues)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][0] == '-' && j == 0)
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (1);
			if ((argv[i][0] == '-' && argv[i][1] == '\0') || j > 10)
				return (1);
			j++;
		}
		i++;
	}
	if (ft_checkers(argv, nvalues, 0, 0))
		return (1);
	return (0);
}

int	ft_checkint(long num)
{
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0);
}

/*
** Checks if all input parameters have
** no duplicates and is within integer range
*/

int	ft_checkers(char **argv, int nvalues, int i, int flag)
{
	int	*values;
	int	j;

	values = malloc(sizeof(long) * nvalues);
	if (!values)
		return (1);
	while (i < nvalues)
	{
		j = 0;
		values[i] = ft_atoi(argv[i + 1]);
		while (j < i)
		{
			if (values[j] == values[i])
				flag = 1;
			j++;
		}
		if (ft_checkint(values[i]))
			flag = 1;
		i++;
	}
	ft_free((void **)&values)
	return (flag);
}

/*
** check 11 03 -234 testcase
** Write a string and but a Newline at the end
*/

int	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	write(fd, "\n", 1);
	return (0);
}
