/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:49:41 by asene             #+#    #+#             */
/*   Updated: 2025/01/18 17:16:51 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	init_dict(t_dict *dict, unsigned int max_size)
{
	dict->size = 0;
	dict->max_nbr_size = 0;
	dict->keys = malloc(sizeof(char **) * max_size);
	dict->values = malloc(sizeof(char **) * max_size);
}

void	kill_dict(t_dict *dict)
{
	int	i;

	i = 0;
	while (i < dict->size)
	{
		free(dict->keys[i]);
		free(dict->values[i]);
		i++;
	}
	free(dict->keys);
	free(dict->values);
}

void	dict_add(t_dict *dict, char *key, char *value)
{
	unsigned int	new_max_nb_size;

	dict->keys[dict->size] = key;
	dict->values[dict->size] = value;
	new_max_nb_size = ft_strlen(key) + 2;
	if (new_max_nb_size > dict->max_nbr_size)
		dict->max_nbr_size = new_max_nb_size;
	dict->size++;
}

char	*dict_get(char *str, t_dict dict)
{
	int	i;

	i = 0;
	while (i < dict.size)
	{
		if (ft_strcmp(dict.keys[i], str) == 0)
			return (dict.values[i]);
		i++;
	}
	return (NULL);
}

char	*dict_get_units(int units, t_dict dict)
{
	int				i;
	unsigned int	u_len;

	if (units <= 1)
		return (NULL);
	i = 0;
	u_len = (units -1) * 3 + 1;
	while (i < dict.size)
	{
		if (ft_strlen(dict.keys[i]) == u_len)
			return (dict.values[i]);
		i++;
	}
	return (NULL);
}
