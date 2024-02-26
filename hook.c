/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzuccare <vzuccare@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:20:54 by vzuccare          #+#    #+#             */
/*   Updated: 2024/02/26 16:36:50 by vzuccare         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_key(t_fract *f)
{


void	hook_events(t_fract *f)
{
	mlx_hook(f->mlx->win, 17, 0, mlx_loop_end, f->mlx->mlx);
	mlx_key(f);
}