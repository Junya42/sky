/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 01:27:48 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/11 06:08:22 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_convert_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	else
		n = -n;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*ft_norm(long int nl, char *res, int i)
{
	res[i--] = '\0';
	if (nl == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (nl < 0)
	{
		res[0] = '-';
		nl = -nl;
	}
	while (nl != 0)
	{
		res[i--] = nl % 10 + '0';
		nl = nl / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	long int	nl;

	nl = 0;
	nl = (long int)n;
	i = 0;
	i = ft_convert_size(n);
	res = (char *)malloc(sizeof(char) * ft_convert_size(n) + 1);
	if (!res)
		return (NULL);
	return (ft_norm(nl, res, i));
}
