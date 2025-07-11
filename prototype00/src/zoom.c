/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:57:28 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/10 21:12:51 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractol *f, int x, int y, double factor)
{
	double	cx;
	double	cy;

	cx = (double)x / f->zoom + f->offset_x;
	cy = (double)y / f->zoom + f->offset_y;
	f->zoom *= factor;
	f->offset_x = cx - (double)x / f->zoom;
	f->offset_y = cy - (double)y / f->zoom;
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == 4)
		zoom(f, x, y, 1.1);
	else if (button == 5)
		zoom(f, x, y, 0.9);
	else
		return (0);
	if (f->type == 'm')
		draw_mandelbrot(f);
	else if (f->type == 'j')
		draw_julia(f, &(f->c));
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
