/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:20:54 by vzuccare          #+#    #+#             */
/*   Updated: 2024/02/27 17:28:28 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, void *param)
{
	if (keycode == 65307)
		free_fractol((t_fract *)param);
	if (keycode == 32)
	{
		((t_fract *)param)->x = 0;
		((t_fract *)param)->y = 0;
		((t_fract *)param)->zoom = 1;
	}
	if (keycode == 65362 || keycode == 119)
		((t_fract *)param)->y -= 170 / ((t_fract *)param)->zoom;
	if (keycode == 65364 || keycode == 115)
		((t_fract *)param)->y += 170 / ((t_fract *)param)->zoom;
	if (keycode == 65361 || keycode == 97)
		((t_fract *)param)->x -= 170 / ((t_fract *)param)->zoom;
	if (keycode == 65363 || keycode == 100)
		((t_fract *)param)->x += 170 / ((t_fract *)param)->zoom;
	mlx_destroy_image(((t_fract *)param)->mlx->mlx, \
		((t_fract *)param)->mlx->img);
	full_screen((t_fract *)param);
	mlx_put_image_to_window(((t_fract *)param)->mlx->mlx, \
		((t_fract *)param)->mlx->win, ((t_fract *)param)->mlx->img, 0, 0);
	return (0);
}

int	mouse_scroll(int scroll, int x, int y, void *param)
{
	(void)x;
	(void)y;
	if (scroll == 4)
		((t_fract *)param)->zoom *= 1.1;
	else if (scroll == 5)
		((t_fract *)param)->zoom /= 1.1;
	if (((t_fract *)param)->mlx->img)
		mlx_destroy_image(((t_fract *)param)->mlx->mlx, \
			((t_fract *)param)->mlx->img);
	full_screen((t_fract *)param);
	mlx_put_image_to_window(((t_fract *)param)->mlx->mlx, \
		((t_fract *)param)->mlx->win, ((t_fract *)param)->mlx->img, 0, 0);
	return (0);
}

void	hook_events(t_fract *f)
{
	mlx_mouse_hook(f->mlx->win, mouse_scroll, f);
	mlx_key_hook(f->mlx->win, key_hook, f);
	mlx_hook(f->mlx->win, 17, 0, mlx_loop_end, f->mlx->mlx);
}
