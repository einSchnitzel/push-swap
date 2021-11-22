/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:17:22 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/22 11:23:12 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	ft_swap(t_node **stack, char n)
{
	t_node	*firsttosec;

	if (*stack == NULL)
		return ;
	firsttosec = *stack;
	*stack = (*stack)->next;
	firsttosec->next = (*stack)->next;
	(*stack)->next = firsttosec;
	write(1, "s",1);
	if (n == 'a')
		write(1, "a\n",2);
	if (n == 'b')
		write(1, "b\n",2);
}

void	ft_swapboth(t_node **a, t_node **b)
{
	t_node	*firsttosec;

	if (*a == NULL || (*a)->next == NULL || (*b)->next == NULL || *b == NULL)
		return ;
	firsttosec = *a;
	*a = (*a)->next;
	firsttosec->next = (*a)->next;
	(*a)->next = firsttosec;
	firsttosec = *b;
	*b = (*b)->next;
	firsttosec->next = (*b)->next;
	(*b)->next = firsttosec;
	write(1, "ss\n",3);
}