/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pfunctions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:02:24 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/06/17 11:57:01 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftpush.h"

void	pa(t_list **a, t_list **b, int ctr)
{
	t_list	*new_element;

	if (!(*b))
		return ;
	new_element = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, new_element);
	if (ctr == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	pa(b, a, 2);
}
