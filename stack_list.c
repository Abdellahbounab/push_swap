/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:35:29 by abounab           #+#    #+#             */
/*   Updated: 2024/02/20 15:21:48 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_t_node(int num)
{
	t_node	*newt_node;

	newt_node = (t_node *) malloc (sizeof(t_node));
	if (!newt_node)
		return (0);
	newt_node->value = num;
	newt_node->next = NULL;
	return (newt_node);
}

void	add_t_node(t_node **lst, t_node *newone, int index)
{
	t_node	*cpy;

	cpy = *lst;
	if (index > 0)
	{
		while (index && --index)
			cpy = cpy->next;
		newone->next = cpy->next;
		cpy->next = newone;
	}
	else if (index == 0 && cpy)
	{
		newone->next = cpy;
		*lst = newone;
	}
	else if (index == 0 && !cpy)
		*lst = newone;
}

void	delete_t_node(t_node **lst, int index)
{
	t_node	*cpy;
	t_node	*save;

	cpy = *lst;
	if (index > 0)
	{
		while (index && --index)
			cpy = cpy->next;
		if (cpy)
		{
			save = cpy->next;
			cpy->next = cpy->next->next;
			free(save);
			save = NULL;
		}
	}
	else if (index == 0)
	{
		save = cpy->next;
		free(cpy);
		*lst = save;
		cpy = NULL;
	}
}

t_node	*get_t_node(t_node **lst, int index)
{
	t_node	*cpy;

	cpy = *lst;
	if (strlen_lst(*lst) >= index)
	{
		while (cpy && --index)
			cpy = cpy->next;
		return (cpy);
	}
	return (0);
}
