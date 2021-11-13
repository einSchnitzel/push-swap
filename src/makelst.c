/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:24:09 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/13 16:29:12 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
** finds the rank corresponding to each node.
*/

int	ft_findrank(int value, char **argv, int nvalues)
{
	int	*values;
	int	i;
	int	rank;

	i = 1;
	rank = 0;
	values = malloc(sizeof(int) * nvalues);
	if (values == NULL)
		return (-1);
	while (i <= nvalues)
	{
		values[i] = (int) ft_atoi(argv[i]);
		if (value > values[i])
			rank++;
		i++;
	}
	ft_free((void **)&values);
	return (rank);
}

/*
** Creates each node and assigns it a rank and its value
*/
t_node	*ft_makenode(char *str, char **argv, int nvalues)
{
	t_node	*node;
	int		value;

	value = (int) ft_atoi(str);
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = value;
	node->rank = ft_findrank(value, argv, nvalues);
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
