/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sfunctions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:02:35 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/06/17 11:55:35 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftpush.h"

void	sa(t_list	**a, int ctr)
{
	t_list	*elem1;
	t_list	*elem2;
	int		tmp;

	if (!(*a)->next)
		return ;
	elem1 = *a;
	elem2 = (*a)->next;
	tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = tmp;
	if (ctr == 1)
		write(1, "sa\n", 3);
	else if(ctr == 2)
		write(1,"sb\n", 3);
}

void	sb(t_list	**b)
{
	sa(b, 2);
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 0);
	sa(b, 0);
	write(1,"ss\n", 3);
}
