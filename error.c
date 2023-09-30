/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:17:33 by adhaka            #+#    #+#             */
/*   Updated: 2023/09/23 11:17:58 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	wrong_arg(void)
{
	perror("ERROR : wrong arg input\n");
	exit (EXIT_FAILURE);
}

void	malloc_error(void)
{
	perror(" Error: Malloc faliure\n");
	exit (EXIT_FAILURE);
}

void	mlx_error1(void)
{
	perror("MiniLibX initialization error");
	exit (EXIT_FAILURE);
}

void	mlx_error2(mlx_t *mlx)
{
	perror("Error: Image creation error\n");
	mlx_close_window(mlx);
	exit (EXIT_FAILURE);
}

void	mlx_error3(mlx_t *mlx)
{
	perror("Error: Image display error\n");
	mlx_close_window(mlx);
	exit (EXIT_FAILURE);
}
