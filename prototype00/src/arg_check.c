/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 05:45:59 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/12 01:19:44 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	is_valid_double(const char *arg)
{
	int	dot_count;

	dot_count = 0;
	if (!arg || !*arg)
		return (false);
	if (*arg == '-' || *arg == '+')
		arg++;
	if (!*arg)
		return (false);
	while (*arg)
	{
		if (*arg == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (false);
		}
		else if (!ft_isdigit(*arg))
			return (false);
		arg++;
	}
	return (true);
}

bool	invalid_input(int ac, const char **av)
{
	if (ac == 2 && (ft_strcmp(av[1], "mandelbrot") == 0))
		return (true);
	if ((ac == 2 || ac == 4) && (ft_strcmp(av[1], "julia") == 0))
	{
		if (ac == 2)
			return (true);
		if (is_valid_double(av[2]) && is_valid_double(av[3]))
			return (true);
	}
	return (false);
}

void	print_usage(void)
{
	ft_printf("erorr : plz args !\n");
	ft_printf("mandelbrot -> \"mandelbrot\"\n");
	ft_printf("julia      -> \"julia\" <real> <imginary>");
}

void	arg_check(t_fractol *f, t_complex *c, const char **av)
{
	if (f->type == 'm')
		draw_mandelbrot(f);
	else if (f->type == 'j')
	{
		if (!av[2] || !av[3])
		{
			c->re = INTI_JULIA;
			c->im = INTI_JULIA;
		}
		else
		{
			c->re = ft_atof(av[2]);
			c->im = ft_atof(av[3]);
		}
		f->c = *c;
		draw_julia(f, c);
	}
}
