/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:38:50 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/22 10:26:55 by rghandou         ###   ########.fr       */
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
}	t_node;
typedef t_node	*t_stack;

int			count_stack(t_stack	*s);
int			pop(t_stack	*s);
int			is_empty(t_stack	*s);
int			push(t_stack	*s, int data);
void		clear_stack(t_stack *s);
int			pa(t_stack *a, t_stack *b);
int			pb(t_stack *b, t_stack *a);
int			sa(t_stack	*s);
int			sb(t_stack	*s);
int			ss(t_stack *a, t_stack *b);
int			ra(t_stack	*s);
int			rb(t_stack	*s);
int			rr(t_stack *a, t_stack *b);
int			rra(t_stack	*s);
int			rrb(t_stack	*s);
int			rrr(t_stack *a, t_stack *b);
int			*creation_array(char	*str, int *lenght);
void		free_split(char **split);
void		ft_putnbr(int n);
char		**ft_split(const char *s, char c);
t_stack		create_stack(void);
int			is_sorted(t_stack s);
void		sort_small(t_stack *a, t_stack *b);
#endif