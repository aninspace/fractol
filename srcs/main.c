/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:57:35 by fmelda            #+#    #+#             */
/*   Updated: 2019/12/26 19:09:18 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				recolor(int keycode, t_fractol *fractol)
{
	if (keycode == 83)
		fractol->color = 0xFFFFFF;
	else if (keycode == 84)
		fractol->color = 0x630101;
	else if (keycode == 85)
		fractol->color = 0xA18B28;
	else if (keycode == 86)
		fractol->color = 0x9303A7;
	else if (keycode == 87)
		fractol->color = 0x0B61A4;
	else if (keycode == 88)
		fractol->color = 0x58E000;
}

int					check_arg(char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(av[1], "burningship") == 0)
		return (2);
	else if (ft_strcmp(av[1], "julia") == 0)
		return (3);
	else
	{
		ft_putstr("you can write: mandelbrot, julia, burningship\n");
		exit(0);
	}
}

void				choose_fractol(t_fractol *fractol)
{
	if (fractol->check == 1)
	{
		mandelbrod(fractol);
		mlx_put_image_to_window(fractol->mlx->ptr, fractol->mlx->win, \
										fractol->mlx->img, 0, 0);
	}
	else if (fractol->check == 2)
	{
		burningship(fractol);
		mlx_put_image_to_window(fractol->mlx->ptr, fractol->mlx->win, \
										fractol->mlx->img, 0, 0);
	}
	else if (fractol->check == 3)
	{
		julia(fractol);
		mlx_put_image_to_window(fractol->mlx->ptr, fractol->mlx->win, \
										fractol->mlx->img, 0, 0);
	}
}

void				fractol_init(t_fractol *fractol)
{
	if (fractol->check == 1)
		mandelbrot_init(fractol);
	else if (fractol->check == 2)
		burningship_init(fractol);
	else if (fractol->check == 3)
		julia_init(fractol);
}

int					main(int ac, char **av)
{
	t_fractol		*fractol;

	if (ac == 2)
	{
		fractol = create_struct();
		if ((fractol->check = check_arg(av)) != -1)
		{
			fractol_init(fractol);
			new_window(fractol);
		}
	}
	else
		ft_putstr("you can write: mandelbrot, julia, burningship\n");
	return (0);
}
