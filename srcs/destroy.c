/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:47:00 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/13 14:56:30 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_player(t_core *core)
{
	mlx_destroy_image(core->img->mlx, core->img->pback);
	mlx_destroy_image(core->img->mlx, core->img->pright);
	mlx_destroy_image(core->img->mlx, core->img->pleft);
	mlx_destroy_image(core->img->mlx, core->img->pfront);
	mlx_destroy_image(core->img->mlx, core->img->afk);
	mlx_destroy_image(core->img->mlx, core->img->eback);
	mlx_destroy_image(core->img->mlx, core->img->eright);
	mlx_destroy_image(core->img->mlx, core->img->eleft);
	mlx_destroy_image(core->img->mlx, core->img->efront);
	mlx_destroy_image(core->img->mlx, core->img->eafk);
}

void	destroy_map(t_core *core)
{
	mlx_destroy_image(core->img->mlx, core->img->floor);
	mlx_destroy_image(core->img->mlx, core->img->wall);
	mlx_destroy_image(core->img->mlx, core->img->roof);
	mlx_destroy_image(core->img->mlx, core->img->light);
	mlx_destroy_image(core->img->mlx, core->img->light1);
	mlx_destroy_image(core->img->mlx, core->img->light2);
}

void	destroy_core(t_core *core)
{
	free(core->user);
	free(core->map->tab);
	free(core->map);
	destroy_player(core);
	destroy_map(core);
	mlx_destroy_image(core->img->mlx, core->img->exit);
	mlx_destroy_image(core->img->mlx, core->img->shiny);
	mlx_destroy_image(core->img->mlx, core->img->shiny2);
	mlx_destroy_image(core->img->mlx, core->img->shiny3);
	mlx_destroy_image(core->img->mlx, core->img->shiny4);
}
