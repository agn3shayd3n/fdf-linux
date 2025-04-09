/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-05 12:00:53 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-05 12:00:53 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_proj a, t_proj b, t_data *img)
{
	int	color;

	color = get_color(a.z);
	bresenham(a, b, img, color);
}

void	draw_map(t_map *map, t_data *img, t_view *view)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width -1)
				draw_line(
					project(map->points[y][x], view),
					project(map->points[y][x + 1], view),
					img);
			if (y < map->height - 1)
				draw_line(
					project(map->points[y][x], view),
					project(map->points[y + 1][x], view),
					img);
			x++;
		}
		y++;
	}
}
