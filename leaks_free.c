/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:42:54 by abounab           #+#    #+#             */
/*   Updated: 2024/03/05 16:00:23 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_t_node(t_node **head)
{
	int	len;

	len = strlen_lst(*head);
	while (len)
		delete_t_node(head, --len);
	free(*head);
}

void	free_arr(char **arr, int len)
{
	while (len >= 0)
	{
		free(arr[len]);
		arr[len] = NULL;
		len--;
	}
	free(arr);
}

void	ft_errno(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}
