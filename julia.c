/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:08:58 by adhaka            #+#    #+#             */
/*   Updated: 2023/09/23 18:54:14 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(void *param)
{
	t_data		*f;
	uint32_t	x;
	uint32_t	y;
	double		pixel_x;
	double		pixel_y;

	f = (t_data *)param;
	y = 0;
	while (++y < f->image->height)
	{
		x = 0;
		while (++x < f->image->width)
		{
			pixel_x = f->x_min + (double)x \
						/ f->image->width * (f->x_max - f->x_min);
			pixel_y = f->y_min + (double)y \
						/ f->image->height * (f->y_max - f->y_min);
			f->iter = julian(pixel_x, pixel_y, f->n_r, f->n_i);
			f->color = ft_pixel(f->iter % 255, f->iter % 121,
					f->iter % 123, 255);
			mlx_put_pixel(f->image, x, y, f->color);
		}
	}
}

int	julian(float r, float i, float nr, float ni)
{
	double	z_r;
	double	z_i;
	double	z_r_sq;
	double	z_i_sq;
	int		iter;

	iter = 0;
	z_r = (double) r;
	z_i = (double) i;
	while (iter < MAX_ITER)
	{
		z_r_sq = z_r * z_r;
		z_i_sq = z_i * z_i;
		if ((z_r_sq + z_i_sq) > 4.0)
			break ;
		z_i = 2 * z_r * z_i + ni;
		z_r = z_r_sq - z_i_sq + nr;
		iter++;
	}
	return (iter);
}
