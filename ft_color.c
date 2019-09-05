/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:31:31 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/07 12:12:45 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_geo_color(t_fdf *f, int pos, int zp)
{
	if (zp <= f->min + f->color)
		f->strima[pos + 1] = (char)255;
	else if (zp > (f->min + f->color) && zp <= (f->min + (2 * f->color)))
	{
		f->strima[pos + 1] = (char)255;
		f->strima[pos + 2] = (char)190;
	}
	else if (zp <= (f->min + (3 * f->color)))
	{
		f->strima[pos + 1] = (char)190;
		f->strima[pos + 2] = (char)255;
	}
	else if (zp <= (f->min + (4 * f->color)))
	{
		f->strima[pos + 1] = (char)128;
		f->strima[pos + 2] = (char)255;
	}
	else if (zp > f->min + (4 * f->color))
		f->strima[pos + 2] = (char)255;
}

static void	ft_sea_color(t_fdf *f, int pos, int zp)
{
	if (zp <= f->min + f->color)
		f->strima[pos + 0] = (char)100;
	else if (zp <= (f->min + (2 * f->color)))
		f->strima[pos + 0] = (char)200;
	else if (zp <= (f->min + (3 * f->color)))
	{
		f->strima[pos + 0] = (char)255;
		f->strima[pos + 1] = (char)100;
	}
	else if (zp <= (f->min + (4 * f->color)))
	{
		f->strima[pos + 0] = (char)255;
		f->strima[pos + 1] = (char)160;
	}
	else if (zp > f->max - f->color)
	{
		f->strima[pos + 0] = (char)255;
		f->strima[pos + 1] = (char)255;
	}
}

static void	ft_geo_color_with_water(t_fdf *f, int pos, int zp)
{
	if (zp == 0)
		f->strima[pos] = (char)255;
	else if (zp <= f->min + (f->color / 2))
		f->strima[pos + 1] = (char)255;
	else if (zp <= (f->min + f->color))
	{
		f->strima[pos + 1] = (char)255;
		f->strima[pos + 2] = (char)90;
	}
	else if (zp <= (f->min + (2 * f->color)))
	{
		f->strima[pos + 1] = (char)255;
		f->strima[pos + 2] = (char)190;
	}
	else if (zp <= (f->min + (3 * f->color)))
	{
		f->strima[pos + 1] = (char)190;
		f->strima[pos + 2] = (char)255;
	}
	else
	{
		f->strima[pos + 2] = (char)255;
		if (zp <= (f->min + (4 * f->color)))
			f->strima[pos + 1] = (char)128;
	}
}

void		ft_put_pixel_on_i(t_fdf *f, int x, int y, int zp)
{
	int		pos;
	int		posx;
	int		posy;

	posx = 4 * x;
	posy = 4 * WIDTH * y;
	pos = posx + posy;
	if (f->pick_color_palet == 0)
		ft_geo_color(f, pos, zp);
	else if (f->pick_color_palet == 1)
		ft_sea_color(f, pos, zp);
	else if (f->pick_color_palet == 2)
		ft_geo_color_with_water(f, pos, zp);
	else if (f->pick_color_palet == 3)
	{
		f->strima[pos] = (char)255;
		f->strima[pos + 1] = (char)255;
		f->strima[pos + 2] = (char)255;
	}
}
