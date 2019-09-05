/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:06:59 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/13 11:22:36 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_f_mlx(t_fdf *f)
{
	f->nbc = 0;
	f->nbl = 0;
	f->movx = 0;
	f->movy = 0;
	f->min = 0;
	f->max = 0;
	f->zoom = 1;
	f->h = 1;
	f->color = 0;
	f->pick_color_palet = 0;
	f->perspective = 0;
	f->a = 0;
	f->w = 0;
	f->mlxptr = NULL;
	f->mlxwin = NULL;
	f->mlxima = NULL;
	f->strima = NULL;
	ft_memset(f->mov, 0, 4);
	ft_memset(f->alphaw, 0, 4);
}

static void	ft_error_display(int argc, int ret)
{
	if (argc != 2)
		write(1, "Usage : ./fdf file.fdf\n", 23);
	else if (ret == -1)
		write(1, "Malloc error\n", 13);
	else if (ret == -2)
		write(1, "Uneven number of points between two lines\n", 42);
	else if (ret == -3)
		write(1, "Invalid or empty file\n", 22);
}

int			main(int argc, char **argv)
{
	t_fdf	f;
	int		bpp;
	int		s_l;
	int		endian;
	int		ret;

	ft_init_f_mlx(&f);
	ret = 0;
	if (argc != 2 || (ret = ft_parse_fdf(argv[1], &f)) < 0)
	{
		ft_error_display(argc, ret);
		return (-1);
	}
	f.mlxptr = mlx_init();
	f.mlxwin = mlx_new_window(f.mlxptr, WIDTH, HEIGHT, "fdf");
	f.mlxima = mlx_new_image(f.mlxptr, WIDTH, HEIGHT);
	f.strima = mlx_get_data_addr(f.mlxima, &(bpp), &(s_l), &(endian));
	ft_fill_image(&f);
	mlx_put_image_to_window(f.mlxptr, f.mlxwin, f.mlxima, 0, 0);
	mlx_expose_hook(f.mlxwin, ft_expose_loop, &f);
	mlx_hook(f.mlxwin, 2, 0, ft_key_down, &f);
	mlx_hook(f.mlxwin, 3, 0, ft_key_up, &f);
	mlx_loop_hook(f.mlxptr, ft_loop, &f);
	mlx_loop(f.mlxptr);
	return (0);
}
