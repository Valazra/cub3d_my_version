/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:35:42 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:35:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init3_more(t_data *data)
{
	if (data->ray.raydiry == 0)
		data->ray.deltadistx = 0;
	else if (data->ray.raydirx == 0)
		data->ray.deltadistx = 1;
	else
		data->ray.deltadistx = sqrt(1 + (data->ray.raydiry \
				* data->ray.raydiry) / (data->ray.raydirx \
				* data->ray.raydirx));
	if (data->ray.raydirx == 0)
		data->ray.deltadisty = 0;
	else if (data->ray.raydiry == 0)
		data->ray.deltadisty = 1;
	else
		data->ray.deltadisty = sqrt(1 + (data->ray.raydirx \
			* data->ray.raydirx) / (data->ray.raydiry * data->ray.raydiry));
}

void	ft_initialisation3(t_data *data)
{
	data->ray.hit = 0;
	data->ray.perpwalldist = 0;
	data->ray.camerax = 2 * data->ray.x / (double)data->rx - 1;
	data->ray.raydirx = data->ray.dirx + data->ray.planx \
		* data->ray.camerax;
	data->ray.raydiry = data->ray.diry + data->ray.plany \
		* data->ray.camerax;
	data->ray.mapx = (int)data->ray.posx;
	data->ray.mapy = (int)data->ray.posy;
	data->ray.movespeed = 0.1;
	data->ray.rotspeed = 0.033 * 1.8;
	ft_init3_more(data);
}

