/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:11:52 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/06/17 12:39:15 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftpush.h"

int	leng(int argc, char **argv)
{
	argc = 0;
	while (*argv)
	{
		argc++;
		argv++;
	}
	return (argc);
}

int	sorted(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->next && tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	two_min(int *array, t_list *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (array [2] > tmp->content)
		{
			array [3] = array [2];
			array [1] = array [0];
			array [2] = tmp->content;
			array [0] = i;
		}
		else if (array[3] > tmp->content && array[2] != tmp->content)
		{
			array [3] = tmp->content;
			array [1] = i;
		}
		tmp = tmp->next;
		i++;
	}
}

void	condition_five_pos(int *array, t_list **a, t_list **b)
{
	if (array[0] <= 2)
		while ((*a)->content != array[2])
			ra(a, 1);
	else
		while ((*a)->content != array[2])
			rra(a, 1);
	pb(a, b);
	if (array[1] <= 2)
		while ((*a)->content != array[3])
			ra(a, 1);
	else
		while ((*a)->content != array[3])
			rra(a, 1);
	pb(a, b);
	sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}

void	display_screen(t_list **lst_a)
{
	t_list	*tmp;

	tmp = *lst_a;
	printf("numb: ");
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
}
