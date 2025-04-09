/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_union.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-05 12:22:16 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-05 12:22:16 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_proj a, t_proj b, t_data *img, int color)
{
	t_line	line;

	line.dx = abs(b.x - a.x);
	line.dy = abs(b.y - a.y);
	if (a.x < b.x)
		line.st_x = 1;
	else
		line.st_x = -1;
	if (a.y < b.y)
		line.st_y = 1;
	else
		line.st_y = -1;
	line.err = line.dx - line.dy;
	line.color = color;
	line.a = a;
	line.b = b;
	line.img = img;
	bresenham_ii(&line);
}

void	bresenham_ii(t_line *line)
{
	int	e2;

	while (line->a.x != line->b.x || line->a.y != line->b.y)
	{
		my_mlx_pixel_put(line->img, line->a.x, line->a.y, line->color);
		e2 = 2 * line->err;
		if (e2 > -line->dy)
		{
			line->err -= line->dy;
			line->a.x += line->st_x;
		}
		if (e2 < line->dx)
		{
			line->err += line->dx;
			line->a.y += line->st_y;
		}
	}
}
