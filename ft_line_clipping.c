/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_clipping.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 10:22:18 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/18 14:37:05 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_get_code(int x, int y)
{
	int		code;

	code = 0;
	if (x < 0)
		code |= LEFT;
	else if (x >= WIDTH)
		code |= RIGHT;
	if (y < 0)
		code |= BOTTOM;
	else if (y >= HEIGHT)
		code |= TOP;
	return (code);
}

static void		ft_update_value(t_point *p, int *x, int *y, int accept)
{
	if (accept == 1)
	{
		p->tx2 = x[2];
		p->ty2 = y[2];
		p->tx = x[1];
		p->ty = y[1];
	}
}

static void		ft_change_value(int *code, int *x, int *y)
{
	if (code[2] == code[0])
	{
		x[1] = x[0];
		y[1] = y[0];
		code[0] = ft_get_code(x[1], y[1]);
	}
	else if (code[2] == code[1])
	{
		x[2] = x[0];
		y[2] = y[0];
		code[1] = ft_get_code(x[2], y[2]);
	}
}

static void		ft_change_code(int *code, int *x, int *y)
{
	if (code[0] != 0)
		code[2] = code[0];
	else
		code[2] = code[1];
	if (code[2] & TOP)
	{
		x[0] = x[1] + (x[2] - x[1]) * (HEIGHT - y[1]) / (y[2] - y[1]);
		y[0] = HEIGHT - 1;
	}
	else if (code[2] & BOTTOM)
	{
		x[0] = x[1] + (x[2] - x[1]) * (0 - y[1]) / (y[2] - y[1]);
		y[0] = 0;
	}
	else if (code[2] & RIGHT)
	{
		y[0] = y[1] + (y[2] - y[1]) * (WIDTH - x[1]) / (x[2] - x[1]);
		x[0] = WIDTH - 1;
	}
	else if (code[2] & LEFT)
	{
		y[0] = y[1] + (y[2] - y[1]) * (0 - x[1]) / (x[2] - x[1]);
		x[0] = 0;
	}
}

int				ft_line_clipping(t_point *p)
{
	int		code[3];
	int		x[3];
	int		y[3];
	int		accept;

	x[1] = p->tx;
	x[2] = p->tx2;
	y[1] = p->ty;
	y[2] = p->ty2;
	accept = 0;
	code[0] = ft_get_code(x[1], y[1]);
	code[1] = ft_get_code(x[2], y[2]);
	while (accept == 0)
	{
		code[2] = -1;
		if (code[0] == 0 && code[1] == 0)
			accept = 1;
		else if (code[0] & code[1])
			accept = -1;
		else
			ft_change_code(code, x, y);
		ft_change_value(code, x, y);
		ft_update_value(p, x, y, accept);
	}
	return (accept);
}
