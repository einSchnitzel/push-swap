/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:28:16 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/10 13:43:31 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				num;
	int				rank;
	struct s_node	*next;
}	t_node;

int		ft_atoi(const char *str);
int		ft_isdigit(int n);
t_node	*ft_makenode(long content);
int		ft_checkint(long num);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
int		ft_argvalidcheck(char **argv, int nvalues);
int		ft_checkers(char **argv, int nargs);
t_node	ft_makestack(char **argv, int nvalues);
#endif
