/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:17:14 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/22 11:02:59 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	ft_rot(t_node **stack, char n)
{
	t_node	*helper;
	t_node	*last;

	helper = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	last->next = helper;
	helper->next = NULL;
	write(1, "r",1);
	if (n == 'a')
		write(1, "a\n",2);
	if (n == 'b')
		write(1, "b\n",2);
}

void	ft_rotboth(t_node **stacka, t_node **stackb)
{
	t_node	*helper;
	t_node	*last;

	helper = *stacka;
	last = ft_lstlast(*stacka);
	*stacka = (*stacka)->next;
	last->next = helper;
	helper->next = NULL;
	helper = *stackb;
	last = ft_lstlast(*stackb);
	*stackb = (*stackb)->next;
	last->next = helper;
	helper->next = NULL;
	write(1, "rr\n",3);
}
