/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:17:34 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/13 17:42:41 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_previous(t_map *m, int pos)
{
	if (m->tab[pos] != '1' && m->tab[pos] != 'E' && m->tab[pos] != 'C')
		return (1);
	return (0);
}

void	get_eimgs(t_img *img, int a, int b)
{
	img->eafk = mlx_xpm_file_to_image(img->mlx, "img/esleepy.xpm", &a, &b);
	img->eleft = mlx_xpm_file_to_image(img->mlx, "img/eleftpuff.xpm", &a, &b);
	img->eright = mlx_xpm_file_to_image(img->mlx, "img/erightpuff.xpm", &a, &b);
	img->eback = mlx_xpm_file_to_image(img->mlx, "img/ebackright.xpm", &a, &b);
	img->efront = mlx_xpm_file_to_image(img->mlx, "img/erightpuff.xpm", &a, &b);
}

void	get_items(t_img *img, int a, int b)
{
	img->afk = mlx_xpm_file_to_image(img->mlx, "img/sleepy.xpm", &a, &b);
	img->pleft = mlx_xpm_file_to_image(img->mlx, "img/leftpuff.xpm", &a, &b);
	img->pright = mlx_xpm_file_to_image(img->mlx, "img/rightpuff.xpm", &a, &b);
	img->pback = mlx_xpm_file_to_image(img->mlx, "img/rbjiggly.xpm", &a, &b);
	img->pfront = mlx_xpm_file_to_image(img->mlx, "img/rfjiggly.xpm", &a, &b);
	img->wall = mlx_xpm_file_to_image(img->mlx, "img/wall.xpm", &a, &b);
	img->light = mlx_xpm_file_to_image(img->mlx, "img/torch1.xpm", &a, &b);
	img->light1 = mlx_xpm_file_to_image(img->mlx, "img/torch2.xpm", &a, &b);
	img->light2 = mlx_xpm_file_to_image(img->mlx, "img/torch3.xpm", &a, &b);
	img->shiny = mlx_xpm_file_to_image(img->mlx, "img/minerala.xpm", &a, &b);
	img->shiny2 = mlx_xpm_file_to_image(img->mlx, "img/mineralb.xpm", &a, &b);
	img->shiny3 = mlx_xpm_file_to_image(img->mlx, "img/mineralc.xpm", &a, &b);
	img->shiny4 = mlx_xpm_file_to_image(img->mlx, "img/minerald.xpm", &a, &b);
	img->roof = mlx_xpm_file_to_image(img->mlx, "img/roof.xpm", &a, &b);
	img->floor = mlx_xpm_file_to_image(img->mlx, "img/floor2.xpm", &a, &b);
	img->exit = mlx_xpm_file_to_image(img->mlx, "img/stairs2.xpm", &a, &b);
}

int	get_imgs(t_img *img, t_map *map)
{
	int	xpos;
	int	ypos;

	xpos = map->x * map->px;
	ypos = map->y * map->py;
	img->mlx = mlx_init();
	if (!img->mlx)
		return (0);
	img->win = mlx_new_window(img->mlx, xpos, ypos, "So_long");
	if (!img->win)
	{
		mlx_destroy_display(img->mlx);
		return (0);
	}
	get_items(img, 0, 0);
	get_eimgs(img, 0, 0);
	return (1);
}

void	*ft_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
	return (NULL);
}
