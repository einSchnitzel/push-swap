/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:47:01 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/23 16:58:06 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_findposa(t_node **a, t_node **b)
{
	int	i;

	i = 0;
	while ((*a)->rank < (*b)->rank)
	{
		(*a)->next;
		i++;
		if ((*b)->rank > (*a)->rank)
			break ;
	}
	return (i);
}
