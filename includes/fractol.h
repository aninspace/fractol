/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:57:53 by fmelda            #+#    #+#             */
/*   Updated: 2019/12/26 19:16:29 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_X 1.0
# define MIN_X -2.0
# define MIN_Y -1.0
# define MAX_Y  MIN_Y + (MAX_X - MIN_X) * HEIGHT / WIDTH
# define FEET 10
# define WIDTH 1000
# define HEIGHT 700
# define SHIFT_X (MAX_X - MIN_X) / (WIDTH - 1)
# define SHIFT_Y (MAX_Y - MIN_Y) / (HEIGHT - 1)
# include <stdlib.h>
# include "mlx.h"
# include "math.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct			s_mlx
{
	void				*ptr;
	void				*win;
	void				*img;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					*fractol;
}						t_mlx;

typedef struct			s_cmpx
{
	int					check;
	double				c_x;
	double				c_y;
	double				z_x;
	double				z_y;
	double				x2;
	double				y2;
	double				tmp;
}						t_cmpx;

typedef struct			s_fractol
{
	t_mlx				*mlx;
	t_cmpx				*cmplx;
	int					check;
	int					color;
	int					it;
	int					it_max;
	int					stop_jl;
	double				shift_x;
	double				shift_y;
	double				checksh;
	double				checkshy;
	double				zoom;
	double				speed;
	double				min_x;
	double				min_y;
	double				max_y;
	double				max_x;
	double				mouse_x;
	double				mouse_y;
	double				m_x;
	double				m_y;
}						t_fractol;

t_fractol				*create_struct(void);
void					mandelbrod(t_fractol *fractol);
void					fill_backgound(int color, t_fractol *fractol);
int						new_window(t_fractol *fractol);
void					choose_fractol(t_fractol *fractol);
int						delete_struct(int key, t_fractol *fractol);
void					mandelbrot_init(t_fractol *fractol);
void					burningship_init(t_fractol *fractol);
void					burningship(t_fractol *fractol);
void					put_pixel(int x, int y, int color, t_fractol *fractol);
void					julia_init(t_fractol *fractol);
void					julia(t_fractol *fractol);
void					complex_julia(int x, int y, t_fractol *fractol);
void					recolor(int keycode, t_fractol *fractol);

#endif
