/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:39:21 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/08/24 11:23:40 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftpush.h"

static int	is_int(const char *str)
{
	int		cont;
	long	num;
	int		sig;

	num = 0;
	sig = 1;
	cont = 0;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			sig = sig * (-1);
		cont++;
	}
	while (str[cont] != '\0')
	{
		num = (num * 10) + (str[cont] - '0');
		cont++;
	}
	if (num > -2147483647 && num < 2147483647)
		return (1);
	else
		return (0);
}

static int	is_number_int(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || (i == 0 && str[i] == '-'))
			i++;
		else
			return (0);
	}
	if (!is_int(str))
		return (0);
	return (1);
}

static int	duplicate_num(int argc, char **argv)
{
	int	i;
	int	j;
	int	*arnub;

	arnub = (int *) malloc (sizeof(int) * argc);
	if (!arnub)
		return (0);
	i = -1;
	while (++i < argc)
		arnub[i] = ft_atoi(argv[i]);
	i = -1;
	while (++i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (arnub[i] == arnub[j++])
				return (0);
		}
	}
	free (arnub);
	return (1);
}

char	**its_split(int *argc, char **argv)
{
	int	i;

	i = 0;
	if (*argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = leng(*argc, argv);
	}
	else
	{
		while (i < *argc)
		{
			if (argv[i + 1])
				argv[i] = argv[i + 1];
			else
				argv[i] = "\0";
			i++;
		}
		i--;
	}
	*argc = i;
	return (argv);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**arg;

	if (argc < 3)
		return (0);
	arg = its_split(&argc, argv);
	i = 0;
	while (i < argc)
	{
		if (is_number_int(arg[i]) > 0)
			i++;
		else
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	if (duplicate_num(argc, arg) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_push_swap(argc, arg);
}
