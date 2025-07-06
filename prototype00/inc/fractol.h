/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:13:04 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/06 18:17:19 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// my library
# include "ft_printf.h"
# include "libft.h"

// minilibx
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

int			get_color(int iter, int max_iter);
int			close_window(t_fractol *f);
void		draw_mandelbrot(t_fractol *f, int max_iter);
void		draw_julia(t_fractol *f, int max_iter);
int			hsv_to_rgb(double h, double s, double v);
int			ft_strcmp(const char *s1, const char *s2);
int			mouse_hook(int button, int x, int y, int max_iter, t_fractol *f);

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

#endif