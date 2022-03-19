/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:44:17 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/13 17:52:03 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <stdio.h>

int	check_valid(int decalage, t_map *map, t_player *user, int max)
{
	int	posdec;

	posdec = user->pos + decalage;
	if (posdec < 0 || posdec >= map->x * map->y)
		return (0);
	if (map->tab[posdec] == '1' || map->tab[posdec] == '2')
		return (0);
	if (map->tab[posdec] == 69 && user->c != max)
		return (0);
	return (1);
}

void	choose_img(int decalage, t_img *img, int x, int y)
{
	if (B != 1)
		mlx_put_image_to_window(img->mlx, img->win, img->pfront, x, y);
	else
	{
		if (decalage == 1)
			mlx_put_image_to_window(img->mlx, img->win, img->pright, x, y);
		if (decalage == -1)
			mlx_put_image_to_window(img->mlx, img->win, img->pleft, x, y);
		if (decalage < -1)
			mlx_put_image_to_window(img->mlx, img->win, img->pback, x, y);
		if (decalage > 1)
			mlx_put_image_to_window(img->mlx, img->win, img->pfront, x, y);
	}
}

int	move_player(int decalage, t_map *map, t_player *user, t_img *img)
{
	int		userx;
	int		usery;
	int		movex;
	int		movey;

	user->moves++;
	if (map->tab[user->pos + decalage] == 'C')
		user->c++;
	if (map->tab[user->pos + decalage] == 'E' && user->c == map->cmax)
		return (42);
	map->tab[user->pos + decalage] = 'P';
	map->tab[user->pos] = '0';
	user->pos += decalage;
	userx = user->pos % map->x * map->px;
	usery = user->pos / map->x * map->py;
	movex = (user->pos - decalage) % map->x * map->px;
	movey = (user->pos - decalage) / map->x * map->py;
	choose_img(decalage, img, userx, usery);
	mlx_put_image_to_window(img->mlx, img->win, img->floor, movex, movey);
	if (decalage < -1)
		img->dir = 1;
	if (decalage > 1)
		img->dir = 0;
	return (1);
}

int	key_handle(int keycode, t_core *core)
{
	int	i;

	i = 0;
	if (keycode == UP)
		if (check_valid(-core->map->x, core->map, core->user, core->map->cmax))
			i = move_player(-core->map->x, core->map, core->user, core->img);
	if (keycode == DOWN)
		if (check_valid(core->map->x, core->map, core->user, core->map->cmax))
			i = move_player(core->map->x, core->map, core->user, core->img);
	if (keycode == LEFT)
		if (check_valid(-1, core->map, core->user, core->map->cmax))
			i = move_player(-1, core->map, core->user, core->img);
	if (keycode == RIGHT)
		if (check_valid(1, core->map, core->user, core->map->cmax))
			i = move_player(1, core->map, core->user, core->img);
	if (keycode == ESC || i == 42 || core->map->end == 1)
	{
		mlx_destroy_window(core->img->mlx, core->img->win);
		core->anim = 0;
	}
	if (!B && i != 0 && i != 42)
		printf("MOVES : %d\n", core->user->moves);
	return (65);
}
