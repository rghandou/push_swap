/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:15:03 by rghandou          #+#    #+#             */
/*   Updated: 2025/09/22 10:38:13 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack(t_stack	*s)
{
	int	count;

	count = 0;
	while (s)
	{
		count ++;
		*s = (*s)->next;
	}
	return (count);
}

t_stack	create_stack(void)
{
	return (NULL);
}

int	is_empty(t_stack	*p)
{
	if (p == NULL)
		return (1);
	return (0);
}

int	push(t_stack	*s, int data)
{
	t_stack	new_node;

	new_node = (t_stack) malloc (sizeof (struct s_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = *s;
	*s = new_node;
	return (1);
}

int	pop(t_stack	*s)
{
	t_stack	tmp;

	tmp = *s;
	*s = (*s)->next;
	free(tmp);
	return (1);
}
