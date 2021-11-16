/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputcheckers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:02:57 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/16 15:35:03 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdio.h>

/*
** Checks if stack is already sorted
** i is 1 for stack a and -1 for stack b
*/
int	ft_checkissorted(t_node **stack_a, int i)
{
	t_node	*stack;
	int		rank;
	int		n;

	n = 0;
	stack = *stack_a;
	if (i != -1 && i != 1)
		return (ft_putendl_fd("debug: iter for ranks is not correct", 1));
	if (stack_a == NULL)
		return (ft_putendl_fd("debug: stack_a empty", 1));
	rank = stack->rank;
	write(1,"before loop\n",13);
	while (stack->next != NULL)
	{
		printf("%ith;\t%i, rank %i\n", n, stack->num, stack->rank);
		stack = stack->next;
		if ((stack->rank - rank) != i)
			return (0);
		n++;
		rank = stack->rank;
	}
	printf("%ith;\t%i, rank %i\n", n, stack->num, stack->rank);
	return (1);
}

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
			if (argv[i][0] == '-' && argv[i][1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	if (ft_inputcheckers(argv, nvalues - 1, 0, 0))
	{
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

int	ft_inputcheckers(char **argv, int nvalues, int i, int flag)
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
