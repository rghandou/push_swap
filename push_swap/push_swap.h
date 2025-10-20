/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:38:50 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/20 09:58:38 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	*t_stack;

int			count_stack(t_stack	*s);
int			pop(t_stack	*s);
int			is_empty(t_stack	*s);
int			push(t_stack	*s, int data);
int			pa(t_stack *s, t_stack *s1);
int			sa(t_stack	*s);
int			ra(t_stack	*s);
int			rra(t_stack	*s);
int			top_index(t_stack	*s);
int			*creation_array(char	*str, int lenght);
void		ft_putnbr(int n);
void		ss(t_stack	*s, t_stack *s1);
t_stack		create_stack(void);
t_stack		*ft_stack_last(t_stack*lst);
#endif