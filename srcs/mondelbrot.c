/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mondelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:42:21 by fmelda            #+#    #+#             */
/*   Updated: 2019/12/26 19:06:54 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				mandelbrot_init(t_fractol *fractol)
{
	fractol->max_x = MAX_X;
	fractol->max_y = MAX_Y;
	fractol->min_x = MIN_X;
	fractol->min_y = MIN_Y;
	fractol->checksh = 0.0;
	fractol->checkshy = 0.0;
	fractol->stop_jl = 0;
}

void				put_pixel(int x, int y, int color, t_fractol *fractol)
{
	fractol->mlx->fractol[y * 1000 + x] = color;
}

void				complex_mandelbrot(int x, int y, t_fractol *fractol)
{
	int	i;

	i = 0;
	fractol->cmplx->z_x = fractol->cmplx->c_x;
	fractol->cmplx->z_y = fractol->cmplx->c_y;
	while (i < 50)
	{
		fractol->cmplx->x2 = fractol->cmplx->z_x * fractol->cmplx->z_x;
		fractol->cmplx->y2 = fractol->cmplx->z_y * fractol->cmplx->z_y;
		if (fractol->cmplx->x2 + fractol->cmplx->y2 > 4)
			break ;
		fractol->cmplx->z_y = 2 * fractol->cmplx->z_x *
					fractol->cmplx->z_y + fractol->cmplx->c_y;
		fractol->cmplx->z_x = fractol->cmplx->x2 -
					fractol->cmplx->y2 + fractol->cmplx->c_x;
		i++;
	}
	if (i == 50)
		put_pixel(x, y, 0x000000, fractol);
	else
		put_pixel(x, y, (fractol->color * i), fractol);
}

void				mandelbrod(t_fractol *fractol)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		fractol->shift_y = (fractol->max_y - fractol->min_y) / (HEIGHT - 1);
		fractol->cmplx->c_y = (fractol->max_y - y * fractol->shift_y +
								fractol->checkshy) * fractol->zoom;
		while (x < WIDTH)
		{
			fractol->shift_x = (fractol->max_x - fractol->min_x)
												/ (WIDTH - 1);
			fractol->cmplx->c_x = (fractol->min_x + x * fractol->shift_x +
										fractol->checksh) * fractol->zoom;
			complex_mandelbrot(x, y, fractol);
			x++;
		}
		y++;
	}
}
