/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:59:58 by vzuccare          #+#    #+#             */
/*   Updated: 2024/02/26 21:20:12 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia(t_fract *f, int x, int y)
{
    ssize_t i;
    double tmp;

    i = -1;
	f->c->re = 0.285 * f->zoom;
	f->c->im = 0.01 * f->zoom;
    f->z->re = (x - WIDTH / 2) / (0.3 * f->zoom * WIDTH);
    f->z->im = (y - HEIGHT / 2) / (0.3 * f->zoom * HEIGHT);
    while (++i < f->max_iter)
    {
        tmp = (f->z->re * f->z->re) - (f->z->im * f->z->im) + f->c->re;
        f->z->im = 2 * f->z->re * f->z->im + f->c->im;
        f->z->re = tmp;
        if ((f->z->re * f->z->re) + (f->z->im * f->z->im) > 4)
            return get_color(0xFFFFFFFF, (double)i / f->max_iter * 2);
    }
    return 0x00000000;
}

int	mandelbrot(t_fract *f, int x, int y)
{
	ssize_t	i;
	double	tmp;

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

