/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunks_utils_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:24:40 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/06/17 12:43:41 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftpush.h"

int	b_to_a_rb(t_list **a, t_list **b, int num, int check)
{
	while ((*b)->ord != num)
	{
		if ((*b)->ord == num - 1)
		{
			pa(a, b, 1);
			check = 1;
		}
		if ((*b)->ord == num)
			break ;
		rb(b, 2);
	}
	return (check);
}

int	b_to_a_rrb(t_list **a, t_list **b, int num, int check)
{
	while ((*b)->ord != num)
	{
		if ((*b)->ord == num - 1)
		{
			pa(a, b, 1);
			check = 1;
		}
		if ((*b)->ord == num)
			break ;
		rrb(b, 2);
	}
	return (check);
}

int	where_is_num(t_list **lst, int num, int tpa)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->ord == num)
			break ;
		tpa++;
		tmp = tmp->next;
	}
	return (tpa);
}