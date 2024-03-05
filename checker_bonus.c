/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:25:01 by abounab           #+#    #+#             */
/*   Updated: 2024/03/05 19:14:53 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	first_case(char **argv, int **stack)
{
	int	len;

	len = 0;
	*stack = int_split(*argv, &len);
	free(*argv);
	if (!*stack)
		ft_errno();
	else
	{
		stack_sort2(*stack, &len);
		free(*stack);
	}
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
			first_case(&argv[1], &stack);
		exit (EXIT_SUCCESS);
	}
}
