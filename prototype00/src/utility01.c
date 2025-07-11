/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:42:21 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/12 03:05:42 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	get_color(int iter, int max_iter)
// {
// 	double	t;
// 	int		r;
// 	int		g;
// 	int		b;

// 	t = (double)iter / max_iter;
// 	r = (int)(9 * (1 - t) * t * t * t * 255);
// 	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
// 	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
// 	return (r << 16 | g << 8 | b);
// }

int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = (int)(255 * t);
	g = (int)(100 * t);
	b = (int)(50 * (1 - t));
	return (r << 16 | g << 8 | b);
}

int	handle_esc(int keycode, t_fractol *f)
{
	if (keycode == ESC_KEY)
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
