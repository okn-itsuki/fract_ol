/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:13:02 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/01 12:56:54 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2 || (argv[1][0] != 'm' && argv[1][0] != 'M'))
	{
		write(1, "Usage: ./fractol mandelbrot\n", 29);
		return (1);
	}
	f.zoom = 200;
	f.offset_x = -2.0;
	f.offset_y = -2.0;
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Mandelbrot");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_len, &f.endian);
	draw_mandelbrot(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_hook(f.win, 17, 0, close_window, &f); // ×で終了
	mlx_loop(f.mlx);
	return (0);
}
