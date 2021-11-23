/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:04:12 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/23 16:59:23 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
** Sort three hardcoded works
*/
int	ft_sortthree(int n, t_node **a)
{
	t_node	*last;

	last = ft_lstlast(*a);
	if ((*a)->rank < (*a)->next->rank && (*a)->next->rank < last->rank)
		return (1);
	if ((*a)->rank < (*a)->next->rank && (*a)->rank < last->rank)
	{
		if (n == 3)
			ft_rrot(a, 'a');
		ft_swap(a, 'a');
	}
	else if ((*a)->rank < last->rank && (*a)->rank > (*a)->next->rank)
		ft_swap(a, 'a');
	else if ((*a)->rank > last->rank && (*a)->rank < (*a)->next->rank)
		ft_rrot(a, 'a');
	else
	{
		ft_rot(a, 'a');
		if ((*a)->rank > (*a)->next->rank)
			ft_swap(a, 'a');
	}
	return (1);
}

int	ft_sortfour(t_node **a, t_node **b)
{
	t_node	*last;

	if (ft_checkissorted(a, 1))
		return (1);
	last = ft_lstlast(*a);
	if ((*a)->rank == 2)
		ft_swap(a, 'a');
	if (ft_checkissorted(a, 1))
		return (1);
	ft_pushtob(a, b);
	ft_sortthree(3, a);
	ft_pushtoa(a, b);
	if ((*a)->rank == 0)
		return (1);
	else if ((*a)->rank == 1)
		ft_swap(a, 'a');
	else if ((*a)->rank == 3)
		ft_rot(a, 'a');
	return (1);
}

// error at 3 4 2 0 1
int	ft_sortfive(int size, t_node **a, t_node **b)
{
	int pos;
	int i;

	if ((*a)->rank >= 3)
		ft_rot(a, 'a');
	ft_printlst(*a);
	ft_pushtob(a, b);
	ft_pushtob(a, b);
	ft_sortthree(3, a);
	ft_printlst(*a);
	if ((*b)->rank < (*b)->next->rank)
		ft_swap(b, 'b');
	pos = ft_findposa(a, b);
	ft_gotopos(size, pos, a);
	ft_pushtoa(a, b);
	
	return (1);
}

int	ft_sortsmall(int n, t_node **a, t_node **b)
{
	t_node	*last;

	last = ft_lstlast(*a);
	if (n == 3)
		ft_sortthree(n, a);
	if (n == 4)
		ft_sortfour(a, b);
	if (n == 5)
		ft_sortfive(a, b);
	return (1);
}
