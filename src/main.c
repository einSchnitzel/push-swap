/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:21:14 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/12 16:24:28 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdio.h>

// t_node	ft_makestack(char **argv, int nvalues)
// {
// 	int		i;
// 	t_node	first;
// 	t_node	help;
// 	long	value;

// 	i = 1;
// 	value = ft_atoi(argv[i]);
// 	first = ft_makenode(value);
// 	while (i < nvalues)
// 	{
// 		value = ft_atoi(argv[i]);
// 		help = ft_makenode(value);
// 		if (help == NULL)
// 		{
// 			ft_lstclear(&first, free);
// 			return (first);
// 		}
// 		ft_lstadd_back(&first, &help);
// 		i++;
// 	}
// 	return (first);
// }

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc <= 1)
		return (ft_putendl_fd("argn <1", 1));
	if (ft_argvalidcheck(argv, argc))
		return (ft_putendl_fd("Error here", 1));
	//stack_a = ft_makestack(argv, argc - 1);
	// if (stack_a == NULL)
	// 	return (1);
	// stack_b = NULL;
	// ft_createranks(stack_a, argc);
	// while (!ft_checksorted(stack_a, stack_b))
	// {
	// 	ft_sort(stack_a, stack_b, argc - 1);
	// }	
	// ft_freestacks(stack_a, stack_b);
	return (0);
}