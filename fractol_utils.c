/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:03:23 by vzuccare          #+#    #+#             */
/*   Updated: 2024/02/26 15:21:49 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int trgb, double t)
{
	return (create_trgb(get_t(trgb), (int)(get_r(trgb) * t), \
		(int)(get_g(trgb) * t), (int)(get_b(trgb) * t)));
}

void	put_pixel(t_fract *f, int x, int y, int color)
{
	char	*dst;

	dst = f->mlx->addr + (y * f->mlx->size_line + x \
		* (f->mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	full_screen(t_fract *f)
{
	int			x;
	int			y;
	int			color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			color = mandelbrot(f, x, y);
			put_pixel(f, x, y, color);
		}
	}
}