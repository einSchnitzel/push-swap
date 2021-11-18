/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:24:09 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/18 16:53:37 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
** finds the rank corresponding to each node.
*/
void ft_printlst(t_node *lst)
{
	while (lst != NULL)
	{
		printf("%i ", lst->num);
		lst = lst->next;
	}
	printf("\n");
}

//error resolved
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
		values[i - 1] = (int)ft_atoi(argv[i]);
		if (value > values[i - 1])
			rank++;
		i++;
	}
	free(values);
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
	node->next = NULL;
	node->num = value;
	node->rank = ft_findrank(value, argv, nvalues);
	ft_printlst(node);
	return (node);
}

/*
** go to last entry in stack
*/
t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
** adds node at front
*/
void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_node **first, t_node *new)
{
	t_node	*lst;

	if (!first || !new)
		return ;
	lst = *first;
	// printf("addback first\t\t\t %i\n",(*first)->num);
	// printf("addback lst \t\t\t %i\n",lst->num);
	// printf("addback new \t\t\t %i\n",new->num);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	lst->next = new;
	new->next = NULL;
}
