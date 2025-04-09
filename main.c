/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-04 20:42:30 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-04 20:42:30 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setting_view(t_fdf *fdf)
{
	fdf->view.scale = 3.0;
	fdf->view.z_scale = 5.0;
	fdf->view.offset_x = 640;
	fdf->view.offset_y = 360;
	fdf->view.angle_z = 0;
	fdf->view.angle_x = 0;
	fdf->view.angle_y = 0;
	fdf->view.projection_mode = 0;
	fdf->view.map_width = fdf->map->width;
	fdf->view.map_height = fdf->map->height;
	fdf->reset_view = fdf->view;
	return ;
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (1);
	fdf.map = read_map(argv[1]);
	if (!fdf.map)
		return (1);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1280, 720, "FdF");
	fdf.img.img = mlx_new_image(fdf.mlx, 1280, 720);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img,
			&fdf.img.bpp, &fdf.img.line_len, &fdf.img.endian);
	setting_view(&fdf);
	draw_map(fdf.map, &fdf.img, &fdf.view);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
	instructions(&fdf);
	mlx_hook(fdf.win, 2, 1L << 0, handle_key, &fdf);
	mlx_hook(fdf.win, 17, 0, handle_close, &fdf);
	fdf.show_panel = 1;
	mlx_loop(fdf.mlx);
	return (0);
}
