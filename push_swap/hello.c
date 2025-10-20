#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef t_node	*t_stack;

// Stack operations
int			count_stack(t_stack s);
int			pop(t_stack *s);
int			is_empty(t_stack s);
int			push(t_stack *s, int data);
void		clear_stack(t_stack *s);

// Push_swap operations
int			pa(t_stack *a, t_stack *b);
int			pb(t_stack *b, t_stack *a);
int			sa(t_stack *s);
int			sb(t_stack *s);
int			ss(t_stack *a, t_stack *b);
int			ra(t_stack *s);
int			rb(t_stack *s);
int			rr(t_stack *a, t_stack *b);
int			rra(t_stack *s);
int			rrb(t_stack *s);
int			rrr(t_stack *a, t_stack *b);

// Utility functions
int			*creation_array(char *str, int *length);
void		ft_putnbr(int n);
char		**ft_split(const char *s, char c);
int			ft_atoi(const char *str);
void		free_split(char **split);
t_stack		create_stack(void);
int			is_sorted(t_stack s);

#endif

// ============= UTILITY FUNCTIONS =============

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			return (0); // Error handling for overflow
		i++;
	}
	return ((int)(result * sign));
}

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*alloc_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		start;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	result = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[i] && j < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
			result[j++] = alloc_word(s, start, i);
	}
	result[j] = NULL;
	return (result);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	*creation_array(char *str, int *length)
{
	char	**split;
	int		*array;
	int		i;
	int		count;

	split = ft_split(str, ' ');
	if (!split)
		return (NULL);
	count = 0;
	while (split[count])
		count++;
	array = malloc(count * sizeof(int));
	if (!array)
	{
		free_split(split);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		array[i] = ft_atoi(split[i]);
		i++;
	}
	*length = count;
	free_split(split);
	return (array);
}

// ============= STACK OPERATIONS =============

t_stack	create_stack(void)
{
	return (NULL);
}

int	is_empty(t_stack s)
{
	return (s == NULL);
}

int	push(t_stack *s, int data)
{
	t_stack	new_node;

	new_node = (t_stack)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = *s;
	*s = new_node;
	return (1);
}

int	pop(t_stack *s)
{
	t_stack	tmp;

	if (!s || !(*s))
		return (0);
	tmp = *s;
	*s = (*s)->next;
	free(tmp);
	return (1);
}

int	count_stack(t_stack s)
{
	int	count;

	count = 0;
	while (s)
	{
		count++;
		s = s->next;
	}
	return (count);
}

void	clear_stack(t_stack *s)
{
	while (*s)
		pop(s);
}

int	is_sorted(t_stack s)
{
	while (s && s->next)
	{
		if (s->data > s->next->data)
			return (0);
		s = s->next;
	}
	return (1);
}

// ============= PUSH_SWAP OPERATIONS =============

int	pa(t_stack *a, t_stack *b)
{
	int	data;

	if (is_empty(*b))
		return (0);
	data = (*b)->data;
	pop(b);
	push(a, data);
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack *b, t_stack *a)
{
	int	data;

	if (is_empty(*a))
		return (0);
	data = (*a)->data;
	pop(a);
	push(b, data);
	write(1, "pb\n", 3);
	return (1);
}

int	sa(t_stack *s)
{
	int	tmp;

	if (!s || !(*s) || !(*s)->next)
		return (0);
	tmp = (*s)->data;
	(*s)->data = (*s)->next->data;
	(*s)->next->data = tmp;
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack *s)
{
	int	tmp;

	if (!s || !(*s) || !(*s)->next)
		return (0);
	tmp = (*s)->data;
	(*s)->data = (*s)->next->data;
	(*s)->next->data = tmp;
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	int	result_a;
	int	result_b;

	result_a = 0;
	result_b = 0;
	if (a && *a && (*a)->next)
	{
		int tmp = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp;
		result_a = 1;
	}
	if (b && *b && (*b)->next)
	{
		int tmp = (*b)->data;
		(*b)->data = (*b)->next->data;
		(*b)->next->data = tmp;
		result_b = 1;
	}
	if (result_a || result_b)
		write(1, "ss\n", 3);
	return (result_a || result_b);
}

int	ra(t_stack *s)
{
	t_stack	first;
	t_stack	current;

	if (!s || !(*s) || !(*s)->next)
		return (0);
	first = *s;
	*s = (*s)->next;
	first->next = NULL;
	current = *s;
	while (current->next)
		current = current->next;
	current->next = first;
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack *s)
{
	t_stack	first;
	t_stack	current;

	if (!s || !(*s) || !(*s)->next)
		return (0);
	first = *s;
	*s = (*s)->next;
	first->next = NULL;
	current = *s;
	while (current->next)
		current = current->next;
	current->next = first;
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	int	result_a;
	int	result_b;
	t_stack	first;
	t_stack	current;

	result_a = 0;
	result_b = 0;
	if (a && *a && (*a)->next)
	{
		first = *a;
		*a = (*a)->next;
		first->next = NULL;
		current = *a;
		while (current->next)
			current = current->next;
		current->next = first;
		result_a = 1;
	}
	if (b && *b && (*b)->next)
	{
		first = *b;
		*b = (*b)->next;
		first->next = NULL;
		current = *b;
		while (current->next)
			current = current->next;
		current->next = first;
		result_b = 1;
	}
	if (result_a || result_b)
		write(1, "rr\n", 3);
	return (result_a || result_b);
}

int	rra(t_stack *s)
{
	t_stack	last;
	t_stack	current;

	if (!s || !(*s) || !(*s)->next)
		return (0);
	current = *s;
	while (current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = *s;
	*s = last;
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack *s)
{
	t_stack	last;
	t_stack	current;

	if (!s || !(*s) || !(*s)->next)
		return (0);
	current = *s;
	while (current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = *s;
	*s = last;
	write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	int		result_a;
	int		result_b;
	t_stack	last;
	t_stack	current;

	result_a = 0;
	result_b = 0;
	if (a && *a && (*a)->next)
	{
		current = *a;
		while (current->next->next)
			current = current->next;
		last = current->next;
		current->next = NULL;
		last->next = *a;
		*a = last;
		result_a = 1;
	}
	if (b && *b && (*b)->next)
	{
		current = *b;
		while (current->next->next)
			current = current->next;
		last = current->next;
		current->next = NULL;
		last->next = *b;
		*b = last;
		result_b = 1;
	}
	if (result_a || result_b)
		write(1, "rrr\n", 4);
	return (result_a || result_b);
}

// ============= MAIN =============

void	print_stack(t_stack s)
{
	while (s)
	{
		ft_putnbr(s->data);
		write(1, "\n", 1);
		s = s->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	int		*array;
	int		length;
	int		i;

	if (argc < 2)
		return (0);
	
	stack_a = create_stack();
	length = 0;
	
	// Parse all arguments
	i = 1;
	while (i < argc)
	{
		array = creation_array(argv[i], &length);
		if (!array)
			return (1);
		
		// Push in reverse order to maintain input order
		int j = length - 1;
		while (j >= 0)
		{
			push(&stack_a, array[j]);
			j--;
		}
		free(array);
		i++;
	}
	
	// Example: Print stack
	write(1, "Stack A:\n", 9);
	print_stack(stack_a);
	
	// Clean up
	clear_stack(&stack_a);
	
	return (0);
}
