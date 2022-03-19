/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:46:35 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/13 14:59:50 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_lights(t_img *img, int a, int b, int game)
{
	if (game > 300)
		mlx_put_image_to_window(img->mlx, img->win, img->light1, a, b);
	if (game > 600)
		mlx_put_image_to_window(img->mlx, img->win, img->light2, a, b);
	if (game > 900)
		mlx_put_image_to_window(img->mlx, img->win, img->light, a, b);
}

void	anim_shiny(t_img *img, int a, int b, int game)
{
	if (game > 500)
		mlx_put_image_to_window(img->mlx, img->win, img->shiny2, a, b);
	if (game > 1000)
		mlx_put_image_to_window(img->mlx, img->win, img->shiny3, a, b);
	if (game > 1500)
		mlx_put_image_to_window(img->mlx, img->win, img->shiny4, a, b);
	if (game > 2000)
		mlx_put_image_to_window(img->mlx, img->win, img->shiny3, a, b);
	if (game > 2500)
		mlx_put_image_to_window(img->mlx, img->win, img->shiny2, a, b);
	if (game > 2999)
		mlx_put_image_to_window(img->mlx, img->win, img->shiny, a, b);
}

void	printmove(t_img *img, int move, t_player *user, int mx)
{
	char	*str;
	int		x;
	int		y;

	str = NULL;
	x = (user->pos % mx) * 64;
	y = (user->pos / mx) * 64;
	str = ft_itoa(move);
	mlx_string_put(img->mlx, img->win, x, y + 16, 0xFFFFFF, str);
	free(str);
}

void	game(t_core *core)
{
	int	a;
	int	b;
	int	i;

	i = -1;
	a = 0;
	b = 0;
	core->game++;
	core->status++;
	printmove(core->img, core->user->moves, core->user, core->map->x);
	spawn(core->map, core->user, core->img, core);
	while (++i < core->map->len)
	{
		a = ((i % core->map->x) * core->map->px);
		b = ((i / core->map->x) * core->map->py);
		if (core->map->tab[i] == '2')
			anim_lights(core->img, a, b, core->game);
		if (core->map->tab[i] == 'C')
			anim_shiny(core->img, a, b, core->status);
		if (core->game > 1200)
			core->game = 1;
	}
}
