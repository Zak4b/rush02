/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:55:05 by asene             #+#    #+#             */
/*   Updated: 2025/01/18 17:15:59 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define DEFAULT_DICT "numbers.dict"

typedef struct s_entry
{
	char	*key;
	char	*value;
}	t_entry;

typedef struct s_dict
{
	int				size;
	unsigned int	max_nbr_size;
	char			**keys;
	char			**values;
}	t_dict;

int		check_number(char **num_str);
char	**cut_num(char *num_str, int *size);

int		parse_line(char *line, t_dict *dict);
int		check_key(char *key);
void	ft_reduce_spaces(char *str);

void	init_dict(t_dict *dict, unsigned int max_size);
void	dict_add(t_dict *dict, char *key, char *value);
char	*dict_get(char *str, t_dict dict);
char	*dict_get_units(int units, t_dict dict);
void	kill_dict(t_dict *dict);

int		ft_is_space(char c);
void	sort_dict(t_dict *dict);

int		putnbr_string(char *num_str, t_dict dict);

void	print_number(char *num_str, t_dict dict);
void	print_units(int units, t_dict dict);

char	*trim_zero(char *char_3);

int	ft_strcmp(const char *s1, const char *s2);

#endif