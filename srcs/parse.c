/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:12:42 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/17 11:16:07 by clynderl         ###   ########.fr       */
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

void	ft_count_dims(t_map *map, char *line)
{
	int i;

	i = 0;
	map->cols++;
	if (map->rows == 0)
	{
		while (line[i])
		{
			while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
				i++;
			if (line[i] >= '0' && line[i] <= '9')
				map->rows++;
			while (line[i] && line[i] != ' '
			&& line[i] != '\t' && line[i] != '\n')
				i++;
		}
	}
	free(line);
}

t_map	*ft_parse(char *file)
{
	t_map	*map;
	int		fd;
	int		fd2;
	char	*line;
	int		i;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
		ft_count_dims(map, line);
	if ((fd2 = open(file, O_RDONLY)) < 0 && !close(fd))
		return (NULL);
	if (!(map->tab = (int **)malloc(sizeof(int*) * (map->cols + 1))))
		return (NULL);
	i = 0;
	while (get_next_line(fd2, &line) > 0)
	{
		map->tab[i++] = ft_get_line_values(line, map->rows);
		free(line);
	}
	map->tab[i] = 0;
	close(fd2);
	return (map);
}
