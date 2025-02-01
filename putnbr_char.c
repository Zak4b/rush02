#include "rush02.h"

char	*trim_zero(char	*num_str)
{
	unsigned int	i;

	i = 0;
	while (num_str[i] == '0')
		i++;
	if (ft_strlen(num_str) == i)
		return (num_str);
	return (num_str + i);
}

// Cut a number string into 3-char parts
char	**cut_num(char *num_str, int *size)
{
	int		num_len;
	int		num_parts;
	int		i;
	char	**res;

	num_len = ft_strlen(num_str);
	num_parts = num_len / 3 + (num_len % 3 != 0);
	if (size)
		*size = num_parts;
	res = ft_calloc(num_parts + 1, sizeof(char *));
	i = 0;
	if (num_len % 3 != 0)
	{
		res[i++] = ft_substr(num_str, 0, num_len % 3);
		num_str += num_len % 3;
		num_parts--;
	}
	while (num_parts > 0)
	{
		res[i++] = ft_substr(num_str, 0, 3);
		num_str += 3;
		num_parts--;
	}
	return (res);
}

int	putnbr_string(char *num_str, t_dict dict)
{
	char	**num_data;
	int		i;
	int		units;

	num_data = cut_num(num_str, &units);
	if (ft_strlen(num_str) > dict.max_nbr_size)
		return (ft_putstr_fd("Dict error. Number is too big", 2), 0);
	i = 0;
	while (i < units)
	{
		if (i > 0 && ft_strcmp(num_data[i], "000") != 0)
			ft_putstr_fd(" ", 1);
		print_number(trim_zero(num_data[i]), dict);
		print_units(units - i, dict);
		i++;
	}
	free_split(num_data);
	return (1);
}
