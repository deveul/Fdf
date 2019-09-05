/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:55:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/18 14:36:42 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_reset_pos(int keycode, t_fdf *f)
{
	if (keycode == 82)
	{
		f->movx = 0;
		f->movy = 0;
	}
	return (0);
}

static int		ft_height(int keycode, t_fdf *f)
{
	if (keycode == 4)
		f->h *= 2;
	if (keycode == 37 && (f->h / 2 > 0))
		f->h /= 2;
	return (0);
}

static int		ft_quit(t_fdf *f)
{
	int		i;

	i = 0;
	mlx_clear_window(f->mlxptr, f->mlxwin);
	ft_bzero(f->strima, (WIDTH * 4 * HEIGHT));
	while (i < f->nbl)
	{
		free(f->coor[i]);
		i++;
	}
	free(f->coor);
	exit(0);
	return (0);
}

static int		ft_zoom(int keycode, t_fdf *f)
{
	if (keycode == 24)
		f->zoom *= 2;
	else if (keycode == 27 && f->zoom / 2 > 0.0)
		f->zoom /= 2;
	return (0);
}

int				ft_commands(int keycode, t_fdf *f)
{
	if (keycode == 53)
		ft_quit(f);
	else if (keycode == 24 || keycode == 27)
		ft_zoom(keycode, f);
	else if (keycode == 4 || keycode == 37)
		ft_height(keycode, f);
	else if (keycode == 82)
		ft_reset_pos(keycode, f);
	else
		ft_commands2(keycode, f);
	return (0);
}
