/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:57:53 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/13 17:44:09 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_len(int fd, char *str, t_map *map)
{
	char	c;
	int		len;
	int		flag;

	len = 0;
	flag = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			if (flag++ == 0)
				map->x = len;
			continue ;
		}
		len++;
	}
	close(fd);
	return (len);
}

int	get_size(int fd, char *str)
{
	char	c;
	int		len;

	len = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &c, 1) > 0)
		len++;
	close(fd);
	return (len);
}

int	*oned_map(int fd, int len, char *str)
{
	int		*tab;
	char	c;
	int		i;

	i = 0;
	c = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	tab = malloc(sizeof(int) * (len));
	if (!tab)
		return (0);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			continue ;
		tab[i] = c;
		i++;
	}
	close(fd);
	return (tab);
}

int	ft_err(void)
{
	write(2, "Invalid map.\n", 13);
	return (0);
}
