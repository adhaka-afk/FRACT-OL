/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_and_zoom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:38:07 by adhaka            #+#    #+#             */
/*   Updated: 2023/09/23 17:34:35 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(double x_delta, double y_delta, void *param)
{
	t_data	*f;
	double	zoom;
	double	center_x;
	double	center_y;

	f = (t_data *)param;
	center_x = (f->x_min + f->x_max) / 2.0;
	center_y = (f->y_min + f->y_max) / 2.0;
	zoom = 0.07;
	x_delta = 0;
	if (y_delta > 0)
	{
		f->x_min = center_x - (center_x - f->x_min) * (1.0 + zoom);
		f->x_max = center_x + (f->x_max - center_x) * (1.0 + zoom);
		f->y_min = center_y - (center_y - f->y_min) * (1.0 + zoom);
		f->y_max = center_y + (f->y_max - center_y) * (1.0 + zoom);
	}
	if (y_delta < 0)
	{
		f->x_min = center_x - (center_x - f->x_min) / (1.0 + zoom);
		f->x_max = center_x + (f->x_max - center_x) / (1.0 + zoom);
		f->y_min = center_y - (center_y - f->y_min) / (1.0 + zoom);
		f->y_max = center_y + (f->y_max - center_y) / (1.0 + zoom);
	}
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*f;

	f = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (exit (0));
}
