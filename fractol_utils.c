/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:03:23 by vzuccare          #+#    #+#             */
/*   Updated: 2024/02/29 12:08:07 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	orange_color(double i, double max_iter)
{
	int	red;
	int	green;

	red = (int)(180 + 75 * sin(3.14 * i / max_iter));
	green = (int)(64 + 63 * sin(3.14 * i / max_iter));
	return (create_trgb(0, red, green, 0));
}

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

void	full_screen(t_fract *f, int x, int y)
{
	f->mlx->img = mlx_new_image(f->mlx->mlx, WIDTH, HEIGHT);
	if (!f->mlx->img)
		free_fractol(f);
	f->mlx->addr = mlx_get_data_addr(f->mlx->img, &f->mlx->bits_per_pixel, \
		&f->mlx->size_line, &f->mlx->endian);
	if (!f->mlx->addr)
	{
		mlx_destroy_image(f->mlx->mlx, f->mlx->img);
		free_fractol(f);
	}
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (ft_strncmp(f->name, "julia", 5) == 0)
				put_pixel(f, x, y, julia(f, x, y));
			else if (ft_strncmp(f->name, "mandelbrot", 5) == 0)
				put_pixel(f, x, y, mandelbrot(f, x, y));
			else if (ft_strncmp(f->name, "burning_ship", 5) == 0)
				put_pixel(f, x, y, burning_ship(f, x, y));
		}
	}
}
