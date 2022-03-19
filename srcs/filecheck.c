/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:56:28 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/09 03:56:29 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_checkfile(char *filename)
{
	int	index;

	index = ft_strlen(filename);
	if (filename[index - 1] == '\\' || filename[index - 1] == '/')
		return (0);
	if (filename[index - 1] != 'r')
		return (0);
	if (filename[index - 2] != 'e')
		return (0);
	if (filename[index - 3] != 'b')
		return (0);
	if (filename[index - 4] != '.')
		return (0);
	return (1);
}
