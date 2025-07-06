/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:53:27 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/06 17:15:05 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractol *f, int max_iter)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			x;
	int			y;
	int			i;

	//パラメータ
	c.re = 0.35;
	c.im = 0.35;
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			z.re = x / f->zoom + f->offset_x;
			z.im = y / f->zoom + f->offset_y;
			i = 0;
			while (z.re * z.re + z.im * z.im <= 4 && i < max_iter)
			{
				tmp = z.re * z.re - z.im * z.im + c.re;
				z.im = 2 * z.re * z.im + c.im;
				z.re = tmp;
				i++;
			}
			*(int *)(f->addr + (y * f->line_len + x * (f->bpp
							/ 8))) = get_color(i, max_iter);
		}
	}
}
