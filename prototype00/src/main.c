/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:13:02 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/12 02:42:00 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol(const char **av)
{
	t_fractol	f;
	t_complex	c;

	f.type = (av[1][0] | 0b00100000);
	f.zoom = ZOOM;
	f.offset_x = -((double)WIDTH / 2.0) / f.zoom;
	f.offset_y = -((double)HEIGHT / 2.0) / f.zoom;
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "iokuno");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_len, &f.endian);
	arg_check(&f, &c, av);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_key_hook(f.win, handle_esc, &f);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop(f.mlx);
}

int	main(int ac, const char **av)
{
	if (!invalid_input(ac, av))
	{
		print_usage();
		return (1);
	}
	fractol(av);
	return (0);
}
