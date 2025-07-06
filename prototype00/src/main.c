/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:13:02 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/07 06:10:31 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//　7/3　色彩表現
int	get_color(int iter, int max_iter)
{
	if (iter == max_iter)
		return (0x000000);
	return (0x666666 * iter / max_iter); // グラデーション
}

int	handle_esc(int keycode, t_fractol *f)
{
	if (keycode == 65307) // 65307 = ESC key
	{
		mlx_destroy_image(f->mlx, f->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	return (0);
}

int	close_window(t_fractol *f)
{
	mlx_destroy_window(f->mlx, f->win);
	mlx_key_hook(f->win, handle_esc, f);
	exit(0);
}

int	main(int ac, const char **av)
{
	t_fractol f;
	t_complex c;

	if (ac < 2 || invalid_input(av[1]))
	{
		print_usage();
		return (1);
	}

	f.type = (av[1][0] | 32);
	f.zoom = 200;
	f.offset_x = -2.0;
	f.offset_y = -2.0;

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
	return (0);
}