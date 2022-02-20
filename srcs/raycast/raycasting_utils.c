/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:27:00 by user42            #+#    #+#             */
/*   Updated: 2021/06/17 11:23:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_drawstartend(t_recup *recup)
{
	if (recup->ray.side == 0)
		recup->ray.perpwalldist = ((double)recup->ray.mapx - recup->ray.posx \
			+ (1 - (double)recup->ray.stepx) / 2) / recup->ray.raydirx;
	else
		recup->ray.perpwalldist = ((double)recup->ray.mapy - recup->ray.posy \
			+ (1 - (double)recup->ray.stepy) / 2) / recup->ray.raydiry;
	recup->ray.lineheight = (int)(recup->ry / recup->ray.perpwalldist);
	recup->ray.drawstart = -recup->ray.lineheight / 2 + recup->ry / 2;
	if (recup->ray.drawstart < 0)
		recup->ray.drawstart = 0;
	recup->ray.drawend = recup->ray.lineheight / 2 + recup->ry / 2;
	if (recup->ray.drawend >= recup->ry || recup->ray.drawend < 0)
		recup->ray.drawend = recup->ry - 1;
}

void	ft_incrementray(t_recup *recup)
{
	while (recup->ray.hit == 0)
	{
		if (recup->ray.sidedistx < recup->ray.sidedisty)
		{
			recup->ray.sidedistx += recup->ray.deltadistx;
			recup->ray.mapx += recup->ray.stepx;
			recup->ray.side = 0;
		}
		else
		{
			recup->ray.sidedisty += recup->ray.deltadisty;
			recup->ray.mapy += recup->ray.stepy;
			recup->ray.side = 1;
		}
		if (recup->map[recup->ray.mapx][recup->ray.mapy] == '1')
			recup->ray.hit = 1;
	}
	ft_drawstartend(recup);
}

void	ft_stepsidedist(t_recup *recup)
{
	if (recup->ray.raydirx < 0)
	{
		recup->ray.stepx = -1;
		recup->ray.sidedistx = (recup->ray.posx - recup->ray.mapx) \
							* recup->ray.deltadistx;
	}
	else
	{
		recup->ray.stepx = 1;
		recup->ray.sidedistx = (recup->ray.mapx + 1.0 - recup->ray.posx) \
							* recup->ray.deltadistx;
	}
	if (recup->ray.raydiry < 0)
	{
		recup->ray.stepy = -1;
		recup->ray.sidedisty = (recup->ray.posy - recup->ray.mapy) \
							* recup->ray.deltadisty;
	}
	else
	{
		recup->ray.stepy = 1;
		recup->ray.sidedisty = (recup->ray.mapy + 1.0 - recup->ray.posy) \
							* recup->ray.deltadisty;
	}
	ft_incrementray(recup);
}
