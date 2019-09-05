/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brezenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:35:58 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/18 14:35:48 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_brezenham(t_point *p, t_bzh *b)
{
	b->x = p->tx;
	b->x2 = p->tx2;
	b->y = p->ty;
	b->y2 = p->ty2;
	b->dx = b->x2 - b->x;
	b->dy = b->y2 - b->y;
	b->xinc = (b->dx > 0) ? 1 : -1;
	b->yinc = (b->dy > 0) ? 1 : -1;
	b->dx = abs(b->dx);
	b->dy = abs(b->dy);
}

static void	ft_higher(t_fdf *f, t_bzh *b, int zp)
{
	b->cumul = b->dy / 2;
	b->i = 1;
	while (b->i++ <= b->dy)
	{
		b->y += b->yinc;
		b->cumul += b->dx;
		if (b->cumul >= b->dy)
		{
			b->cumul -= b->dy;
			b->x += b->xinc;
		}
		ft_put_pixel_on_i(f, b->x, b->y, zp);
	}
}

static void	ft_longer(t_fdf *f, t_bzh *b, int zp)
{
	b->cumul = b->dx / 2;
	b->i = 1;
	while (b->i++ <= b->dx)
	{
		b->x += b->xinc;
		b->cumul += b->dy;
		if (b->cumul >= b->dx)
		{
			b->cumul -= b->dx;
			b->y += b->yinc;
		}
		ft_put_pixel_on_i(f, b->x, b->y, zp);
	}
}

void		ft_brezenham(t_fdf *f, t_point *p, int zp)
{
	t_bzh	b;

	ft_init_brezenham(p, &b);
	ft_put_pixel_on_i(f, b.x, b.y, zp);
	if (b.dx > b.dy)
		ft_longer(f, &b, zp);
	else
		ft_higher(f, &b, zp);
}
