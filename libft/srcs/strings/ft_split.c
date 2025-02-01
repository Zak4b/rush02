/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:20 by asene             #+#    #+#             */
/*   Updated: 2024/12/25 20:53:08 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	count_word(char const *str, char c)
{
	int	wc;

	wc = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			wc++;
		while (*str && *str != c)
			str++;
	}
	return (wc);
}

char	**ft_split(char const *str, char c)
{
	char	*start;
	int		k;
	char	**array;

	array = malloc(sizeof(char *) * (count_word(str, c) + 1));
	if (array == NULL)
		return (NULL);
	k = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		start = (char *)str;
		while (*str && *str != c)
			str++;
		if (str > start)
		{
			array[k] = ft_strndup(start, str - start);
			if (array[k++] == NULL)
				return (free_split(array), NULL);
		}
	}
	array[k] = NULL;
	return (array);
}
