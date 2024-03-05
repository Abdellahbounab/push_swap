/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:48:21 by abounab           #+#    #+#             */
/*   Updated: 2024/03/05 17:14:43 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rangeof(int len)
{
	if (len < 20)
		return (3);
	return (len / 20 + 10);
}

int	strlen_lst(t_node *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

int	check_sorted_list(t_node *head)
{
	int		len;
	t_node	*cpy;

	len = strlen_lst(head);
	cpy = head;
	while (--len && cpy->next)
	{
		if (cpy->value >= cpy->next->value)
			return (0);
		cpy = cpy->next;
	}
	return (1);
}

int	ft_strncmp(char *str, char *cmp, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] != cmp[i])
			return (0);
		i++;
	}
	if (!(str[i] - cmp[i]))
		return (1);
	return (0);
}

long long	ft_itoa(char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!*str)
			return (-1);
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (num * sign < -2147483648 || num * sign > 2147483647)
		return (-1);
	return (num * sign);
}
