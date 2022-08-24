/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftpush.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:54:03 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/06/17 12:45:28 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPUSH_H
# define LIBFTPUSH_H
# include "../libft/libft.h"

typedef struct s_chunks
{
	int	tpa;
	int	order;
	int	check;
	int	size_a;
	int	size_b;
}	t_chunk;

void		init_push_swap(int argc, char **arg);
void		display_screen(t_list **lst_a);
void		sa(t_list	**a, int ctr);
void		sb(t_list	**b);
void		ss(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b, int ctr);
void		pb(t_list **a, t_list **b);
void		ra(t_list **a, int ctr);
void		rb(t_list **b, int ctr);
void		rr(t_list **a, t_list **b);
void		rra(t_list **a, int ctr);
void		rrb(t_list **b, int ctr);
void		rrr(t_list **a, t_list **b);
int			sorted(t_list **a);
void		sort_two(t_list **a);
void		sort_three(t_list **a);
void		sort_four(t_list **a, t_list **b);
void		push_swap_sort(t_list **a);
void		sort_five(t_list **a, t_list **b);
void		two_min(int *array, t_list *tmp);
void		condition_five_pos(int *array, t_list **a, t_list **b);
int			leng(int argc, char **argv);
void		sort_less_ten(t_list **a, t_list **b);
int			*maping(int argc, char **argv);
void		sort_array(int argc, char **argv, char **rtn);
void		cpyptrptr(char **rtn, char **argv, int argc);
void		sort_chunks(t_list **a, t_list **b);
void		sort_chunks_a_to_b(t_list **a, t_list **b, int m);
void		sort_chunks_b_to_a(t_list **a, t_list **b);
int			b_to_a_rb(t_list **a, t_list **b, int num, int check);
int			b_to_a_rrb(t_list **a, t_list **b, int num, int check);
int			where_is_num(t_list **lst, int num, int tpa);
void		sort_chunks_rotate_list_a(t_list **a, int max, int tpa, int chunk);
void		sort_big_chunks(t_list **a, t_list **b, int m);
void		sort_big_chunks_b_to_a(t_list **a, t_list **b);
#endif