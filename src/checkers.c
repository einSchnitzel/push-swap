/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:02:57 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/12 16:09:05 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdio.h>

/*
** Checks if all input parameters have number formatting,
** no duplicates are within the int value rangeß
*/
int	ft_argvalidcheck(char **argv, int nvalues)
{
	int	i;
	int	j;

	i = 1;
	while (i < nvalues)
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("%c no digit\n", argv[i][j]);
				return (1); 
			}
			if ((argv[i][0] == '-' && argv[i][1] == '\0') || j > 10)
			{
				ft_putendl_fd("Error no number", 1);
				return (1);
			}
			j++;
		}
		i++;
	}
	if (ft_checkers(argv, nvalues, 1, 0))
	{
		printf("checkers failed\n");
		return (1);
	}
	printf("checkers xyz\n");
	return (0);
}

int	ft_checkint(long num)
{
	if (num > 2147483647 || num < -2147483648)
	{
		printf("%ld is not an integer \n", num);
		return (1);
	}
	return (0);
}

/*
** Checks if all input parameters have
** no duplicates and is within integer range
*/

int	ft_checkers(char **argv, int nvalues, int i, int flag)
{
	long	*values;
	int		j;

	values = malloc(sizeof(long) * nvalues);
	if (values == NULL)
		return (1);
	while (i < nvalues)
	{
		j = 0;
		values[i - 1] = ft_atoi(argv[i]);
		printf("value: %li\n", values[i-1]);
	 	while (j < i)
		{
			if (values[j] == values[i - 1])
				flag = 1;
			j++;
		}
		if (ft_checkint(values[i - 1]))
			flag = 1;
		i++;
	}
	free(values);
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
