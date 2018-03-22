/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:32:55 by bbardocz          #+#    #+#             */
/*   Updated: 2018/03/22 15:03:30 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	color_win(void *mlx_ptr, void *win_ptr)
{
	float minx = -2.4; float maxx = 2.4;
	float miny = -1.5; float maxy = 1.5;
	float rc; float ic;
	float rz; float iz;
	float r; float i;
	int y; int x;
	int a;
	int bpp; int size_line/*1280*/; int endian;
	void *img_ptr;
	char *img_data;

	img_ptr = mlx_new_image(mlx_ptr, 320, 200);
	img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	for (x = 0; x < 319; x++)
	{
		for (y = 0; y < 199; y++)
		{
			rc = minx + (maxx - minx) / 320 * x;
			ic = miny + (maxy - miny) / 200 * y;
			rz = 0;
			iz = 0;
			for (a = 0; a < 15; a++)
			{
				r = rz;
				i = iz;
				rz = r * r - i * i + rc;
				iz = 2 * r * i + ic;
				if (rz * rz + iz * iz >= 4)
					break ;
			}
			if (a != 15)
				img_data[x + 4 * 1280 * y] = (char)255;
//				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ffffff);
			if (a == 15)
				img_data[x + 4 * 1280 * y] = 0;
//				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00000000);
		}
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
}

void	mandelbrot(void *mlx_ptr)
{
	void	*win_ptr;
	win_ptr = mlx_new_window(mlx_ptr, 1300, 1300, "Mandelbrot");
	color_win(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
}
