/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:19:05 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/06 11:46:51 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/printf/ft_printf.h"
# include "./libft/libft/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define WIDTH	1000
# define HEIGHT	1000
# define S2S2E 0.7071f
# define S2S3 0.8165f
# define DIVSQRT (0.4082f)
# define TOP 8
# define BOTTOM 4
# define RIGHT 2
# define LEFT 1

typedef struct		s_fdf
{
	int				**coor;
	int				nbc;
	int				nbl;
	int				movx;
	int				movy;
	int				min;
	int				max;
	int				pick_color_palet;
	int				perspective;
	float			a;
	float			w;
	float			color;
	float			zoom;
	float			h;
	void			*mlxptr;
	void			*mlxwin;
	void			*mlxima;
	char			*strima;
	char			mov[4];
	char			alphaw[4];
}					t_fdf;

typedef struct		s_point
{
	int				z;
	int				z2;
	int				tx;
	int				ty;
	int				tmpx;
	int				tmpy;
	int				tx2;
	int				ty2;
}					t_point;

typedef struct		s_bzh
{
	int				i;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
	int				x2;
	int				y2;
}					t_bzh;

int					ft_parse_fdf(char *file, t_fdf *f);
void				ft_fill_image(t_fdf *f);
void				ft_put_pixel_on_i(t_fdf *f, int x, int y, int zp);
void				ft_brezenham(t_fdf *f, t_point *p, int zp);
int					ft_commands(int keycode, t_fdf *f);
int					ft_commands2(int keycode, t_fdf *f);
int					ft_loop(t_fdf *f);
int					ft_expose_loop(t_fdf *f);
int					ft_key_down(int keycode, t_fdf *f);
int					ft_key_up(int keycode, t_fdf *f);
int					ft_line_clipping(t_point *p);
void				ft_which_segment(t_point *p, int x, int y, t_fdf *f);

#endif
