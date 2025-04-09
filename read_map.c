/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-04 20:41:18 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-04 20:41:18 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*read_map(const char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = get_height(filename);
	map->width = get_width(filename);
	if (map->height <= 0 || map->width <= 0)
		return (NULL);
	map->points = malloc(sizeof(t_point) * map->height);
	if (!map->points)
		return (NULL);
	if (map_filler(map, filename) == -1)
		return (NULL);
	return (map);
}

int	map_filler(t_map *map, const char *filename)
{
	int		fd;
	char	*line;
	char	**split;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	y = 0;
	while (y < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->points[y] = malloc(sizeof(t_point) * map->width);
		if (!map->points[y])
			return (-1);
		split = ft_split(line, ' ');
		filler_aux(map->points[y], split, y, map->width);
		free(line);
		free(split);
		y++;
	}
	close(fd);
	return (0);
}

void	filler_aux(t_point *row, char **split, int y, int width)
{
	int		x;

	x = 0;
	while (x < width)
	{
		row[x].x = x;
		row[x].y = y;
		row[x].z = ft_atoi(split[x]);
		row[x].color = -1;
		free(split[x]);
		x++;
	}
}

int	get_height(const char *filename)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(const char *filename)
{
	int		fd;
	int		width;
	char	*line;
	char	**split;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	split = ft_split(line, ' ');
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	free(line);
	close(fd);
	width = i;
	return (width);
}
