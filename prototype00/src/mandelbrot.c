/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:12:49 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/02 14:48:19 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter)
{
	if (iter == MAX_ITER)
		return (0xFFFFFF);               // 黒
	return (0xFFFFFF * iter / MAX_ITER); // グラデーション
}

void	draw_mandelbrot(t_fractol *f)
{
	double	tmp;

	int x, y, i;
	t_complex c, z;
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			c.re = x / f->zoom + f->offset_x;
			c.im = y / f->zoom + f->offset_y;
			z.re = 0;
			z.im = 0;
			i = 0;
			while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
			{
				tmp = z.re * z.re - z.im * z.im + c.re;
				z.im = 2 * z.re * z.im + c.im;
				z.re = tmp;
				i++;
			}
			*(int *)(f->addr + (y * f->line_len + x * (f->bpp
							/ 8))) = get_color(i);
		}
	}
}
