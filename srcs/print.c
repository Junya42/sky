/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:57:09 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/13 17:42:59 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_surrounding(t_img *img, t_map *map, int x, int y)
{
	int	i;
	int	a;

	i = -1;
	a = (x - 1) * map->px;
	while (++i < y - 1)
	{
		mlx_put_image_to_window(img->mlx, \
				img->win, img->roof, 0, map->px * i);
		mlx_put_image_to_window(img->mlx, \
				img->win, img->roof, a, map->px * i);
	}
}

void	inside_walls(t_img *img, t_map *m, int b)
{
	int	check;

	check = 0;
	while (--b)
	{
		check = m->tab[b + m->x];
		if ((m->tab[b] == '1' || m->tab[b] == '2') && b + m->x < m->len)
		{
			if ((check != '1' && check != '2') && b % 7 == 0)
			{
				mlx_put_image_to_window(img->mlx, img->win, \
						img->light, (b % m->x) \
						* m->px, (b / m->x) * m->py);
				m->tab[b] = '2';
			}
			else if (check != '1' && check != '2')
				mlx_put_image_to_window(img->mlx, img->win, \
						img->wall, (b % m->x) \
						* m->px, (b / m->x) * m->py);
			else if (check == '1' || check == '2')
				mlx_put_image_to_window(img->mlx, img->win, \
						img->roof, (b % m->x) \
						* m->px, (b / m->x) * m->py);
		}
	}
}

void	outside_walls(t_img *img, t_map *map)
{
	int	i;

	i = 0;
	while (++i < map->x)
	{
		if (map->tab[i + map->x] == '1')
			mlx_put_image_to_window(img->mlx, img->win, \
					img->roof, (i % map->x) * map->px, (i / map->x) * map->py);
	}
}

t_img	*put_game(t_map *map, t_player *user)
{
	t_img	*img;
	int		a;
	int		b;

	a = ((user->pos % map->x) * map->px);
	b = ((user->pos / map->x) * map->py);
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	get_imgs(img, map);
	img->dir = 0;
	put_entities(img, map, -1, 0);
	if (!B)
		mlx_put_image_to_window(img->mlx, img->win, img->pfront, a, b);
	else
	{
		inside_walls(img, map, map->len - map->x);
		put_surrounding(img, map, map->x, map->y);
		outside_walls(img, map);
	}
	return (img);
}

void	put_entities(t_img *img, t_map *map, int i, int b)
{
	int	a;

	while (++i < map->len)
	{
		a = ((i % map->x) * map->px);
		b = ((i / map->x) * map->py);
		if (map->tab[i] == '1' && i >= map->len - map->x)
			mlx_put_image_to_window(img->mlx, img->win, img->wall, a, b);
		else if (map->tab[i] == '1' && B && i != 0 && i <= map->x && i % 3 == 0)
		{
			mlx_put_image_to_window(img->mlx, img->win, img->light, a, b);
			if (map->tab[i + map->x] != '1' && map->tab[i + map->x] != '2')
				map->tab[i] = '2';
		}
		else if (map->tab[i] == '1')
			mlx_put_image_to_window(img->mlx, img->win, img->wall, a, b);
		else if (map->tab[i] == '0')
			mlx_put_image_to_window(img->mlx, img->win, img->floor, a, b);
		else if (map->tab[i] == 'C')
			mlx_put_image_to_window(img->mlx, img->win, img->shiny, a, b);
		else if (map->tab[i] == 'P')
			mlx_put_image_to_window(img->mlx, img->win, img->afk, a, b);
		else if (map->tab[i] == 'E')
			mlx_put_image_to_window(img->mlx, img->win, img->exit, a, b);
	}
}
