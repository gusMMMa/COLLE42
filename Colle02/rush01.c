/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:04:00 by ynacache          #+#    #+#             */
/*   Updated: 2017/07/23 14:11:55 by egrout-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

char	*rush01(int x, int y)
{
	char	line_first[x];
	char	line_middle[x];
	char	line_last[x];
	char	*str;
	int		nblettre2;

	nblettre2 = x * y + y;
	if (!(str = (char *)malloc(sizeof(char) * (nblettre2 + 1))))
		return (NULL);
	if (x > 0 && y > 0)
	{
		ft_line_border(x, '/', '\\', line_first);
		ft_line_border(x, '*', '*', line_middle);
		ft_line_border(x, '\\', '/', line_last);
		ft_line_center(x, '*', line_first);
		ft_line_center(x, ' ', line_middle);
		ft_line_center(x, '*', line_last);
		ft_print(line_first, 1, x, str);
		ft_print(line_middle, y - 2, x, str);
		if (y > 1)
			ft_print(line_last, 1, x, str);
	}
	str[nblettre2] = '\0';
	return (str);
}
