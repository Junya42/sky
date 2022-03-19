/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:53:40 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/13 17:19:49 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	best_move(t_map *m, t_player *u, int mx, int px)
{
	int	cp;

	cp = u->pos - 1;
	while (++cp <= u->epos)
	{
		if (cp == mx && check_previous(m, mx))
			return (-m->x);
		if (cp == u->epos - 1 && check_previous(m, u->epos - 1))
			return (-1);
	}
	cp = u->pos + 1;
	while (--cp >= u->epos)
	{
		if (cp == px && check_previous(m, px))
			return (m->x);
		if (cp == u->epos + 1 && check_previous(m, u->epos + 1))
			return (1);
	}
	return (42);
}

int	rest(t_map *map, t_player *user, t_img *img)
{
	int	xpos;
	int	ypos;

	xpos = ((user->epos % map->x) * map->px);
	ypos = ((user->epos / map->x) * map->py);
	mlx_put_image_to_window(img->mlx, img->win, \
			img->eafk, xpos, ypos);
	return (7);
}

void	choose_new_sprite(t_map *map, t_player *user, t_img *img, int choice)
{
	int	x;
	int	y;

	x = ((user->epos % map->x) * map->px);
	y = ((user->epos / map->x) * map->py);
	if (choice == 1)
		mlx_put_image_to_window(img->mlx, img->win, img->eright, x, y);
	else if (choice == -1)
		mlx_put_image_to_window(img->mlx, img->win, img->eleft, x, y);
	else if (choice == map->x)
		mlx_put_image_to_window(img->mlx, img->win, img->efront, x, y);
	else if (choice == -map->x)
		mlx_put_image_to_window(img->mlx, img->win, img->eback, x, y);
}

int	choose_move(t_map *map, t_player *user, t_img *img, int choice)
{
	int	x;
	int	y;

	x = ((user->epos % map->x) * map->px);
	y = ((user->epos / map->x) * map->py);
	choice = best_move(map, user, user->epos - map->x, user->epos + map->x);
	if (choice != 42 && choice != -42)
	{
		mlx_put_image_to_window(img->mlx, img->win, img->floor, x, y);
		user->epos += choice;
		choose_new_sprite(map, user, img, choice);
	}
	else
		rest(map, user, img);
	return (1);
}

int	spawn(t_map *map, t_player *user, t_img *img, t_core *core)
{
	user->enemy = 0;
	if (core->status % 1500 == 0)
	{
		if (user->moves >= 5)
			user->enemy = 1;
		if (user->enemy == 1)
		{
			choose_move(map, user, img, 0);
			if (user->epos == user->pos)
			{
				core->anim = 0;
				core->map->end = 1;
			}
		}
		core->status = 0;
	}
	return (0);
}
