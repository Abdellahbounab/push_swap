/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:58:32 by abounab           #+#    #+#             */
/*   Updated: 2024/03/05 19:12:10 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	total_len;

	if (!s1)
		return (ft_strdups(s2, ft_strlen(s2)));
	if (s2 && s1)
	{
		total_len = ft_strlen(s1) + ft_strlen(s2);
		joined = (char *) malloc(sizeof(char) * (total_len + 2));
		if (!joined)
			return (ft_errno(), NULL);
		while (*s1)
			*(joined++) = *(s1++);
		*(joined++) = ' ';
		while (*s2)
			*(joined++) = *(s2++);
		*(joined) = 0;
		return (joined - (total_len + 1));
	}
	return (ft_errno(), NULL);
}

int	not_empty(char *str)
{
	if (!*str)
		return (1);
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_join_args(char **arg, int argc)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 1;
	str = NULL;
	while (i < argc)
	{
		tmp = str;
		if (*arg[i] && not_empty(arg[i]))
		{
			str = ft_strjoin(str, arg[i]);
			free(tmp);
			if (!str)
				return (ft_errno(), NULL);
		}
		else
			return (free(str), ft_errno(), NULL);
		i++;
	}
	return (str);
}

void	stack_sort(int *stack, int len)
{
	t_node	*head;
	t_node	*cpy;
	int		i;

	i = 0;
	head = create_t_node(stack[i++]);
	while (i < len)
	{
		cpy = create_t_node(stack[i++]);
		add_t_node(&head, cpy, strlen_lst(head));
	}
	if (!check_sorted_list(head))
	{
		if (len <= 5)
			smaller_sort(&head, len);
		else
			larger_sort(&head);
	}
	free_t_node(&head);
}
