/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:25:08 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/13 16:37:33 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
**	everything to free and free lst
*/

void	ft_free(void **arr)
{
	if (*arr != NULL)
	{
		free(*arr);
	}
	arr = NULL;
}

void	ft_lstdelone(t_node *lst)
{
	if (lst)
	{
		ft_free((void **)&lst);
		lst = NULL;
	}
}

void	ft_lstclear(t_node **lst)
{
	t_node	*helper;

	while (*lst)
	{	
		helper = (*lst)->next;
		ft_lstdelone(*lst);
		(*lst) = helper;
	}
	*lst = NULL;
}

void	ft_freestacks(t_node **stack_a, t_node **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}
