/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:52:45 by abounab           #+#    #+#             */
/*   Updated: 2024/03/05 16:11:37 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_move(int i, int where, int val)
{
	if (val >= where + i)
		return (1);
	return (0);
}

static int	not_duplicated(int *arr, int num, int len)
{
	int	iteration;

	iteration = 0;
	if (len == 0)
		return (1);
	while (iteration < len)
	{
		if (num == arr[iteration++])
			return (0);
	}
	return (1);
}

static int	valid_int(char *str, int *num)
{
	int	val;

	val = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (str && *str)
	{
		if (*str >= '0' && *str <= '9')
		{
			val *= 10;
			val += '0' - *str;
		}
		else
			return (0);
		str++;
	}
	*num = val;
	return (1);
}

int	*int_split(char	*str, int *len)
{
	char	**args;
	int		*arr;

	args = ft_split_space(str, &len);
	if (!*len)
		return (exit(EXIT_SUCCESS), NULL);
	if (args)
	{
		arr = get_arr(args, *len);
		if (arr)
			return (free_arr(args, *len), arr);
		return (free_arr(args, *len), NULL);
	}
	return (NULL);
}

int	*get_arr(char **args, int len)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *) malloc (sizeof(int) * len);
	if (!arr)
		return (0);
	while (i < len)
	{
		if (valid_int(args[i], &arr[i]))
		{
			arr[i] = (int)ft_itoa(args[i]);
			if ((arr[i] == -1 && !ft_strncmp(args[i], "-1", 2)) 
				|| !not_duplicated(arr, arr[i], i))
				return (free(arr), ft_errno(), NULL);
			i++;
		}
		else
			return (free(arr), ft_errno(), NULL);
	}
	return (arr);
}
