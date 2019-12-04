/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:12:42 by clynderl          #+#    #+#             */
/*   Updated: 2019/12/04 17:34:59 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*ft_get_line_values(char *line, int rows)
{
	int		*tab;
	int		i;
	int		pos;

	if (!(tab = (int*)malloc(sizeof(int) * rows)))
		return (NULL);
	i = 0;
	pos = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		if (line[i] >= '0' && line[i] <= '9')
		{
			tab[pos] = ft_atoi(&line[i]);
			pos++;
		}
		while (line[i] && line[i] != ' '
			&& line[i] != '\t' && line[i] != '\n')
			i++;
	}
	return (tab);
}

int		ft_col_val(t_map *map, char *line, int c)
{
	int	i;
	int	pos;

	if (!(map->colors[c] = (int*)malloc(sizeof(int) * map->rows)))
		return (0);
	i = 0;
	pos = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		if (line[i] >= '0' && line[i] <= '9')
		{
			map->colors[c][pos] = 0;
			pos++;
		}
		while (line[i] && line[i] != ' '
			&& line[i] != '\t' && line[i] != '\n')
		{
			i++;
			if (line[i] == ',')
				map->colors[c][pos - 1] = ft_atoi_base(&line[i + 1], 16);
		}
	}
	return (1);
}

void	ft_count_dims(t_map *map, char *line)
{
	int i;
	int rows;

	i = 0;
	map->cols++;
	rows = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		if (line[i] >= '0' && line[i] <= '9')
			rows++;
		while (line[i] && line[i] != ' '
		&& line[i] != '\t' && line[i] != '\n')
			i++;
	}
	if (map->rows == 0 || map->rows == rows)
		map->rows = rows;
	else
	{
		ft_putendl("Invalid size");
		exit(0);
	}
	free(line);
}

t_map	*ft_parse(char *file)
{
	t_map	*map;
	int		fd;
	char	*line;
	int		i;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
		ft_count_dims(map, line);
	if (!close(fd) && (fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	if (!(map->tab = (int **)malloc(sizeof(int*) * (map->cols + 1)))
		|| !(map->colors = (int **)malloc(sizeof(int*) * (map->cols + 1))))
		return (NULL);
	i = 0;
	while (get_next_line(fd, &line) > 0 && ft_col_val(map, line, i))
	{
		map->tab[i++] = ft_get_line_values(line, map->rows);
		free(line);
	}
	map->tab[i] = 0;
	close(fd);
	return (map);
}
