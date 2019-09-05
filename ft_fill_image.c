/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:55:53 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/18 14:35:36 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_which_perspective(t_point *p, t_fdf *f)
{
	if (f->perspective == 0 || f->perspective == 1)
	{
		p->tx = ((S2S2E) * (p->tmpx - p->tmpy));
		if (f->perspective == 0)
			p->ty = -((S2S3 * p->z * f->zoom) \
					- (DIVSQRT * (p->tmpx + p->tmpy)));
		else
			p->ty = -((S2S2E) * sin(f->a) \
					* (p->tmpx + p->tmpy) + cos(f->a) * p->z);
	}
	else if (f->perspective == 2)
	{
		p->tx = ((cos(f->w) * p->tmpx) - (sin(f->w) * p->tmpy));
		p->ty = -(sin(f->w) * sin(f->a) * p->tmpx - (cos(f->w) \
					* sin(f->a) * (p->tmpy)) + (cos(f->a) * p->z));
	}
}

static void	ft_get_p_before_proj(t_point *p, t_fdf *f, int x, int y)
{
	p->tx = x - (f->nbc / 2);
	p->ty = y - (f->nbl / 2);
	p->z = f->coor[y][x] * f->h;
	p->tmpx = f->zoom * ((WIDTH) / (f->nbc * 2.f)) * (p->tx);
	p->tmpy = f->zoom * (HEIGHT / (f->nbl * 2.f)) * (p->ty);
}

void		ft_fill_image(t_fdf *f)
{
	int		x;
	int		y;
	t_point	p;

	y = 0;
	f->color = (float)((f->max - f->min) / (5.0));
	while (y < f->nbl)
	{
		x = 0;
		while (x < f->nbc)
		{
			ft_get_p_before_proj(&p, f, x, y);
			ft_which_perspective(&p, f);
			p.tx += (WIDTH / 2);
			p.tx += f->movx;
			p.ty += (HEIGHT / 2);
			p.ty += f->movy;
			ft_which_segment(&p, x, y, f);
			x++;
		}
		y++;
	}
}
