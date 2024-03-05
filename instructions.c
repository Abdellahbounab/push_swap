/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:50:10 by abounab           #+#    #+#             */
/*   Updated: 2024/02/23 22:18:33 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_node **stack_a, t_node **stack_b, char *stack)
{
	if (rotate(stack_a, stack) && rotate(stack_b, NULL))
		return (1);
	return (0);
}

int	reverse_rotate(t_node **lst, char *stack)
{
	t_node	*cpy;
	int		len;

	len = strlen_lst(*lst);
	if (*lst && len >= 2)
	{
		cpy = create_t_node(get_t_node(lst, len)->value);
		cpy->index = get_t_node(lst, len)->index;
		delete_t_node(lst, len - 1);
		add_t_node(lst, cpy, 0);
		if (stack)
			write (1, stack, 4);
		return (1);
	}
	return (0);
}

int	rotate(t_node **lst, char *stack)
{
	t_node	*cpy;
	int		len;

	len = strlen_lst(*lst);
	if (*lst && len >= 2)
	{
		cpy = create_t_node((*lst)->value);
		cpy->index = (*lst)->index;
		delete_t_node(lst, 0);
		add_t_node(lst, cpy, len - 1);
		if (stack)
			write (1, stack, 3);
		return (1);
	}
	return (0);
}

int	swap(t_node **lst, char *stack)
{
	t_node	*cpy;
	int		len;

	len = strlen_lst(*lst);
	if (*lst && len >= 2)
	{
		cpy = create_t_node((*lst)->next->value);
		delete_t_node(lst, 1);
		add_t_node(lst, cpy, 0);
		if (stack)
			write (1, stack, 3);
		return (1);
	}
	return (0);
}

int	push(t_node **lst_from, t_node **lst_to, char *stack)
{
	t_node	*cpy;

	if (*lst_from)
	{
		cpy = create_t_node((*lst_from)->value);
		cpy->index = (*lst_from)->index;
		add_t_node(lst_to, cpy, 0);
		delete_t_node(lst_from, 0);
		if (stack)
			write (1, stack, 3);
		return (1);
	}
	return (0);
}
