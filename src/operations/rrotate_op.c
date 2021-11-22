/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:17:18 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/22 13:17:15 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

t_node	*ft_lstseclast(t_node *lst)
{
	if (!lst|| !lst->next)
		return (NULL);
	while (lst->next->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_rrot(t_node **stack, char n)
{
	t_node	*helper;
	t_node	*last;

	helper = ft_lstseclast(*stack);
	last = ft_lstlast(*stack);
	helper->next = NULL;
	helper = *stack;
	*stack = last;
	(*stack)->next = helper;
	write(1, "rr",2);
	if (n == 'a')
		write(1, "a\n",2);
	if (n == 'b')
		write(1, "b\n",2);
}

void	ft_rrotboth(t_node **stacka, t_node **stackb)
{
	t_node	*helper;
	t_node	*last;

	helper = ft_lstseclast(*stacka);
	last = ft_lstlast(*stacka);
	helper->next = NULL;
	helper = *stacka;
	*stacka = last;
	last->next = helper;
	(*stacka)->next = helper;
	helper = ft_lstseclast(*stackb);
	last = ft_lstlast(*stackb);
	helper->next = NULL;
	helper = *stackb;
	*stackb = last;
	last->next = helper;
	(*stackb)->next = helper;
	write(1, "rrr\n",4);
}
