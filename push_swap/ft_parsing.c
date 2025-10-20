/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:32:18 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/01 08:49:57 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	is_repeat(char *str)
// {
// 	char	c;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		j = 1;
// 		c = str[i];
// 		while (str[j] != '\0')
// 		{
// 			if (c == str[j])
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int	is_repeat(int j, int i)
// {
// 	if (i == j)
// 		return (1);
// 	return (0);
// }

int	*creation_array(char	*str, int lenght)
{
	int	i;
	int	j;
	int	res;
	int	len;
	int	*array;

	len = lenght;
	array = malloc((len) * sizeof(int));
	i = 0;
	while (i < len)
	{
		j = 0;
		res = 0;
		while (str[j] != '\0')
		{
			res = res * 10 + str[j] - 48;
			j++;
			array[i] = res;
		}
		i++;
	}
	return (array);
}
