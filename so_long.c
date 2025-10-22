/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:02:58 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/22 12:25:34 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_invalid(char **strs)
{
	int	i;

	i = 0;
	if (!valid_input(strs))
	{
		wriet(1, "Error: Invalid map.\n", 21);
		i = 0;
		while (strs[i])
		{
			free(strs[i]);
			i++
		}
		exit(0);
	}
}

void main
