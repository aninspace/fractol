/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:04:26 by fmelda            #+#    #+#             */
/*   Updated: 2019/12/26 19:04:30 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					delete_struct(int key, t_fractol *fractol)
{
	if (key == 2)
	{
		free(fractol->mlx);
		fractol->mlx = NULL;
	}
	if (key == 2 || key == 1)
	{
		free(fractol->cmplx);
		fractol->mlx = NULL;
	}
	if (key == 2 || key == 1 || key == 0)
	{
		free(fractol);
		fractol = NULL;
	}
	return (1);
}

t_fractol			*create_struct(void)
{
	t_fractol		*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		return (NULL);
	if (!(fractol->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
	{
		delete_struct(0, fractol);
		return (NULL);
	}
	if (!(fractol->cmplx = (t_cmpx *)malloc(sizeof(t_cmpx))))
	{
		delete_struct(1, fractol);
		return (NULL);
	}
	fractol->color = 0x0000AF;
	fractol->zoom = 0.99;
	return (fractol);
}
