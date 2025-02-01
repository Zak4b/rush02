/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 01:01:35 by asene             #+#    #+#             */
/*   Updated: 2025/01/18 15:51:08 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	handle_args(int argc, char **argv, char **dict_file, char **number)
{
	if (argc == 3)
	{
		*dict_file = argv[1];
		*number = argv[2];
	}
	else
	{
		*dict_file = DEFAULT_DICT;
		*number = argv[1];
	}
	while (**number == '0' && *(*number + 1))
		(*number)++;
	if (check_number(number))
		return (1);
	ft_putstr_fd("Invalid number\n", 2);
	return (0);
}

int	fill_dict(t_dict *dict, char *dict_file)
{
	int		fd;
	char	*line;

	fd = open(dict_file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Can't open dict file\n", 2), 0);
	init_dict(dict, 120);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (parse_line(line, dict) == 0)
			return (close(fd), get_next_line(fd), free(line), 0);
		free(line);
	}
	close(fd);
	sort_dict(dict);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*dict_file;
	char	*nb;
	t_dict	dict;


	if (argc == 1 || argc > 3)
	{
		ft_fprintf(2, "Usage: %s [dict_file] number\n", argv[0]);
		return (2);
	}
	if (!handle_args(argc, argv, &dict_file, &nb))
		return (1);
	if (!fill_dict(&dict, dict_file))
		return (1);
	putnbr_string(nb, dict);
	kill_dict(&dict);
	ft_putchar_fd('\n', 1);
	return (0);
}
