/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 18:27:58 by ynacache          #+#    #+#             */
/*   Updated: 2017/07/23 18:50:41 by egrout-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_col(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		ft_lign(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

int		ft_okisone(int nbok)
{
	if (nbok == 0)
	{
		write(1, "aucune\n", 7);
		return (0);
	}
	else
	{
		return (1);
	}
}

int		ft_nbok(int *tab)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i] == 1)
			result++;
		i++;
	}
	return (result);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('_');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}
