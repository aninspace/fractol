/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:26:01 by fmelda            #+#    #+#             */
/*   Updated: 2019/12/26 18:59:43 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia_init(t_fractol *fractol)
{
	fractol->max_x = 2.0;
	fractol->max_y = 2.0;
	fractol->min_y = -2.0;
	fractol->min_x = -2.0;
	fractol->checksh = 0.0;
	fractol->checkshy = 0.0;
	fractol->mouse_x = 1015;
	fractol->mouse_y = 555;
	fractol->stop_jl = 0;
}

void		complex_julia(int x, int y, t_fractol *fractol)
{
	int i;

	i = 0;
	fractol->cmplx->z_x = fractol->cmplx->c_x;
	fractol->cmplx->z_y = fractol->cmplx->c_y;
	fractol->m_x = (float)(fractol->mouse_x - (WIDTH / 2)) / 400.0;
	fractol->m_y = (float)(fractol->mouse_y - (HEIGHT / 2)) / 400.0;
	while (i < 50)
	{
		fractol->cmplx->x2 = fractol->cmplx->z_x * fractol->cmplx->z_x;
		fractol->cmplx->y2 = fractol->cmplx->z_y * fractol->cmplx->z_y;
		if (fractol->cmplx->x2 + fractol->cmplx->y2 > 4)
			break ;
		fractol->cmplx->tmp = fractol->cmplx->z_y;
		fractol->cmplx->z_y = fractol->cmplx->y2 - fractol->cmplx->x2
						- 0.8 + (fractol->cmplx->c_y / WIDTH) + fractol->m_x;
		fractol->cmplx->z_x = 2 * fractol->cmplx->z_x * fractol->cmplx->tmp
						+ fractol->cmplx->c_x / WIDTH + fractol->m_y;
		i++;
	}
	if (i == 50)
		put_pixel(x, y, 0x000000, fractol);
	else
		put_pixel(x, y, (fractol->color * i), fractol);
}

void		julia(t_fractol *fractol)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		fractol->shift_y = (fractol->max_y - fractol->min_y) / (HEIGHT - 1);
		fractol->cmplx->c_y = (fractol->max_y - y * fractol->shift_y
							+ fractol->checkshy) * fractol->zoom;
		while (x < WIDTH)
		{
			fractol->shift_x = (fractol->max_x - fractol->min_x) / (WIDTH - 1);
			fractol->cmplx->c_x = (fractol->min_x + x * fractol->shift_x
								+ fractol->checksh) * fractol->zoom;
			complex_julia(x, y, fractol);
			x++;
		}
		y++;
	}
}
