/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:03:23 by vzuccare          #+#    #+#             */
/*   Updated: 2024/02/26 21:31:27 by vincent          ###   ########.fr       */
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
	color = 0x00000000;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (ft_strncmp(f->name, "julia", 5) == 0)
				color = julia(f, x, y);
			else if (ft_strncmp(f->name, "mandelbrot", 5) == 0)
				color = mandelbrot(f, x, y);
			put_pixel(f, x, y, color);
		}
	}
}