/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:24:09 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/10 13:58:00 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_node	*ft_makenode(long content)
{
	t_node		*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = content;
	node->rank = -1;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	last = *lst;
	if (last)
	{
		while (last && new && last->next)
			last = last->next;
		last->next = new;
	}
	else
		*lst = new;
}
