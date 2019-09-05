/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:27:22 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/07 11:15:24 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_expose_loop(t_fdf *f)
{
	mlx_clear_window(f->mlxptr, f->mlxwin);
	ft_bzero(f->strima, (WIDTH * 4 * HEIGHT));
	ft_fill_image(f);
	mlx_put_image_to_window(f->mlxptr, f->mlxwin, f->mlxima, 0, 0);
	return (0);
}
