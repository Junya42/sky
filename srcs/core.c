/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:41:36 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/13 17:28:33 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	a = s;
	i = -1;
	while (++i < n)
		a[i] = c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

int	*check(int ac, char **av, t_map *map)
{
	int	fd;
	int	*tab;

	fd = 0;
	if (ac != 2)
		return (ft_error("Wrong number of arguments."));
	if (!ft_checkfile(av[1]))
		return (ft_error("Wrong type of file."));
	map->len = get_len(fd, av[1], map);
	map->size = get_size(fd, av[1]);
	if (!map->len || !map->size)
		return (ft_error("Invalid map"));
	tab = oned_map(fd, map->len, av[1]);
	if (!tab)
		return (0);
	fd = open(av[1], O_RDONLY);
	map->y = parse_ber(map, -1, 0, fd);
	if (map->y < 3)
	{
		free(tab);
		return (ft_error("Invalid map"));
	}
	map->end = 0;
	return (tab);
}

t_core	*create_core(int ac, char **av)
{
	t_core	*core;

	core = (t_core *)ft_calloc(sizeof(t_core), 1);
	if (!core)
		return (NULL);
	core->map = init_map();
	if (!core->map)
		return (freecore(core));
	core->map->tab = check(ac, av, core->map);
	if (!core->map->tab)
		return (firstfree(core));
	if (!check_object(core->map))
		return (secondfree(core));
	core->user = init_player(core->map, core->map->tab, core->map->x);
	if (!core->user)
		return (secondfree(core));
	core->img = put_game(core->map, core->user);
	if (!core->img)
		return (thirdfree(core));
	core->win = 0;
	core->anim = 1;
	core->status = 1;
	core->map->end = 0;
	return (core);
}
