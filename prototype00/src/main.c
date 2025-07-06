/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:13:02 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/06 18:25:41 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 7/3 コマンドライン引数を判定してerror Comment　を出力
int	invalid_input(const char *arg)
{
	if (ft_strcmp(arg, "mandelbrot"))
		return (0);
	if (ft_strcmp(arg, "julia"))
		return (0);
	return (1);
}

void	print_usage(void)
{
	ft_printf("plz args !\"mandelbrot\" or \"julia\" ");
}

//　7/3　色彩表現
int	get_color(int iter, int max_iter)
{
	if (iter == max_iter)
		return (0x000000);               // 黒
	return (0x00FF00 * iter / max_iter); // グラデーション
}

int	handle_esc(int keycode, t_fractol *f)
{
	if (keycode == 65307) // 65307 = ESCキー
	{
		mlx_destroy_image(f->mlx, f->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	return (0);
}

//　ｘボタンで終了させる　7/2
int	close_window(t_fractol *f)
{
	mlx_destroy_window(f->mlx, f->win);
	mlx_key_hook(f->win, handle_esc, f);
	exit(0);
}

int	main(int ac, const char **av)
{
	t_fractol f;
	int max_iter;

	if (ac < 2 || invalid_input(av[1]))
	{
		print_usage();
		return (1);
	}

	if (ac == 2)
		max_iter = MAX_ITER;
	else
		max_iter = ft_atoi(av[2]);

	f.type = (av[1][0] | 32);
	f.zoom = 200;
	f.offset_x = -2.0;
	f.offset_y = -2.0;

	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fractol");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_len, &f.endian);

	if (f.type == 'm')
		draw_mandelbrot(&f, max_iter);
	else if (f.type == 'j')
		draw_julia(&f, max_iter);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop(f.mlx);
	return (0);
}