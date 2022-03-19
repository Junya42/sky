/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 07:06:35 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/13 17:52:10 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	exit_hook(t_core *core)
{
	core->map->end = 1;
	core->anim = 0;
	return (0);
}

int	end(t_core *core)
{
	if (core->map->end == 1)
	{
		core->status = 0;
		core->anim = 0;
		mlx_destroy_window(core->img->mlx, core->img->win);
	}
	if (core->anim == 1 && core->map->end == 0 && B)
		game(core);
	return (0);
}

int	main(int ac, char **av)
{
	t_core	*core;

	core = create_core(ac, av);
	if (!core)
		return (0);
	mlx_loop_hook(core->img->mlx, &end, core);
	mlx_hook(core->img->win, KeyPress, KeyPressMask, key_handle, core);
	mlx_hook(core->img->win, 17, (1L << 17), &exit_hook, core);
	mlx_loop(core->img->mlx);
	destroy_core(core);
	mlx_destroy_display(core->img->mlx);
	free(core->img->mlx);
	free(core->img);
	free(core);
	return (0);
}
