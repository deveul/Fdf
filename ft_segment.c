/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:29:30 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/18 14:38:05 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_p_before_proj(t_fdf *f, t_point *p, int x, int y)
{
	int		zp;

	p->tx2 = x - (f->nbc / 2);
	p->ty2 = y - (f->nbl / 2);
	p->z2 = f->coor[y][x] * f->h;
	zp = (p->z + p->z2) / (2 * f->h);
	p->tmpx = f->zoom * (WIDTH / (f->nbc * 2.f)) * (p->tx2);
	p->tmpy = f->zoom * (HEIGHT / (f->nbl * 2.f)) * (p->ty2);
	return (zp);
}

static void	ft_this_segment(t_point *p, t_fdf *f, int zp)
{
	if (f->perspective == 0 || f->perspective == 1)
	{
		p->tx2 = ((S2S2E) * (p->tmpx - p->tmpy));
		if (f->perspective == 0)
			p->ty2 = -((S2S3 * p->z2 * f->zoom) \
					- (DIVSQRT * (p->tmpx + p->tmpy)));
		else
			p->ty2 = -((S2S2E) * sin(f->a) \
					* (p->tmpx + p->tmpy) + cos(f->a) * p->z2);
	}
	else if (f->perspective == 2)
	{
		p->tx2 = ((cos(f->w) * p->tmpx) - (sin(f->w) * p->tmpy));
		p->ty2 = -(sin(f->w) * sin(f->a) * p->tmpx - (cos(f->w) \
					* sin(f->a) * (p->tmpy)) + (cos(f->a) * p->z2));
	}
	p->tx2 += (WIDTH / 2);
	p->tx2 += f->movx;
	p->ty2 += (HEIGHT / 2);
	p->ty2 += f->movy;
	if (ft_line_clipping(p) == 1)
		ft_brezenham(f, p, zp);
	else
		return ;
}

void		ft_which_segment(t_point *p, int x, int y, t_fdf *f)
{
	int		zp;
	t_point	pbis;

	pbis = *p;
	if (x + 1 < f->nbc)
	{
		zp = ft_get_p_before_proj(f, p, ++x, y);
		ft_this_segment(p, f, zp);
		x--;
	}
	if (y + 1 < f->nbl)
	{
		zp = ft_get_p_before_proj(f, &pbis, x, ++y);
		ft_this_segment(&pbis, f, zp);
	}
}
