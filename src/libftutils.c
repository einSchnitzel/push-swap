/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:55:52 by smetzler          #+#    #+#             */
/*   Updated: 2021/11/12 15:37:20 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdio.h>

int	ft_isdigit(int n)
{
	if (n < '0' || n > '9')
		return (0);
	return (1);
}

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
