/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:43:58 by abounab           #+#    #+#             */
/*   Updated: 2024/03/05 19:11:26 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_values(t_node **from, t_node **to)
{
	int	val;

	val = (*to)->value;
	(*to)->value = (*from)->value;
	(*from)->value = val;
}

static void	bubble_sort(t_node **head)
{
	t_node	*cpy2;

	cpy2 = *head;
	while (cpy2->next)
	{
		if (cpy2->value > cpy2->next->value)
		{
			swap_values(&cpy2, &(cpy2->next));
			cpy2 = *head;
		}
		else
			cpy2 = cpy2->next;
	}
}

void	cpy_index(t_node **head, t_node *cpy)
{
	t_node	*tmp;
	t_node	*saver;

	tmp = *head;
	saver = cpy;
	while (tmp)
	{
		cpy = saver;
		while (cpy)
		{
			if (tmp->value == cpy->value)
				tmp->index = cpy->index;
			cpy = cpy->next;
		}
		tmp = tmp->next;
	}
}

t_node	*ft_sorted_cpy(t_node *head)
{
	int		i;
	t_node	*cpy;
	t_node	*cpy2;

	i = 0;
	cpy = NULL;
	while (head)
	{
		cpy2 = create_t_node(head->value);
		if (!cpy2)
			return (free(cpy), NULL);
		cpy2->index = i;
		add_t_node(&cpy, cpy2, i++);
		head = head->next;
	}
	cpy2 = cpy;
	bubble_sort(&cpy);
	return (cpy);
}
