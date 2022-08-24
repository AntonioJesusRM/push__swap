/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_over_five.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:47:16 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/06/17 12:43:03 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftpush.h"

void	sort_less_ten(t_list **a, t_list **b)
{
	t_chunk	ck;

	ck = (t_chunk){0, 0, 0, ft_lstsize(*a), ft_lstsize(*b)};
	while (ck.order < ck.size_a - 1)
	{
		if ((*a)->ord == ck.order)
		{
			pb(a, b);
			ck.order++;
		}
		ra(a, 1);
	}
	ck.size_b = ft_lstsize(*b);
	while (ck.size_b > 0)
	{
		if ((*b)->ord == ck.size_b - 1)
		{
			pa(a, b, 0);
			ck.size_b--;
		}
		if (*b)
			rb(b, 2);
	}
}

void	sort_chunks(t_list **a, t_list **b)
{
	sort_chunks_a_to_b(a, b, ft_lstsize(*a));
	sort_five(a, b);
	sort_chunks_b_to_a(a, b);
}

void	sort_big_chunks(t_list **a, t_list **b, int m)
{
	t_chunk	ck;
	t_list	*tmp;

	ck = (t_chunk){0, -1, 0, m / 10 + 22, 39};
	while (++ck.order < m)
	{
		tmp = *a;
		if (ck.order == ck.size_a)
			ck.size_a += ck.size_b;
		while ((*a)->ord > ck.size_a)
			ra(a, 1);
		if ((*a)->ord <= ck.size_a)
			pb(a, b);
	}
	sort_big_chunks_b_to_a(a, b);
}
