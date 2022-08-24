/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:36:10 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/06/17 12:46:18 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftpush.h"

void	init_push_swap(int argc, char **argv)
{
	t_list	**a;
	t_list	*new_element;
	int		*ord;
	int		i;

	i = 0;
	a = (t_list **) malloc (sizeof(t_list) * argc);
	if (!a)
		return ;
	ord = maping(argc, argv);
	while (i < argc)
	{
		new_element = ft_lstnew(ft_atoi(argv[i]), ord[i]);
		ft_lstadd_back(a, new_element);
		i++;
	}
	if (sorted(a) != 1)
		push_swap_sort(a);
	free (new_element);
	free (ord);
	free (a);
}

int	*maping(int argc, char **argv)
{
	int			*ord;
	char		**num_sort;
	int			i;
	int			j;

	num_sort = (char **) malloc (sizeof(char *) * argc);
	sort_array(argc, argv, num_sort);
	i = -1;
	ord = (int *) malloc (sizeof(int) * argc);
	while (++i < argc)
	{
		j = 0;
		while (argv[i] != num_sort[j])
			j++;
		ord[i] = j;
	}
	free (num_sort);
	return (ord);
}

void	sort_array(int argc, char **argv, char **rtn)
{
	int		i;
	int		j;
	int		vaux;
	int		min;
	char	*aux;

	i = -1;
	cpyptrptr(rtn, argv, argc);
	while (++i < argc)
	{
		min = ft_atoi(rtn[i]);
		vaux = i;
		j = i;
		while (++j < argc)
		{
			if (ft_atoi(rtn[j]) < min)
			{
				min = ft_atoi(rtn[j]);
				vaux = j;
			}
		}
		aux = rtn[vaux];
		rtn[vaux] = rtn[i];
		rtn[i] = aux;
	}
}

void	cpyptrptr(char **rtn, char **argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		rtn[i] = argv[i];
		i++;
	}
}
