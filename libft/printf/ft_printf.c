/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:40:28 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/10/17 18:21:08 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf3(t_prf *prf, t_fmt arg)
{
	if (arg.conv != 'c' && arg.conv != 'C'
			&& arg.conv != 'S' && arg.conv != 's')
		prf->cpt[1] = ft_strlen(prf->tmp);
	if (!(prf->tmp2 = ft_memdup(prf->top, prf->cpt[2])))
		return (-1);
	ft_strdel(&prf->top);
	if (!(prf->top = ft_memjoin(prf->tmp2, prf->tmp, prf->cpt[2], prf->cpt[1])))
		return (-1);
	ft_del_prf(prf, &arg);
	prf->cpt[0] += arg.len;
	prf->cpt[2] += prf->cpt[1];
	return (1);
}

static int	ft_printf2(va_list ap, t_prf *prf, const char *format)
{
	t_fmt	arg;

	if (prf->cpt[3] == 0)
		prf->cpt[3] = prf->cpt[1];
	prf->cpt[1] = 0;
	arg = ft_analyze_arg(&format[++prf->cpt[0]]);
	if ((prf->tmp = ft_get_conv(ap, &arg, &prf->cpt[1])) == 0)
	{
		if (prf->tmp2)
			write(1, prf->tmp2, prf->cpt[3]);
		else
			write(1, prf->top, prf->cpt[3]);
		ft_del_prf2(prf, &arg);
		return (-1);
	}
	return (ft_printf3(prf, arg));
}

static int	ft_printf4(t_prf *prf, const char *format)
{
	if (!(prf->tmp2 = ft_memdup(prf->top, prf->cpt[2])))
		return (-1);
	prf->cpt[3] = prf->cpt[2];
	ft_strdel(&prf->top);
	if (!(prf->top = ft_memjoin(prf->tmp2, &format[prf->cpt[0]], prf->cpt[2],
			ft_strlenuntilc(&format[prf->cpt[0]], '%'))))
		return (-1);
	while (format[prf->cpt[0]] && format[prf->cpt[0]] != '%')
	{
		prf->cpt[0]++;
		prf->cpt[2]++;
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_prf	prf;

	if (!format)
		return (-1);
	ft_init_prf(&prf);
	if ((prf.cpt[0] = ft_get_arg_nb(format)) == 0)
		return (ft_only_fmt(format));
	prf.cpt[0] = 0;
	va_start(ap, format);
	while (format[prf.cpt[0]])
	{
		if (format[prf.cpt[0]] == '%')
		{
			if ((ft_printf2(ap, &prf, format)) == -1)
				return (-1);
		}
		else if ((ft_printf4(&prf, format)) == -1)
			return (-1);
	}
	va_end(ap);
	write(1, prf.top, prf.cpt[2]);
	ft_strdel(&prf.tmp2);
	ft_del_prfo(&prf);
	return (prf.cpt[2]);
}
