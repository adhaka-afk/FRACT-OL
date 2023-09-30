/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:08:09 by adhaka            #+#    #+#             */
/*   Updated: 2023/09/23 18:46:14 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <errno.h>

# define MAX_ITER 705
# define W_WIDTH 1200
# define W_HEIGHT 1000

typedef struct s_data
{
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		r;
	double		i;
	double		n_r;
	double		n_i;
	double		z_r;
	double		z_i;
	int			iter;
	uint32_t	color;
	mlx_image_t	*image;
	mlx_t		*mlx;

}	t_data;

// main func.
void			zoom(double x_delta, double y_delta, void *param);
void			ft_hook(mlx_key_data_t keydata, void *param);
void			mlx_func(t_data *f, mlx_t *mlx);
void			j_or_m(int argc, char **argv, mlx_t *mlx, t_data *f);

// julia func.
void			julia(void *param);
int				julian(float r, float i, float nr, float ni);
// mandelbrot func.
void			mandelbrot(void *param);
void			u_val(t_data *f);
void			mandelfork(int x, int y, t_data *f);
// error func.
void			mlx_error3(mlx_t *mlx);
void			mlx_error2(mlx_t *mlx);
void			mlx_error1(void);
void			malloc_error(void);
void			wrong_arg(void);
// util func.
int				ft_strcmp(char *s1, char *s2);
int32_t			ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
double			ft_atof(const char *str);

#endif
