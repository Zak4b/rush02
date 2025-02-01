/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:50:08 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 01:56:17 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_number(char **num_str)
{
	int	i;

	i = 0;
	while (ft_isdigit((*num_str)[i]))
		i++;
	if ((*num_str)[i] != '\0')
		return (0);
	return (1);
}

int	check_key(char *key)
{
	int	len;
	int	val;

	len = ft_strlen(key);
	if (len <= 2)
	{
		val = ft_atoi(key);
		if (val < 20)
			return (1);
		else
			return (val % 10 == 0);
	}
	else if (*(key++) != '1')
		return (0);
	while (*key && *key == '0')
		key++;
	return (*key == '\0');
}

/**
 * This function reduces multiple spaces in a string to a single space.
 * It also trims leading and trailing spaces.
 */
void	ft_reduce_spaces(char *str)
{
	int	i;
	int	j;
	int	space_found;

	i = 0;
	j = 0;
	space_found = 0;
	while (str[i] != '\0')
	{
		if (!space_found && ft_is_space(str[i]))
		{
			str[j++] = ' ';
			space_found = 1;
		}
		else if (!ft_is_space(str[i]))
		{
			str[j++] = str[i];
			space_found = 0;
		}
		i++;
	}
	str[j] = '\0';
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
