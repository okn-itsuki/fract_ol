/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:13:04 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/01 12:58:19 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_complex
{
    double re;
    double im;
}   t_complex;

typedef struct s_fractol
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    double  zoom;
    double  offset_x;
    double  offset_y;
}   t_fractol;

int     ft_atoi(const char *str);
void    draw_mandelbrot(t_fractol *f);

# define WIDTH     800
# define HEIGHT    800
# define MAX_ITER  100

#endif