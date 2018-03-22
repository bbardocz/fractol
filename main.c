/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:25:43 by bbardocz          #+#    #+#             */
/*   Updated: 2018/03/16 15:41:33 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	void	*mlx_ptr;

	if (argc != 2 || strncmp(argv[1] ,"Mandelbrot", 10) != 0)
	{
		ft_putendl("./fractol Mandelbrot");
		return (0);
	}
	mlx_ptr = mlx_init();
	if (strncmp(argv[1], "Mandelbrot", 10) == 0)
		mandelbrot(mlx_ptr);
	return (0);
}
