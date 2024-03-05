/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:27:46 by abounab           #+#    #+#             */
/*   Updated: 2024/03/05 19:12:39 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_case(char *argv, int **stack)
{
	int	len;

	len = 0;
	*stack = int_split(argv, &len);
	if (*stack)
		stack_sort(*stack, len);
	else
		ft_errno();
}

int	main(int argc,	char **argv)
{
	int	*stack;

	stack = NULL;
	if (argc > 1)
	{
		argv[1] = ft_join_args(argv, argc);
		if (!argv[1])
			ft_errno();
		else
			first_case(argv[1], &stack);
		if (stack)
			free(stack);
	}
}

//python3 -m push_swap_gui
//export MallocStackLogging=1