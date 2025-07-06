/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 05:45:59 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/07 06:13:13 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 7/3 コマンドライン引数を判定してerror Comment　を出力
int	invalid_input(const char *arg)
{
	if (ft_strcmp(arg, "m"))
		return (1);
	if (ft_strcmp(arg, "j"))
		return (1);
	return (0);
}

void	print_usage(void)
{
	ft_printf("plz args !\n");
	ft_printf("mandelbrot -> \"m\"\n");
	ft_printf("julia      -> \"j\" <real> <imginary>");
}

void	arg_check(t_fractol *f, t_complex *c, const char **av)
{
	if (f->type == 'm')
		draw_mandelbrot(f);
	else if (f->type == 'j')
	{
		c->re = ft_atof(av[2]);
		c->im = ft_atof(av[3]);
		f->c = *c;
		draw_julia(f, c);
	}
}