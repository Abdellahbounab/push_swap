/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:31:02 by abounab           #+#    #+#             */
/*   Updated: 2024/03/05 17:29:17 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	call_instruction(char *input, t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = ft_strlen(input);
	if (ft_strncmp(input, "sa", len))
		swap(stack_a, NULL);
	else if (ft_strncmp(input, "sb", len))
		swap(stack_b, NULL);
	else if (ft_strncmp(input, "pa", len))
		push(stack_b, stack_a, NULL);
	else if (ft_strncmp(input, "pb", len))
		push(stack_a, stack_b, NULL);
	else if (ft_strncmp(input, "ra", len))
		rotate(stack_a, NULL);
	else if (ft_strncmp(input, "rb", len))
		rotate(stack_b, NULL);
	else if (ft_strncmp(input, "rr", len))
		rr(stack_a, stack_b, NULL);
	else if (ft_strncmp(input, "rra", len))
		reverse_rotate(stack_a, NULL);
	else if (ft_strncmp(input, "rrb", len))
		reverse_rotate(stack_b, NULL);
}

static void	try_input(t_node **stack_a, char **input, int len)
{
	t_node	*stack_b;
	char	**cpy;
	int		i;

	i = 0;
	cpy = input;
	stack_b = NULL;
	while (input && *input)
	{
		call_instruction(*input, stack_a, &stack_b);
		input++;
		i++;
	}
	if (stack_a && len == strlen_lst(*stack_a)
		&& check_sorted_list(*stack_a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	if (cpy)
		free_arr(cpy, i);
}

static int	check_instruction(char *str, int len)
{
	if (*str && ft_strncmp(str, "sa\n", len))
		return (1);
	else if (*str && ft_strncmp(str, "sb\n", len))
		return (1);
	else if (*str && ft_strncmp(str, "ss\n", len))
		return (1);
	else if (*str && ft_strncmp(str, "pa\n", len))
		return (1);
	else if (*str && ft_strncmp(str, "pb\n", len))
		return (1);
	else if (*str && ft_strncmp(str, "ra\n", len))
		return (1);
	else if (*str && ft_strncmp(str, "rb\n", len))
		return (1);
	else if (*str && ft_strncmp(str, "rra\n", len))
		return (1);
	else if (*str && ft_strncmp(str, "rrb\n", len))
		return (1);
	else if (*str && ft_strncmp(str, "rr\n", len))
		return (1);
	else if (*str && ft_strncmp(str, "rrr\n", len))
		return (1);
	return (free(str), 0);
}

static char	**get_input(int fd, int **len, t_node **head, char **arr)
{
	char	*str;
	char	*tmp;
	char	*word;

	tmp = NULL;
	str = NULL;
	word = get_next_line(fd);
	while (word && *word)
	{
		if (check_instruction(word, ft_strlen(word)))
		{
			tmp = str;
			str = ft_strjoins(tmp, word);
			free(tmp);
			free(word);
			if (!str)
				return (free_t_node(head), ft_errno(), NULL);
		}
		else
			return (free(str), free_t_node(head), ft_errno(), NULL);
		word = get_next_line(fd);
	}
	if (str)
		return (arr = ft_split_space(str, len), free(str), arr);
	return (NULL);
}

void	stack_sort2(int *stack, int *len)
{
	t_node	*head;
	t_node	*cpy;
	char	**arr;
	int		i;

	i = 0;
	arr = NULL;
	head = create_t_node(stack[i++]);
	while (i < *len)
	{
		cpy = create_t_node(stack[i++]);
		add_t_node(&head, cpy, strlen_lst(head));
	}
	cpy = ft_sorted_cpy(head);
	cpy_index(&head, cpy);
	try_input(&head, get_input(STDIN_FILENO,
			&len, &head, arr), strlen_lst(head));
	free_t_node(&head);
	free_t_node(&cpy);
}
