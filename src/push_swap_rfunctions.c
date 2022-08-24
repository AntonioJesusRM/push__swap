/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rfunctions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:11:56 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/06/17 10:23:48 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftpush.h"

void	ra(t_list **a, int ctr)
{
	t_list	*first_a;

	if (!(*a))
		return ;
	first_a = *a;
	*a = (*a)->next;
	first_a->next = NULL;
	ft_lstadd_back(a, first_a);
	if (ctr == 1)
		write(1, "ra\n", 3);
	else if (ctr == 2)
		write(1, "rb\n", 3);
}

void	rb(t_list **b, int ctr)
{
	ra(b, ctr);
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 0);
	ra(b, 0);
	write(1, "rr\n", 3);
}
