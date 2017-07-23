/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:04:00 by ynacache          #+#    #+#             */
/*   Updated: 2017/07/23 14:29:22 by egrout-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		result;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-' ? -1 : 1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (result * sign);
	}
	return (result * sign);
}

void	ft_line_border(int column, char first, char last, char line[])
{
	line[0] = first;
	if (column != 1)
		line[column - 1] = last;
}

void	ft_line_center(int column, char middle, char line[])
{
	int i;

	i = 1;
	while (i < column - 1)
	{
		line[i] = middle;
		i++;
	}
}

void	ft_print(char line[], int nbline, int column)
{
	int		i;

	i = 0;
	while (nbline > 0)
	{
		while (i < column)
		{
			ft_putchar(line[i]);
			i++;
		}
		i = 0;
		ft_putchar('\n');
		nbline--;
	}
}

int		main(int argc, char **argv)
{
	char	line_first[ft_atoi(argv[1])];
	char	line_middle[ft_atoi(argv[1])];
	char	line_last[ft_atoi(argv[1])];

	if (ft_atoi(argv[1]) > 0 && ft_atoi(argv[2]) > 0)
	{
		ft_line_border(ft_atoi(argv[1]), 'A', 'A', line_first);
		ft_line_border(ft_atoi(argv[1]), 'B', 'B', line_middle);
		ft_line_border(ft_atoi(argv[1]), 'C', 'C', line_last);
		ft_line_center(ft_atoi(argv[1]), 'B', line_first);
		ft_line_center(ft_atoi(argv[1]), ' ', line_middle);
		ft_line_center(ft_atoi(argv[1]), 'B', line_last);
		ft_print(line_first, 1, ft_atoi(argv[1]));
		ft_print(line_middle, ft_atoi(argv[2]) - 2, ft_atoi(argv[1]));
		if (ft_atoi(argv[2]) != 1)
		{
			ft_print(line_last, 1, ft_atoi(argv[1]));
		}
	}
}
