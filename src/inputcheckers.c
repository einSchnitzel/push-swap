/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputcheckers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:02:57 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/13 16:26:03 by smetzler         ###   ########.fr       */
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
				return (1);
			//printf("%c is digit\n", argv[i][j]);
			if (argv[i][0] == '-' && argv[i][1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	if (ft_checkers(argv, nvalues - 1, 0, 0))
	{
		//printf("checkers failed\n");
		return (1);
	}
	return (0);
}

int	ft_checkint(long num)
{
	if (num > 2147483647 || num < -2147483648)
	{
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
		values[i] = ft_atoi(argv[i + 1]);
		while (j < i)
		{
			if (values[j] == values[i])
				flag = 1;
			j++;
		}
		if (ft_checkint(values[i]) || flag == 1)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	free(values);
	return (flag);
}
