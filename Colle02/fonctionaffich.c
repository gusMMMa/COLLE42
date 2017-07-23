/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctionaffich.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 21:25:55 by ynacache          #+#    #+#             */
/*   Updated: 2017/07/23 19:01:18 by egrout-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_line_border(int column, char first, char last, char line[])
{
	line[0] = first;
	if (column != 1)
	{
		line[column - 1] = last;
	}
}

void	ft_line_center(int column, char middle, char line[])
{
	int		i;

	i = 1;
	while (i < column - 1)
	{
		line[i] = middle;
		i++;
	}
}

void	ft_print(char line[], int nbline, int column, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	while (nbline > 0)
	{
		while (i < column)
		{
			str[j] = line[i];
			i++;
			j++;
		}
		i = 0;
		str[j] = '\n';
		j++;
		nbline--;
	}
	str[j] = '\0';
}
