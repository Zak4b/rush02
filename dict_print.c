/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:49:37 by asene             #+#    #+#             */
/*   Updated: 2025/01/18 15:49:37 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_hundreds(char	*num_str, t_dict dict)
{
	if (ft_strcmp(num_str, "000") == 0)
		return ;
	if (num_str[0] == 1)
		ft_putstr_fd(dict_get("1", dict), 1);
	else
		ft_putstr_fd(dict_get((char []){num_str[0], 0}, dict), 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(dict_get("100", dict), 1);
	if (num_str[1] != '0' || num_str[2] != '0')
	{
		ft_putchar_fd(' ', 1);
		if (num_str[1] != '0')
			print_number(num_str + 1, dict);
		else if (num_str[2] != '0')
			print_number(num_str + 2, dict);
	}
}

void	print_number(char *num_str, t_dict dict)
{
	int			num_len;

	num_len = ft_strlen(num_str);
	if (num_len == 1)
		return (ft_putstr_fd(dict_get(num_str, dict), 1));
	else if (num_len == 3)
		return (print_hundreds(num_str, dict), (void)0);
	if (num_str[0] == '1')
		return (ft_putstr_fd(dict_get(num_str, dict), 1));
	ft_putstr_fd(dict_get((char []){num_str[0], '0', 0}, dict), 1);
	if (num_str[1] != '0')
	{
		ft_putchar_fd(' ', 1);
		ft_putstr_fd(dict_get(num_str +1, dict), 2);
	}
}

void	print_units(int units, t_dict dict)
{
	char	*str;

	str = dict_get_units(units, dict);
	if (!str)
		return ;
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
}
