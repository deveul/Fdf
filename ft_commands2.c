/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:01:15 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/17 18:12:51 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_change_perspective(int keycode, t_fdf *f)
{
	if (keycode == 35)
		f->perspective = 1;
	else if (keycode == 34)
		f->perspective = 0;
	else if (keycode == 31)
		f->perspective = 2;
	else if (keycode == 29)
	{
		f->a = 0;
		f->w = 0;
	}
	else if (keycode == 32)
		f->a += 0.1;
	else if (keycode == 16)
		f->a -= 0.1;
	else if (keycode == 28)
		f->w -= 0.1;
	else if (keycode == 25)
		f->w -= 0.1;
	return (0);
}

static int		ft_change_color(int keycode, t_fdf *f)
{
	if (keycode == 1)
		f->pick_color_palet = 1;
	else if (keycode == 5)
		f->pick_color_palet = 0;
	else if (keycode == 3)
		f->pick_color_palet = 2;
	else if (keycode == 13)
		f->pick_color_palet = 3;
	return (0);
}

int				ft_commands2(int keycode, t_fdf *f)
{
	if (keycode == 1 || keycode == 5 || keycode == 3 || keycode == 13)
		ft_change_color(keycode, f);
	else if (keycode == 35 || keycode == 34 || keycode == 32
			|| keycode == 16 || keycode == 31 || keycode == 28
			|| keycode == 25 || keycode == 29)
		ft_change_perspective(keycode, f);
	return (0);
}
