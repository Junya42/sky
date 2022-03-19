/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 07:38:53 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/13 15:05:53 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_core	*freecore(t_core *core)
{
	free(core);
	return (NULL);
}

t_core	*firstfree(t_core *core)
{
	free(core->map);
	free(core);
	return (NULL);
}

t_core	*secondfree(t_core *core)
{
	free(core->map->tab);
	free(core->map);
	free(core);
	return (NULL);
}

t_core	*thirdfree(t_core *core)
{
	free(core->map->tab);
	free(core->map);
	free(core->user);
	free(core);
	return (NULL);
}
