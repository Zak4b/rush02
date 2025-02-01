#include "rush02.h"

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_dict(t_dict *dict)
{
	int	i;
	int	j;

	i = 0;
	while (i < dict->size - 1)
	{
		j = 0;
		while (j < dict->size - i - 1)
		{
			if (ft_strlen(dict->keys[j]) > ft_strlen(dict->keys[j])
				|| ft_strcmp(dict->keys[j], dict->keys[j + 1]) > 0)
			{
				ft_swap(&dict->keys[j], &dict->keys[j + 1]);
				ft_swap(&dict->values[j], &dict->values[j + 1]);
			}
			j++;
		}
		i++;
	}
}
