/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:21:14 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/18 16:53:21 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdio.h>

/*
** Creates the stack, frees it if an error occurs at allocation
*/

t_node	*ft_makestack(char **argv, int nvalues)
{
	int		i;
	t_node	*node;
	t_node	*head;

	node = NULL;
	head = NULL;
	i = 1;
	head = ft_makenode(argv[i], argv, nvalues - 1);
	i++;
	while (i < nvalues)
	{
		node = NULL;
		node = ft_makenode(argv[i], argv, nvalues - 1);
		if (node == NULL || node->rank == -1)
		{
			ft_lstclear(&head);
			ft_lstclear(&node);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		ft_printlst(head);
		i++;
	}
	return (head);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	int		issorted;
	//t_node	*stack_b;

	if (argc <= 1)
		return (0);
	if (ft_argvalidcheck(argv, argc))
		return (ft_putendl_fd("Error", 1));
	stack_a = ft_makestack(argv, argc);
	if (stack_a == NULL)
		return (ft_putendl_fd("Memory Error", 1));
	issorted = ft_checkissorted(&stack_a, 1);
	if (issorted == 0)
	{
		// printf("is not sorted\n");
		// stack_b = ft_makenode(argv[2], argv, argc - 1);
		// printf("stacka1: \t%i, rank %i\n", stack_a->num, stack_a->rank);
		// printf("stackb1: \t%i, rank %i\n", stack_b->num, stack_b->rank);
		// ft_pushtoa(&stack_b, &stack_a);
		// printf("stacka1: \t%i, rank %i\n", stack_a->num, stack_a->rank);
		// printf("stackb1: \t%i, rank %i\n", stack_b->num, stack_b->rank);
		//ft_sort(&stack_a, argc - 1);
	}
	return (0);
}
