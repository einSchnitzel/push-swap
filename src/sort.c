/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:44:14 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/25 16:29:54 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_checkifswapa(t_node **a, t_node **b)
{
	t_node	*last;

	last = ft_lstlast(*a);
	if ((*a)->next->rank < (*a)->rank)
		ft_swap(a, 'a');
	if (last->rank < (*a)->rank)
		ft_rot(a, 'a');
	else
		ft_pushtob(a, b);
	last = ft_lstlast(*a);
	return (last->rank);
}

/*
** inserts elements inbetween last 2 elemnts in longest sequence of a if they fit
*/
int	ft_checkprev(int previous, t_node **a, t_node **b)
{
	t_node	*seclast;
	t_node	*last;

	seclast = ft_lstseclast(*a);
	last = ft_lstlast(*a);
	if (last->rank > (*a)->rank && (seclast)->rank < (*a)->rank)
	{
		ft_rrot(a, 'a');
		ft_swap(a, 'a');
		ft_rot(a, 'a');
		ft_rot(a, 'a');
		last = ft_lstlast(*a);
		previous = last->rank;
	}
	else
		ft_pushtob(a, b);
	return (last->rank);
}

/*
**pushes elements to b and moves largest to end and swaps if smaller than last
*/
int	ft_bucketsb(int size, t_node **a, t_node **b)
{
	ft_pushtob(a, b);
	if ((*b)->rank > (2 * size / 3))
		ft_rot(b, 'b');
	if ((*b)->next->rank < (*b)->rank)
		ft_swap(b, 'b');
	return (1);
}

/*
**pushes elements to b if they don't fit into the longest sequence
*/
int	ft_elementstob(int size, int flag, t_node **a, t_node **b)
{
	int		i;
	int		tob;
	int		previous;

	tob = 0;
	i = 0;
	while (i < size)
	{
		if (flag == 0 && ((*a)->rank < size / 3))
		{
			previous = (*a)->rank;
			ft_rot(a, 'a');
			flag = 1;
		}
		else
		{
			if (flag == 0)
				tob = tob + ft_bucketsb(size, a, b);
			else if (previous > (*a)->rank)
				previous = ft_checkprev(previous, a, b);
			else
				previous = ft_checkifswapa(a, b);
		}
		i++;
	}
	return (tob);
}

int	ft_sortbig(int size, t_node **stack_a, t_node **stack_b)
{
	int	size_b;
	int size_a;

	size_a = ft_lstsize(*stack_a);
	ft_elementstob(size, 0, stack_a, stack_b);
	ft_printlst(*stack_b);
	size_b = ft_lstsize(*stack_b);
	printf("a; %i b: %i\n", size_a, size_b);
	ft_printlst(*stack_a);
	printf("a; %i b: %i\n", size_a, size_b);
	return (0);
}
