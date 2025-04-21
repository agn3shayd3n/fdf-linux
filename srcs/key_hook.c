/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnes <agnes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:00:25 by agnesgar          #+#    #+#             */
/*   Updated: 2025/04/13 14:39:18 by agnes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	handle_zoom(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 122)
		fdf->view.scale *= 1.1;
	else if (keycode == 120)
		fdf->view.scale *= 0.9;
	return (0);
}

static int	handle_arrows(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 65361)
		fdf->view.offset_x -= 30;
	else if (keycode == 65363)
		fdf->view.offset_x += 30;
	else if (keycode == 65364)
		fdf->view.offset_y += 30;
	else if (keycode == 65362)
		fdf->view.offset_y -= 30;
	return (0);
}

static int	handle_axis(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 119)
		fdf->view.angle_x += 0.1;
	else if (keycode == 115)
		fdf->view.angle_x -= 0.1;
	else if (keycode == 101)
		fdf->view.angle_y += 0.1;
	else if (keycode == 113)
		fdf->view.angle_y -= 0.1;
	return (0);
}

int	handle_key(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 65307)
		exit(0);
	else if (keycode == 122 || keycode == 120)
		handle_zoom(keycode, param);
	else if (keycode >= 65361 && keycode <= 65364)
		handle_arrows(keycode, param);
	else if (keycode == 108)
		fdf->view.angle_z += 0.1;
	else if (keycode == 114)
		fdf->view.angle_z -= 0.1;
	else if (keycode == 98)
		fdf->view.projection_mode = !fdf->view.projection_mode;
	else if ((keycode == 101) || (keycode >= 113 && keycode <= 119))
		handle_axis(keycode, param);
	else if (keycode == 65288)
		fdf->view = fdf->reset_view;
	else if (keycode == 104)
		fdf->show_panel = !fdf->show_panel;
	create_window(param);
	return (0);
}
