/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:28:16 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/23 16:55:48 by smetzler         ###   ########.fr       */
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

int		ft_findrank(int value, char **argv, int nvalues);
void	ft_printlst(t_node *lst);
void	ft_pushtob(t_node **a, t_node **b);
void	ft_pushtoa(t_node **a, t_node **b);
void	ft_swap(t_node **stack, char n);
void	ft_swapboth(t_node **a, t_node **b);
void	ft_rot(t_node **stack, char n);
void	ft_rotboth(t_node **stacka, t_node **stackb);
void	ft_rrot(t_node **stack, char n);
void	ft_rrotboth(t_node **stacka, t_node **stackb);
void	ft_lstclear(t_node **lst);
void	ft_lstdelone(t_node *lst);
void	ft_free(void **arr);
long	ft_atoi(const char *str);
int		ft_isdigit(int n);
int		ft_putendl_fd(char *s, int fd);
t_node	*ft_makenode(char *str, char **argv, int nvalues);
int		ft_checkissorted(t_node **stack_a, int i);
int		ft_checkint(long num);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
int		ft_argvalidcheck(char **argv, int nvalues);
int		ft_inputcheckers(char **argv, int nvalues, int i, int flag);
t_node	*ft_makestack(char **argv, int nvalues);
int		ft_sortsmall(int n, t_node **a, t_node **b);
int		ft_sortthree(int argc, t_node **stack_a);
int		ft_sortfour(t_node **a, t_node **b);
int		ft_sortfive(int size, t_node **a, t_node **b);
void	ft_freestacks(t_node **stack_a, t_node **stack_b);
#endif
