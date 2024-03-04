/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:20:54 by vzuccare          #+#    #+#             */
/*   Updated: 2024/03/04 11:57:31 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_julia_keys(int keycode, t_fract *fract)
{
	if (keycode == 65451 && ft_strncmp(fract->name, "julia", 5) == 0)
	{
		fract->j->re += 0.1;
		fract->j->im += 0.1;
	}
	if (keycode == 65453 && ft_strncmp(fract->name, "julia", 5) == 0)
	{
		fract->j->re -= 0.1;
		fract->j->im -= 0.1;
	}
}

int	key_hook(int keycode, void *p)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(((t_fract *)p)->mlx->mlx, ((t_fract *)p)->mlx->img);
		free_fractol((t_fract *)p);
	}
	if (keycode == 32)
	{
		((t_fract *)p)->x = 0;
		((t_fract *)p)->y = 0;
		((t_fract *)p)->zoom = 1;
	}
	if (keycode == 65362 || keycode == 119)
		((t_fract *)p)->y -= 10 * ((t_fract *)p)->zoom;
	if (keycode == 65364 || keycode == 115)
		((t_fract *)p)->y += 10 * ((t_fract *)p)->zoom;
	if (keycode == 65361 || keycode == 97)
		((t_fract *)p)->x -= 10 *((t_fract *)p)->zoom;
	if (keycode == 65363 || keycode == 100)
		((t_fract *)p)->x += 10 * ((t_fract *)p)->zoom;
	handle_julia_keys(keycode, (t_fract *)p);
	mlx_destroy_image(((t_fract *)p)->mlx->mlx, ((t_fract *)p)->mlx->img);
	full_screen((t_fract *)p, -1, -1);
	mlx_put_image_to_window(((t_fract *)p)->mlx->mlx, \
		((t_fract *)p)->mlx->win, ((t_fract *)p)->mlx->img, 0, 0);
	return (0);
}

int	mouse_scroll(int scroll, int x, int y, void *p)
{
	(void)x;
	(void)y;
	if (scroll == 4)
		((t_fract *)p)->zoom *= 1.1;
	else if (scroll == 5)
		((t_fract *)p)->zoom /= 1.1;
	if (((t_fract *)p)->mlx->img)
		mlx_destroy_image(((t_fract *)p)->mlx->mlx, ((t_fract *)p)->mlx->img);
	full_screen((t_fract *)p, -1, -1);
	mlx_put_image_to_window(((t_fract *)p)->mlx->mlx, \
		((t_fract *)p)->mlx->win, ((t_fract *)p)->mlx->img, 0, 0);
	return (0);
}

void	hook_events(t_fract *f)
{
	mlx_mouse_hook(f->mlx->win, mouse_scroll, f);
	mlx_key_hook(f->mlx->win, key_hook, f);
	mlx_hook(f->mlx->win, 17, 0, mlx_loop_end, f->mlx->mlx);
}
