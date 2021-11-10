/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:25:08 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/10 15:53:04 by smetzler         ###   ########.fr       */
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

void	ft_lstdelone(t_node *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->num);
		del(lst->rank);
		free(lst);
	}
}

void	ft_lstclear(t_node **lst, void (*del)(void *))
{
	t_node	*helper;

	while (*lst && del)
	{	
		helper = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = helper;
	}
	*lst = NULL;
}
