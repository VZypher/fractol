/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:59:58 by vzuccare          #+#    #+#             */
/*   Updated: 2024/02/29 12:10:05 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fract *f, int x, int y)
{
	ssize_t	i;
	double	tmp;

	x += f->x;
	y += f->y;
	i = -1;
	f->z->re = 0;
	f->z->im = 0;
	f->c->re = (x - WIDTH / 2) / (0.3 * f->zoom * WIDTH);
	f->c->im = (y - HEIGHT / 2) / (0.3 * f->zoom * HEIGHT);
	while (++i < f->max_iter)
	{
		tmp = (f->z->re * f->z->re) - (f->z->im * \
			f->z->im) + f->c->re;
		f->z->im = 2 * f->z->re * f->z->im + f->c->im;
		f->z->re = tmp;
		if ((f->z->re * f->z->re) + (f->z->im * \
			f->z->im) > 4)
			return (get_color(0xFFFFFFFF, (double)i / f->max_iter * 2));
	}
	return (0x00000000);
}

int	burning_ship(t_fract *f, int x, int y)
{
	ssize_t	i;
	double	tmp;

	i = -1;
	x += f->x;
	y += f->y;
	f->z->re = 0;
	f->z->im = 0;
	f->c->re = (x - WIDTH / 2) / (0.3 * f->zoom * WIDTH);
	f->c->im = (y - HEIGHT / 2) / (0.3 * f->zoom * HEIGHT);
	while (++i < f->max_iter)
	{
		tmp = (f->z->re * f->z->re) - (f->z->im * \
			f->z->im) + f->c->re;
		f->z->im = 2 * fabs(f->z->re * f->z->im) + f->c->im;
		f->z->re = tmp;
		if ((f->z->re * f->z->re) + (f->z->im * \
			f->z->im) > 4)
			return (orange_color(i, f->max_iter));
	}
	return (0x00000000);
}
