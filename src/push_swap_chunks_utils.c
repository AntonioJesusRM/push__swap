/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunks_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:14:11 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/06/17 12:57:26 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftpush.h"

void	sort_chunks_a_to_b(t_list **a, t_list **b, int m)
{
	t_chunk	ck;	
	t_list	*tmp;

	ck = (t_chunk){0, 0, 0, m / 13 + 17, (m / 13 + 21) / 2};
	if (ck.size_a % 2 == 0)
		ck.size_a++;
	while (ck.order < m - 5)
	{
		ck.order = m - ft_lstsize(*a);
		ck.tpa = 0;
		tmp = *a;
		while (tmp)
		{
			if (tmp->ord <= ck.size_a && tmp->ord < m - 5)
				break ;
			ck.tpa++;
			tmp = tmp->next;
		}
		if (ck.order == ck.size_a)
			ck.size_a += ck.size_b;
		sort_chunks_rotate_list_a(a, m, ck.tpa, ck.size_a);
		if ((*a)->ord < m - 5)
			pb(a, b);
	}
}

void	sort_chunks_b_to_a(t_list **a, t_list **b)
{
	t_chunk	ck;	

	ck = (t_chunk){0, 0, 0, 0, 0};
	ck.size_b = ft_lstsize(*b);
	ck.order = ck.size_b;
	while (--ck.order > -1)
	{
		ck.tpa = 0;
		ck.tpa = where_is_num(b, ck.order, ck.tpa);
		if (ck.tpa <= ck.order / 2)
			ck.check = b_to_a_rb(a, b, ck.order, ck.check);
		else
			ck.check = b_to_a_rrb(a, b, ck.order, ck.check);
		pa(a, b, 1);
		if (ck.check == 1)
		{
			sa(a, 1);
			ck.check = 0;
			ck.order--;
		}
	}
}

void	sort_chunks_rotate_list_a(t_list **a, int max, int tpa, int chunk)
{
	if (tpa <= (max / 2))
		while (tpa > 0 && tpa--)
			ra(a, 1);
	else
	{
		while (max - tpa > 0 && tpa--)
		{
			if ((*a)->ord <= chunk)
				break ;
			rra(a, 1);
		}
	}
}

void	sort_big_chunks_b_to_a(t_list **a, t_list **b)
{
	t_chunk	ck;

	ck = (t_chunk){0, ft_lstsize(*b), 0, 0, 0};
	while (--ck.order > -1)
	{
		ck.tpa = 0;
		ck.tpa = where_is_num(b, ck.order, ck.tpa);
		if (ck.tpa <= ck.order / 2)
			ck.check = b_to_a_rb(a, b, ck.order, ck.check);
		else
			ck.check = b_to_a_rrb(a, b, ck.order, ck.check);
		pa(a, b, 1);
		if (ck.check == 1)
		{
			sa(a, 1);
			ck.check = 0;
			ck.order--;
		}
	}
}
