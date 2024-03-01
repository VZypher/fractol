/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:03:21 by vzuccare          #+#    #+#             */
/*   Updated: 2024/02/26 15:15:03 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	free_init(t_fract *f)
{
	if (f->j)
		free(f->j);
	if (f->colors)
		free(f->colors);
	if (f->mlx)
		free(f->mlx);
	return (-1);
}

int	init_fractol(t_fract *f)
{
	f->x = 0;
	f->y = 0;
	f->max_iter = 30;
	f->zoom = 1;
	f->c = NULL;
	f->z = NULL;
	f->colors = (t_color *)malloc(sizeof(t_color) * 256);
	if (!f->colors)
		return (free_init(f));
	f->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!f->mlx)
		return (free_init(f));
	f->mlx->mlx = mlx_init();
	if (!f->mlx->mlx)
		return (free_init(f));
	f->mlx->win = mlx_new_window(f->mlx->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->mlx->win)
		return (free_fractol(f));
	f->c = (t_complex *)malloc(sizeof(t_complex));
	f->z = (t_complex *)malloc(sizeof(t_complex));
	if (!f->c || !f->z)
		return (free_fractol(f));
	return (0);
}

int	free_fractol(t_fract *f)
{
	if (f->colors)
		free(f->colors);
	if (f->mlx->win && f->mlx->mlx)
		mlx_destroy_window(f->mlx->mlx, f->mlx->win);
	if (f->mlx->mlx)
	{
		mlx_destroy_display(f->mlx->mlx);
		free(f->mlx->mlx);
		free(f->mlx);
	}
	if (f->c)
		free(f->c);
	if (f->z)
		free(f->z);
	if (f->j)
		free(f->j);
	exit (0);
}

void	ft_parse_args(int ac, char **av, t_fract *f)
{
	f->j = NULL;
	ft_tolower_str(av[1]);
	if (ac != 2 && !(ft_strncmp(av[1], "julia", 5) == 0 || \
		(av[1][0] == '2' && ft_strlen(av[1]) == 1)))
	{
		ft_printf(2, "ERROR Usage: ./f [fractal] \
			(mandelbrot, julia, burningship or 1, 2, 3)\n");
		exit(0);
	}
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0 || \
		(av[1][0] == '1' && ft_strlen(av[1]) == 1))
		f->name = "mandelbrot";
	else if (ft_strncmp(av[1], "julia", 5) == 0 || \
		(av[1][0] == '2' && ft_strlen(av[1]) == 1))
		init_julia(f, ac, av);
	else if (ft_strncmp(av[1], "burningship", 10) == 0 || \
		(av[1][0] == '3' && ft_strlen(av[1]) == 1))
		f->name = "burningship";
	else
	{
		ft_printf(2, "ERROR Usage: ./f [fractal] \
			(mandelbrot, julia, burningship or 1, 2, 3)\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_fract	f;

	if (ac < 2)
	{
		ft_printf(2, "ERROR Usage: ./f [fractal] \
			(mandelbrot, julia, burningship or 1, 2, 3)\n");
		return (-1);
	}
	ft_parse_args(ac, av, &f);
	if (!f.name)
		return (-1);
	if (init_fractol(&f) == -1)
		return (-1);
	full_screen(&f, -1, -1);
	if (mlx_put_image_to_window(f.mlx->mlx, f.mlx->win, \
		f.mlx->img, 0, 0) == -1)
	{
		mlx_destroy_image(f.mlx->mlx, f.mlx->img);
		free_fractol(&f);
	}
	hook_events(&f);
	mlx_loop(f.mlx->mlx);
	mlx_destroy_image(f.mlx->mlx, f.mlx->img);
	free_fractol(&f);
	return (0);
}
