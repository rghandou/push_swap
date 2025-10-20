/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:20:57 by rghandou          #+#    #+#             */
/*   Updated: 2025/09/29 12:07:46 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_digit(int s)
{
	if (s == '-')
		return (1);
	if (s >= '0' && s <= '9')
		return (1);
	return (0);
}

void	print_stack(t_stack *s)
{
	while (*s)
	{
		ft_putnbr((*s)->data);
		*s = (*s)->next;
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int	*array;
	int	i;

	i = 1;
	while (i < argc)
	{
		array = creation_array(argv[i], argc - 1);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		printf("%d \n", array[i]);
		i++;
	}
	return (0);
}

// 	/*t_stack	s;
// 	t_stack	s1;

// 	s = create_stack();
// 	s1 = create_stack();
// 	push(&s, 5);
// 	push(&s, 1);
// 	push(&s, 2);
// 	push(&s, 3);
// 	push(&s, 4);
// 	push(&s1, 0);
// 	push(&s1, 7);
// 	ra(&s);
// 	print_stack(&s);
// 	write(1, "\n", 1);
// 	print_stack(&s1);*/
// 	printf("%d",is_repeat("cc"));