/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:10:55 by ynacache          #+#    #+#             */
/*   Updated: 2017/07/23 19:00:35 by egrout-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

int		*ft_compare(char *str1, int ligne, int colonne, int nbchar)
{
	int		*retour;
	char	*temp;
	int		i;

	t_rush	t_ope[5] =
	{
		{0, rush00},
		{1, rush01},
		{2, rush02},
		{3, rush03},
		{4, rush04},
	};
	i = 0;
	retour = (int *)malloc(sizeof(int) * (5 + 1));
	temp = (char *)malloc(sizeof(char) * (nbchar + 1));
	while (i < 1)
	{
		temp = t_ope[i].f(colonne, ligne);
		if (ft_strcmp(temp, str1) == 0)
			retour[i] = 1;
		else
			retour[i] = 2;
		i++;
	}
	retour[i] = '\0';
	return (retour);
}
