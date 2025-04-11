/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnes <agnes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:33:19 by agnes             #+#    #+#             */
/*   Updated: 2025/04/11 10:36:34 by agnes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_data *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < 1024)
	{
		x = 0;
		while (x < 1280)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

int	create_window(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_clear_window(fdf->mlx, fdf->win);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
	clear_image(&fdf->img, 0x000000);
	draw_map(fdf->map, &fdf->img, &fdf->view);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	instructions(fdf);
	return (0);
}
