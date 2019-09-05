/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:44:46 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/18 15:31:35 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_nb_arg(char *line)
{
	char	**tab;
	int		i;

	if (!(tab = ft_strsplit(line, ' ')))
		return (-1);
	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	return (i);
}

static void	ft_check_min_max(int i, int j, t_fdf *f, char **spline)
{
	if ((f->coor[i][j] = ft_atoi(spline[j])) > f->max)
		f->max = f->coor[i][j];
	else if (f->coor[i][j] < f->min)
		f->min = f->coor[i][j];
	ft_strdel(&spline[j]);
}

static int	ft_get_coor(int fd, t_fdf *f)
{
	char	**spline;
	char	*line;
	int		nb;
	int		i;
	int		j;

	i = -1;
	if (!(f->coor = ft_memalloc(sizeof(int*) * f->nbl)))
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		j = -1;
		if (!(spline = ft_strsplit(line, ' ')))
			return (-1);
		nb = ft_get_nb_arg(line);
		if (f->nbc != nb)
			return (-2);
		if (!(f->coor[++i] = ft_memalloc(sizeof(int) * nb)))
			return (-1);
		while (spline[++j])
			ft_check_min_max(i, j, f, spline);
		ft_strdel(&line);
		free(spline);
	}
	return (0);
}

int			ft_parse_fdf(char *file, t_fdf *f)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		f->nbl++;
		if (f->nbc == 0)
		{
			f->nbc = ft_get_nb_arg(line);
			if (f->nbc == -1)
				return (-1);
		}
		ft_strdel(&line);
	}
	close(fd);
	if (f->nbc == 0)
		return (-3);
	fd = open(file, O_RDONLY);
	return (ft_get_coor(fd, f));
}
