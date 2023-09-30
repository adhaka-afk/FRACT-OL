/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:08:16 by adhaka            #+#    #+#             */
/*   Updated: 2023/09/23 19:16:55 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(void *param)
{
	uint32_t	y;
	uint32_t	x;
	t_data		*f;

	f = (t_data *)param;
	y = 0;
	while (++y < f->image->height)
	{
		x = 0;
		while (++x < f->image->width)
		{
			mandelfork(x, y, f);
			while (f->iter < MAX_ITER)
			{
				if (f->z_r * f->z_r + f->z_i * f->z_i <= 4.0)
					u_val(f);
				else
					break ;
			}
			f->color = ft_pixel(f->iter % 130, f->iter % 230, \
						f->iter % 123, 255);
			mlx_put_pixel(f->image, x, y, f->color);
		}
	}
}

void	u_val(t_data *f)
{
	double	z_r_sq;
	double	z_i_sq;

	z_r_sq = f->z_r * f->z_r;
	z_i_sq = f->z_i * f->z_i;
	f->z_i = 2.0 * f->z_r * f->z_i + f->n_i;
	f->z_r = z_r_sq - z_i_sq + f->n_r;
	f->iter++;
}

void	mandelfork(int x, int y, t_data *f)
{
	double	x_factor;
	double	y_factor;

	x_factor = (f->x_max - f->x_min) / f->image->width;
	y_factor = (f->y_max - f->y_min) / f->image->height;
	f->r = f->x_min + x * x_factor;
	f->i = f->y_min + y * y_factor;
	f->n_r = f->r;
	f->n_i = f->i;
	f->iter = 0;
	f->z_r = 0.0;
	f->z_i = 0.0;
}
