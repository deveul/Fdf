/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:14:05 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/09/26 15:13:04 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		a;
	char	*dup;

	i = 0;
	a = 0;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	if ((dup = malloc(sizeof(char) * (i + 1))) == 0)
		return (NULL);
	while (a < i)
	{
		dup[a] = src[a];
		a++;
	}
	dup[a] = '\0';
	return (dup);
}
