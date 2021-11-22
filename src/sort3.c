/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:04:12 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/22 15:09:58 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
** Sort three hardcoded
*/
int	ft_sortthree(int argc, t_node **stack)
{
	if (argc == 3)
	{
		ft_swap(stack, 'a');
		return (0);
	}
	if ((*stack)->rank == 0)
	{
		ft_rrot(stack, 'a');
		ft_swap(stack, 'a');
	}
	if ((*stack)->rank == 2)
	{
		ft_rot(stack, 'a');
		if ((*stack)->rank == 1)
			ft_swap(stack, 'a');
	}
	if ((*stack)->rank == 1)
	{
		if ((*stack)->next->rank == 0)
			ft_swap(stack, 'a'); 
		if ((*stack)->next->rank == 2)
			ft_rrot(stack, 'a');
	}
	return (0);
}
