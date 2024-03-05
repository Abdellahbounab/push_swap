/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:55:53 by abounab           #+#    #+#             */
/*   Updated: 2024/03/05 15:55:44 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	words_count(char *str)
{
	int	len;

	len = 0;
	if (*str && (*str != ' ' && *str != '\t' && *str != '\n'))
	{
		len++;
		str++;
	}
	while (*str)
	{
		if (*str && (*str != ' ' && *str != '\t' && *str != '\n')
			&& ((*(str - 1) == ' ') || (*(str - 1) == '\t') 
				|| (*(str - 1) == '\n')))
			len++;
		str++;
	}
	return (len);
}

static int	word_len(char **str)
{
	int	len;

	len = 0;
	while (**str == ' ' || **str == '\t' || **str == '\n')
		(*str)++;
	while (**str && **str != ' ' && **str != '\t' && **str != '\n')
	{
		(*str)++;
		len++;
	}
	return (len);
}

char	**ft_split_space(char *str, int **len)
{
	char	**arr;
	int		i;

	i = 0;
	**len = words_count(str);
	if (**len)
	{
		arr = (char **) malloc (sizeof(char *) * (**len + 1));
		if (!arr)
			return (NULL);
		while (*str && i < **len)
		{
			while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
				str++;
			if (*str)
			{
				*(arr + i) = ft_strdups(str, word_len(&str));
				if (!*(arr + i))
					return (free_arr(arr, i), NULL);
				i++;
			}
		}
		return (*(arr + i) = 0, arr);
	}
	return (0);
}

char	*ft_strdups(char *str, int len)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = (char *) malloc (sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		*(cpy + i) = *(str + i);
		i++;
	}
	*(cpy + i) = 0;
	return (cpy);
}
