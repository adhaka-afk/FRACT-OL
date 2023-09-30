/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:08:06 by adhaka            #+#    #+#             */
/*   Updated: 2023/09/23 19:55:58 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(int32_t argc, char **argv)
{
	t_data	*f;
	mlx_t	*mlx;

	if (argc < 2)
		wrong_arg();
	if (argc > 1)
	{
		mlx = mlx_init(W_WIDTH, W_HEIGHT, "fractol", true);
		if (!(mlx))
			mlx_error1();
		f = (t_data *)malloc(sizeof(t_data));
		if (!f)
			malloc_error();
		f->image = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
		if (!f->image)
			mlx_error2(mlx);
		if (mlx_image_to_window(mlx, f->image, 0, 0) == -1)
			mlx_error3(mlx);
		mlx_scroll_hook(mlx, zoom, f);
		j_or_m(argc, argv, mlx, f);
		free(f);
		return (EXIT_SUCCESS);
	}
}

void	j_or_m(int argc, char **argv, mlx_t *mlx, t_data *f)
{
	if (ft_strcmp(argv[1], "m") && argc == 2)
	{
		f->x_min = -2.0;
		f->x_max = 0.5;
		f->y_min = -1.0;
		f->y_max = 1.0;
		mlx_loop_hook(mlx, mandelbrot, f);
	}
	else if (ft_strcmp(argv[1], "j") && argc == 4)
	{
		f->x_min = -1.0;
		f->x_max = 1.0;
		f->y_min = -1.0;
		f->y_max = 1.0;
		f->n_r = ft_atof(argv[2]);
		f->n_i = ft_atof(argv[3]);
		mlx_loop_hook(mlx, julia, f);
	}
	else
	{
		perror("ERROR: INVALID fractol data, \n \
				try 'j' '-0.1231' '-0.12341' or 'm'\n");
		exit(EXIT_FAILURE);
	}
	mlx_func(f, mlx);
}

void	mlx_func(t_data *f, mlx_t *mlx)
{
	mlx_key_hook(mlx, ft_hook, f);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
