/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:31:52 by ynacache          #+#    #+#             */
/*   Updated: 2017/07/23 19:15:21 by egrout-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

#include <unistd.h>

typedef struct		s_rush
{
	int				x;
	char			*(*f)(int, int);
}					t_rush;

char				*rush00(int x, int y);
char				*rush01(int x, int y);
char				*rush02(int x, int y);
char				*rush03(int x, int y);
char				*rush04(int x, int y);
int					*ft_compare(char *str, int ligne, int colonne, int nbchar);
int					ft_strlen(char *str);
void				ft_line_border(int column, char first, char last,
															char line[]);
void				ft_line_center(int column, char middle, char line[]);
void				ft_print(char line[], int nbline, int column, char *str);
void				ft_putchar(char c);
int					ft_col(char *str);
int					ft_lign(char *str);
int					ft_okisone(int nbok);
int					ft_nbok(int *tab);
void				ft_putnbr(int nb);

#endif
