/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:13:04 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/02 14:19:26 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	double	offset_x;
	double	offset_y;
	char	type;
}			t_fractol;

int			get_color(int iter);
int			close_window(t_fractol *f);
void		draw_mandelbrot(t_fractol *f);
void		draw_julia(t_fractol *f);
int			hsv_to_rgb(double h, double s, double v);

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

#endif