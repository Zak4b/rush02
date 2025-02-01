/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:49:33 by asene             #+#    #+#             */
/*   Updated: 2025/01/18 17:04:48 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*parse_key(char **str)
{
	char	*start;
	int		length;

	while (ft_is_space(**str))
		(*str)++;
	start = *str;
	while (ft_isdigit(**str))
		(*str)++;
	length = *str - start;
	if (length == 0)
		return (NULL);
	return (ft_substr(start, 0, length));
}

int	skip_separator(char	**str)
{
	int	i;

	i = 0;
	while (ft_is_space((*str)[i]))
		i++;
	if ((*str)[i++] != ':')
		return (0);
	while (ft_is_space((*str)[i]))
		i++;
	*str = &(*str)[i];
	return (1);
}

char	*parse_value(char **str)
{
	char	*value_string;
	char	*start;
	int		length;

	start = *str;
	while (**str != '\0')
		(*str)++;
	length = *str - start;
	if (length == 0)
		return (NULL);
	value_string = ft_strdup(start);
	return (value_string);
}

void	trim_value(char **value)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while ((*value)[i++])
	{
		i++;
		len++;
	}
}

int	parse_line(char *line, t_dict *dict)
{
	char	*key;
	char	*value;
	char	*tmp;

	key = parse_key(&line);
	if (skip_separator(&line) == 0)
	{
		ft_putstr_fd("Dict Error. Invalid Format\n", 2);
		return (free(key), 0);
	}
	value = parse_value(&line);
	if (!key || !value || check_key(key) == 0)
	{
		ft_putstr_fd("Dict Error. Error during parsing\n", 2);
		return (free(key), free(value), 0);
	}
	tmp = value;
	value = ft_strtrim(value, " \t\n");
	free(tmp);
	ft_reduce_spaces(value); // split to string
	dict_add(dict, key, value);
	return (1);
}
