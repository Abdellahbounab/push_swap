/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounab <abounab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:35:26 by abounab           #+#    #+#             */
/*   Updated: 2024/03/05 17:05:04 by abounab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

t_node		*create_t_node(int num);
void		add_t_node(t_node **lst, t_node *newone, int index);
void		delete_t_node(t_node **lst, int index);
t_node		*get_t_node(t_node	**lst, int index);

void		read_list(t_node *head);

void		free_t_node(t_node **head);
void		ft_errno(void);
void		free_arr(char **arr, int len);

void		cpy_index(t_node **head, t_node *cpy);
t_node		*ft_sorted_cpy(t_node *head);

void		stack_sort(int *stack, int len);
int			push(t_node **lst_from, t_node **lst_to, char *stack);
int			swap(t_node	**lst, char *stack);
int			rotate(t_node	**lst, char *stack);
int			rr(t_node **stack_a, t_node **stack_b, char *stack);
int			reverse_rotate(t_node	**lst, char *stack);

int			*int_split(char	*str, int *len);
int			*get_arr(char **args, int len);
int			next_move(int i, int where, int val);

char		**ft_split_space(char *str, int **len);
char		*ft_strdups(char *str, int len);

char		*ft_join_args(char **arg, int argc);
int			ft_strlen(char *str);

void		second_algo(t_node **stack_a, t_node **stack_b);
void		larger_sort(t_node **head);

void		smaller_sort(t_node **head, int len);

long long	ft_itoa(char *str);
int			ft_strncmp(char *str, char *cmp, int len);
int			check_sorted_list(t_node *head);
int			strlen_lst(t_node *lst);
int			rangeof(int len);

#endif