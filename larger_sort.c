/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   larger_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:01:13 by abounab           #+#    #+#             */
/*   Updated: 2024/02/23 22:17:01 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_algo(t_node **stack_a, t_node **stack_b)
{
	int	j;
	int	val;
	int	where;

	j = 0;
	where = rangeof(strlen_lst(*stack_a));
	while (strlen_lst(*stack_a))
	{
		val = (*stack_a)->index;
		if (val < 0 + j)
		{
			push(stack_a, stack_b, "pb\n");
			if (strlen_lst(*stack_a) > 1 
				&& next_move(j + 1, where, (*stack_a)->index))
				rr(stack_a, stack_b, "rr\n");
			else
				rotate(stack_b, "rb\n");
			j++;
		}
		else if (val >= 0 + j && val < where + j 
			&& push(stack_a, stack_b, "pb\n"))
			j++;
		else
			rotate(stack_a, "ra\n");
	}
}

static int	top_half(t_node *head, int len, int index)
{
	while (len--)
	{
		if (head->index == index)
			return (1);
		head = head->next;
	}
	return (0);
}

void	second_algo(t_node **stack_a, t_node **stack_b)
{
	int	j;

	j = 0;
	while (strlen_lst(*stack_b))
	{
		j = strlen_lst(*stack_b) - 1;
		if ((*stack_b)->index == j)
			push(stack_b, stack_a, "pa\n");
		else if (top_half(*stack_b, strlen_lst(*stack_b) / 2, j))
			rotate(stack_b, "rb\n");
		else
			reverse_rotate(stack_b, "rrb\n");
	}
}

static void	range_sort(t_node **head)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = *head;
	stack_b = NULL;
	first_algo(&stack_a, &stack_b);
	second_algo(&stack_a, &stack_b);
	*head = stack_a;
}

void	larger_sort(t_node **head)
{
	t_node	*sorted_cpy;

	sorted_cpy = ft_sorted_cpy(*head);
	cpy_index(head, sorted_cpy);
	range_sort(head);
	free_t_node(&sorted_cpy);
}
