/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:21:14 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/13 16:37:28 by smetzler         ###   ########.fr       */
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
	t_node	*first;

	i = 1;
	first = NULL;
	node = NULL;
	first = ft_makenode(argv[i], argv, nvalues - 1);
	i++;
	printf("%d rank %d\n", first->num, first->rank);
	while (i < nvalues)
	{
		node = ft_makenode(argv[i], argv, nvalues - 1);
		if (node->rank == -1 || node == NULL)
		{
			ft_lstclear(&first);
			ft_lstclear(&node);
			return (NULL);
		}
		printf("%i, rank %i\n", node->num, node->rank);
		ft_lstadd_back(&first, node);
		i++;
	}
	return (first);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc <= 1)
		return (0);
	if (ft_argvalidcheck(argv, argc))
		return (ft_putendl_fd("Error", 1));
	ft_putendl_fd("main", 1);
	stack_a = ft_makestack(argv, argc);
	if (stack_a == NULL)
		return (ft_putendl_fd("Memory Error", 1));
	stack_b = NULL;
	

	// stack_b = NULL;
	// while (ft_checkifsorted(stack_a))
	// {
	// 	ft_sort(stack_a, stack_b, argc - 1);
	// }
	ft_freestacks(&stack_a, &stack_b);
	return (0);
}