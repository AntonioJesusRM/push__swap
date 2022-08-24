/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sortfunctions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:52:07 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/06/17 12:47:52 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftpush.h"

void	push_swap_sort(t_list **a)
{
	t_list	**b;

	b = (t_list **) malloc (ft_lstsize(*a));
	if (ft_lstsize(*a) == 2)
		sort_two(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	else if (ft_lstsize(*a) > 5 && ft_lstsize(*a) < 10)
		sort_less_ten(a, b);
	else if (ft_lstsize(*a) >= 10 && ft_lstsize(*a) < 500)
		sort_chunks(a, b);
	else if (ft_lstsize(*a) >= 500)
		sort_big_chunks(a, b, ft_lstsize(*a));
	free(b);
}

void	sort_two(t_list **a)
{
	if (sorted(a) != 1)
		sa(a, 1);
}

void	sort_three(t_list **a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	while (sorted(a) != 1)
	{
		if ((*a)->content < tmp->content && (*a)->content > tmp->next->content
			&& (*a)->next->content > (*a)->next->next->content)
		{
			rra(a, 1);
			break ;
		}
		else if ((*a)->content > tmp->content
			&& tmp->content < tmp->next->content
			&& (*a)->content > tmp->next->content)
		{
			ra(a, 1);
			break ;
		}
		else
			sa(a, 1);
	}
}

void	sort_four(t_list **a, t_list **b)
{
	int		min;
	t_list	*tmp;

	tmp = *a;
	min = tmp->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	while ((*a)->content != min)
		ra(a, 1);
	pb(a, b);
	sort_three(a);
	pa(a, b, 1);
}

void	sort_five(t_list **a, t_list **b)
{
	int		*array;
	t_list	*tmp;

	tmp = *a;
	array = (int *) malloc (sizeof(int) * 4);
	array [0] = 0;
	array [1] = 1;
	array [2] = tmp->content;
	array [3] = tmp->next->content;
	two_min(array, tmp);
	condition_five_pos(array, a, b);
	free (array);
}
