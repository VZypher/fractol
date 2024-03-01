/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:45:19 by vzuccare          #+#    #+#             */
/*   Updated: 2024/02/29 13:02:59 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(char *str)
{
	double	nb;
	double	dec;
	int		signe;
	ssize_t	i;

	i = -1;
	signe = 1;
	nb = 0;
	dec = 1;
	if (str[0] == '-')
	{
		signe = -1;
		i++;
	}
	while (str[++i] && str[i] != '.')
		nb = nb * 10 + str[i] - '0';
	if (str[i] == '.')
	{
		while (str[++i])
		{
			nb = nb * 10 + str[i] - '0';
			dec *= 10;
		}
	}
	return (nb / dec * signe);
}

void	init_julia(t_fract *f, int ac, char **av)
{
	if (ac != 4)
	{
		ft_printf(2, "ERROR Usage: ./f julia [re] [im]\n");
		exit(0);
	}
	f->name = "julia";
	f->j = malloc(sizeof(t_complex));
	if (!f->j)
	{
		ft_printf(2, "ERROR: malloc failed\n");
		exit (0);
	}
	f->j->re = 0;
	f->j->im = 0;
	if (ft_strncmp(f->name, "julia", 5) == 0)
	{
		if (av[2])
			f->j->re = ft_atod(av[2]);
		if (av[3])
			f->j->im = ft_atod(av[3]);
	}
}

int	julia(t_fract *f, int x, int y)
{
	ssize_t	i;
	double	tmp;

	i = -1;
	x += f->x;
	y += f->y;
	f->z->re = (x - WIDTH / 2) / (0.3 * f->zoom * WIDTH);
	f->z->im = (y - HEIGHT / 2) / (0.3 * f->zoom * HEIGHT);
	while (++i < f->max_iter)
	{
		tmp = (f->z->re * f->z->re) - (f->z->im * f->z->im) + f->j->re;
		f->z->im = 2 * f->z->re * f->z->im + f->j->im;
		f->z->re = tmp;
		if ((f->z->re * f->z->re) + (f->z->im * f->z->im) > 4)
			return (get_color(0xFFFFFFFF, (double)i / f->max_iter * 1.2));
	}
	return (0x00000000);
}
