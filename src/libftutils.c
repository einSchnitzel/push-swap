/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:55:52 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/25 16:28:18 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_isdigit(int n)
{
	if (n < '0' || n > '9')
		return (0);
	return (1);
}
/*
** determine size of list
*/
int	ft_lstsize(t_node *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

/*
** Write array into long 
*/
long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	sum;

	sum = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' )
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		sum = -sum * 10;
		sum = -sum - (str[i] - '0');
		i++;
	}
	return (-sum * sign);
}

/*
** Write a string and but a Newline at the end
*/
int	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	write(fd, "\n", 1);
	return (0);
}
