/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:21:57 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/19 10:37:17 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

/*
** Pushes top of b to a
*/
void	ft_pushtoa(t_node **a, t_node **b)
{
	t_node	*helper;

	if (*b == NULL)
		return ;
	helper = *b;
	*b = (*b)->next;
	helper->next = *a;
	*a = helper;
	write(1,"pa\n",3);
}

/*
** Pushes top of a to b
*/
void	ft_pushtob(t_node **a, t_node **b)
{
	t_node	*helper;

	if (*a == NULL)
		return ;
	helper = *a;
	*a = (*a)->next;
	helper->next = *b;
	*b = helper;
	write(1,"pb\n",3);
}