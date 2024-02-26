/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:03:17 by vzuccare          #+#    #+#             */
/*   Updated: 2024/02/26 15:24:37 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux-master/mlx.h"
# include <libft.h>
# include <ft_printf.h>
# include <math.h>
# include <fcntl.h>	
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_color
{
	uint32_t			color;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}	t_color;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mlx;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_frac
{
	char		*name;
	int			x;
	int			y;
	int			color;
	int			max_iter;
	double		zoom;
	t_complex	*c;
	t_complex	*z;
	t_mlx		*mlx;
	t_color		*colors;
}	t_fract;

void	put_pixel(t_fract *f, int x, int y, int color);
void	full_screen(t_fract *f);
void	init_fractol(t_fract *f);
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		get_color(int trgb, double t);
void	ft_parse_args(int ac, char **av, t_fract *f);
int		mandelbrot(t_fract *f, int x, int y);
void	hook_events(t_fract *f);
void	free_fractol(t_fract *f);
#endif
