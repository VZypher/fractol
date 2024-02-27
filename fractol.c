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

void	init_fractol(t_fract *f)
{
	f->x = 0;
	f->y = 0;
	f->max_iter = 30;
	f->zoom = 1;
	f->colors = (t_color *)malloc(sizeof(t_color) * 256);
	f->colors->color = 0x00000000;
	f->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!f->mlx)
		exit(0);
	f->mlx->mlx = mlx_init();
	if (!f->mlx->mlx)
		exit(0);
	f->mlx->win = mlx_new_window(f->mlx->mlx, \
		HEIGHT, WIDTH, f->name);
	if (!f->mlx->win)
		exit(0);
	f->c = (t_complex *)malloc(sizeof(t_complex));
	f->z = (t_complex *)malloc(sizeof(t_complex));
}

void	free_fractol(t_fract *f)
{
	if (f->colors)
		free(f->colors);
	if (f->mlx->img)
		mlx_destroy_image(f->mlx->mlx, f->mlx->img);
	if (f->mlx->win)
	{
		mlx_clear_window(f->mlx->mlx, f->mlx->win);
		mlx_destroy_window(f->mlx->mlx, f->mlx->win);
	}
	if (f->mlx->mlx)
		mlx_destroy_display(f->mlx->mlx);
	if (f->mlx->mlx)
		free(f->mlx->mlx);
	if (f->mlx)
		free(f->mlx);
	if (f->c)
		free(f->c);
	if (f->z)
		free(f->z);
	exit (0);
}

void	ft_parse_args(int ac, char **av, t_fract *f)
{
	if (ac != 2)
	{
		ft_printf(1, "ERROR Usage: ./f [fractal] \
			(mandelbrot, julia, burningship or 1, 2, 3)\n");
		exit(0);
	}
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0 || \
		(av[1][0] == '1' && ft_strlen(av[1]) == 1))
		f->name = "mandelbrot";
	else if (ft_strncmp(av[1], "julia", 5) == 0 || \
		(av[1][0] == '2' && ft_strlen(av[1]) == 1))
		f->name = "julia";
	else if (ft_strncmp(av[1], "burningship", 10) == 0 || \
		(av[1][0] == '3' && ft_strlen(av[1]) == 1))
		f->name = "burningship";
	else
	{
		ft_printf(1, "ERROR Usage: ./f [fractal] \
			(mandelbrot, julia, burningship or 1, 2, 3)\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_fract	f;

	ft_parse_args(ac, av, &f);
	if (!f.name)
		return (0);
	init_fractol(&f);
	if (!f.colors || !f.mlx || !f.c || !f.z)
		free_fractol(&f);
	ft_printf(1, "Fractol: %s\n", f.name);
	full_screen(&f);
	if (mlx_put_image_to_window(f.mlx->mlx, f.mlx->win, \
		f.mlx->img, 0, 0) == -1)
		free_fractol(&f);
	hook_events(&f);
	mlx_loop(f.mlx->mlx);
	free_fractol(&f);
	return (0);
}
