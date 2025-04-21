/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnes <agnes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:49:40 by agnesgar          #+#    #+#             */
/*   Updated: 2025/04/13 14:37:27 by agnes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	handle_close(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	exit(0);
	return (0);
}
