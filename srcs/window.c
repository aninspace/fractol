/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:31:16 by fmelda            #+#    #+#             */
/*   Updated: 2019/12/26 19:04:10 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					key_event(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
		exit(0);
	else if (keycode >= 83 && keycode <= 88)
		recolor(keycode, fractol);
	else if (keycode == 124)
		fractol->checksh -= 0.1;
	else if (keycode == 123)
		fractol->checksh += 0.1;
	else if (keycode == 69)
		fractol->zoom -= 0.01;
	else if (keycode == 78)
		fractol->zoom += 0.01;
	else if (keycode == 125)
		fractol->checkshy += 0.1;
	else if (keycode == 126)
		fractol->checkshy -= 0.1;
	else if (keycode == 49)
		fractol->stop_jl = (fractol->stop_jl + 1) % 2;
	mlx_clear_window(fractol->mlx->ptr, fractol->mlx->win);
	choose_fractol(fractol);
	return (0);
}

int					close_window(void *param)
{
	(void)param;
	exit(0);
}

int					move_hook(int x, int y, t_fractol *fractol)
{
	if (fractol->check == 3 && fractol->stop_jl != 0)
	{
		fractol->mouse_x = x;
		fractol->mouse_y = y;
		mlx_clear_window(fractol->mlx->ptr, fractol->mlx->win);
	}
	choose_fractol(fractol);
	return (0);
}

int					mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractol->zoom += 0.1;
	if (button == 5)
		fractol->zoom -= 0.1;
	mlx_clear_window(fractol->mlx->ptr, fractol->mlx->win);
	choose_fractol(fractol);
	return (0);
}

int					new_window(t_fractol *fractol)
{
	if (!(fractol->mlx->ptr = mlx_init()))
		return (delete_struct(2, fractol));
	if (!(fractol->mlx->win = mlx_new_window(fractol->mlx->ptr,
									WIDTH, HEIGHT, "fractol")))
		return (delete_struct(2, fractol));
	if (!(fractol->mlx->img = mlx_new_image(fractol->mlx->ptr, WIDTH, HEIGHT)))
		return (delete_struct(2, fractol));
	if (!(fractol->mlx->fractol = (int *)mlx_get_data_addr(fractol->mlx->img,
											&(fractol->mlx->bits_per_pixel),
					&(fractol->mlx->size_line), &(fractol->mlx->endian))))
		return (delete_struct(2, fractol));
	choose_fractol(fractol);
	mlx_hook(fractol->mlx->win, 17, 0, close_window, fractol);
	mlx_hook(fractol->mlx->win, 2, 0, key_event, fractol);
	mlx_hook(fractol->mlx->win, 4, 0, mouse_hook, fractol);
	mlx_hook(fractol->mlx->win, 6, 0, move_hook, fractol);
	mlx_loop(fractol->mlx->ptr);
	return (0);
}
