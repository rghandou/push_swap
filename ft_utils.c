/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:04:04 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/22 11:31:46 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_negative(int *n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		*n = (-1) * (*n);
	}
}

int	check_min(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	char	c;
	int		d;
	int		dig;
	int		n;

	d = 1;
	n = nb;
	if (checkmin(n) == 1)
		return ;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	negativecheck(&n);
	while ((n / d) >= 10)
		d *= 10;
	while (d != 0)
	{
		dig = (n / d) % 10;
		c = dig + '0';
		write(1, &c, 1);
		d /= 10;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	count_words(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		if (str[i] != '\0')
			i++;
	}
	return (count);
}
