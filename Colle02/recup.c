/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:18:18 by ynacache          #+#    #+#             */
/*   Updated: 2017/07/23 19:10:12 by egrout-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "header.h"

char	*ft_allocplusun(char *src)
{
	char	*new;
	int		taillesrc;
	int		i;

	i = 0;
	if (*src == '\0')
		return (0);
	taillesrc = ft_strlen(src);
	if (!(new = (char *)malloc(sizeof(char) * (taillesrc + 2))))
		return (NULL);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i + 1] = '\0';
	free(src);
	return (new);
}

void	ft_print_name(int i, int colonne, int ligne)
{
	write(1, "[colle-0", 8);
	ft_putnbr(i);
	write(1, "] ", 2);
	write(1, "[", 1);
	ft_putnbr(colonne);
	write(1, "] ", 2);
	write(1, "[", 1);
	ft_putnbr(ligne);
}

void	ft_option(int *nbok, int *tab, int square[2], int *i)
{
	if (tab[*i] == 1 && *nbok > 1)
	{
		ft_print_name(*i, square[0], square[1]);
		write(1, "]", 1);
		write(1, " || ", 4);
		*nbok = *nbok - 1;
	}
	if (tab[*i] == 1 && *nbok == 1)
	{
		*i = *i + 1;
		ft_print_name(*i, square[0], square[1]);
		write(1, "]\n", 2);
		return ;
	}
}

void	ft_affiche(int *tab, int ligne, int colonne)
{
	int		i;
	int		nbok;
	int		square[2];

	i = -1;
	square[0] = colonne;
	square[1] = ligne;
	nbok = ft_nbok(tab);
	if (ft_okisone(nbok) == 0)
		return ;
	while (nbok == 1 && tab[++i])
	{
		if (tab[i] == 1)
		{
			ft_print_name(i, colonne, ligne);
			write(1, "]\n", 2);
			return ;
		}
	}
	while (nbok > 1 && tab[++i])
	{
		ft_option(&nbok, tab, square, &i);
		if (tab[i] == 1 && nbok == 1)
			return ;
	}
}

int		main(void)
{
	char	buf[2];
	char	*str;
	int		i;
	int		colonne;

	i = 0;
	str = (char *)malloc(sizeof(char) * 2);
	str[0] = '\0';
	buf[0] = 'A';
	while (read(0, buf, 1) != 0)
	{
		str[i] = buf[0];
		str = ft_allocplusun(str);
		i++;
	}
	str[i] = '\0';
	i = 0;
	i = ft_lign(str);
	colonne = ft_col(str);
	ft_affiche(ft_compare(str, i, colonne, ft_strlen(str)), i, colonne);
	return (0);
}
