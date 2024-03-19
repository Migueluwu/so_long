/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:22:05 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/19 19:35:15 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file)
{
	int		i;
	int		fd;
	char	*aux;
	int		is_line;

	is_line = 1;
	aux = ".";
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error();
	aux = get_next_line(fd);
	while (aux)
	{
		aux = NULL;
		aux = get_next_line(fd);
		i++;
	}
	free(aux);
	close(fd);
	if (i < 3)
		error();
	return (i);
}

char	**fill_map(char *file, int lines)
{
	char	**map;
	int		fd;
	int		line;

	line = 0;
	map = ft_calloc((lines + 1), sizeof (char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error();
	map[line] = get_next_line(fd);
	if (!map[line++])
		error();
	while (line < lines)
	{
		map[line] = NULL;
		map[line] = get_next_line(fd);
		if (!map[line])
			error();
		line++;
	}
	close(fd);
	return (map);
}

char	**read_and_check(char *file, t_map	*t_map)
{
	char	**map;
	int		lines;

	t_map->rows = count_lines(file);
	map = fill_map(file, t_map->rows);
	t_map->columns = is_rectangle(map);
	if (t_map->columns >= 3 && t_map->rows >= 3
		&& have_wall(map, t_map->rows, t_map->columns) && have_coins(map)
		&& have_exit_and_spawn(map) && !have_wrong_char(map)
		&& fill_flood(copy_map(map, t_map->rows)))
	{
		return (map);
	}
	else
	{
		free_map(map);
		error();
	}
	return (map);
}
