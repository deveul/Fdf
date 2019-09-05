/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:55:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/07 11:23:11 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key_up(int keycode, t_fdf *f)
{
	if (keycode == 123)
		f->mov[0] = 0;
	else if (keycode == 124)
		f->mov[1] = 0;
	else if (keycode == 125)
		f->mov[2] = 0;
	else if (keycode == 126)
		f->mov[3] = 0;
	else if (keycode == 32)
		f->alphaw[0] = 0;
	else if (keycode == 16)
		f->alphaw[1] = 0;
	else if (keycode == 28)
		f->alphaw[2] = 0;
	else if (keycode == 25)
		f->alphaw[3] = 0;
	ft_commands(keycode, f);
	return (0);
}

int		ft_key_down(int keycode, t_fdf *f)
{
	if (keycode == 123)
		f->mov[0] = 1;
	else if (keycode == 124)
		f->mov[1] = 1;
	else if (keycode == 125)
		f->mov[2] = 1;
	else if (keycode == 126)
		f->mov[3] = 1;
	else if (keycode == 32)
		f->alphaw[0] = 1;
	else if (keycode == 16)
		f->alphaw[1] = 1;
	else if (keycode == 28)
		f->alphaw[2] = 1;
	else if (keycode == 25)
		f->alphaw[3] = 1;
	return (0);
}
