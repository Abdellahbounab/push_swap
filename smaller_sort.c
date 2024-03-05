/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:06 by abounab           #+#    #+#             */
/*   Updated: 2024/02/26 18:44:31 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_three(t_node **head)
{
	if (!check_sorted_list(*head))
	{
		if ((*head)->value > (*head)->next->value)
		{
			swap(head, "sa\n");
			if (!check_sorted_list(*head) && get_t_node(head, 3))
			{
				if ((*head)->value > (*head)->next->next->value)
					reverse_rotate(head, "rra\n");
				else
					sort_three(head);
			}
		}
		else if (!check_sorted_list(*head))
		{
			reverse_rotate(head, "rra\n");
			sort_three(head);
		}
		return (1);
	}
	return (1);
}

static int	get_min(t_node *head, int *i)
{
	int	j;
	int	min;

	j = 2;
	*i = 1;
	min = head->value;
	while (head->next)
	{
		if (head->next->value < min)
		{
			*i = j;
			min = head->next->value;
		}
		head = head -> next;
		j++;
	}
	return (min);
}

static void	sort_threeplus_utils(t_node **stack_a)
{
	int		min;
	int		pos;

	min = get_min(*stack_a, &pos);
	if (!check_sorted_list(*stack_a))
	{
		if (pos <= (strlen_lst(*stack_a) / 2) + 1)
			while ((*stack_a)->value != min)
				rotate(stack_a, "ra\n");
		else
			while ((*stack_a)->value != min)
				reverse_rotate(stack_a, "rra\n");
	}
}

static void	sort_threeplus(t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	sort_threeplus_utils(stack_a);
	if (strlen_lst(*stack_a) > 3 && !check_sorted_list(*stack_a))
	{
		push(stack_a, &stack_b, "pb\n");
		if (strlen_lst(*stack_a) != 3)
		{
			sort_threeplus_utils(stack_a);
			if (!check_sorted_list(*stack_a))
				push(stack_a, &stack_b, "pb\n");
		}
	}
	if (strlen_lst(*stack_a) == 3)
		sort_three(stack_a);
	while (strlen_lst(stack_b))
		push(&stack_b, stack_a, "pa\n");
}

void	smaller_sort(t_node **head, int len)
{
	if (len <= 3)
		sort_three(head);
	else
		sort_threeplus(head);
}
