/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:27:22 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/22 14:37:35 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_rotate(t_fdf *f)
{
	if (f->alphaw[0] == 1)
		f->a += 0.1;
	if (f->alphaw[1] == 1)
		f->a -= 0.1;
	if (f->alphaw[2] == 1)
		f->w += 0.1;
	if (f->alphaw[3] == 1)
		f->w -= 0.1;
	return (0);
}

static int		ft_movements(t_fdf *f)
{
	if (f->mov[0] == 1)
		f->movx += 10;
	if (f->mov[1] == 1)
		f->movx -= 10;
	if (f->mov[2] == 1)
		f->movy -= 10;
	if (f->mov[3] == 1)
		f->movy += 10;
	return (0);
}

int				ft_loop(t_fdf *f)
{
	mlx_clear_window(f->mlxptr, f->mlxwin);
	ft_bzero(f->strima, (WIDTH * 4 * HEIGHT));
	ft_movements(f);
	ft_rotate(f);
	ft_fill_image(f);
	mlx_put_image_to_window(f->mlxptr, f->mlxwin, f->mlxima, 0, 0);
	return (0);
}
