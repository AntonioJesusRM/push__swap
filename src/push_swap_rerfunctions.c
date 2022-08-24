/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rerfunctions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:47:22 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/06/17 10:20:20 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftpush.h"

void	rra(t_list **a, int ctr)
{
	t_list	*last_a;
	t_list	*first_a;
	t_list	*tmp;

	last_a = *a;
	first_a = *a;
	tmp = *a;
	if (!(*a)->next)
		return ;
	while (last_a->next)
		last_a = last_a->next;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	last_a->next = first_a;
	*a = last_a;
	tmp->next = NULL;
	if (ctr == 1)
		write(1, "rra\n", 4);
	else if (ctr == 2)
		write(1, "rrb\n", 4);
}

void	rrb(t_list **b, int ctr)
{
	rra(b, ctr);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
