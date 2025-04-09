/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-09 10:13:30 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-09 10:13:30 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	instructions(t_fdf *fdf)
{
	int		i;
	char	*lines[10];

	lines[0] = "--- CONTROLES ---";
	lines[1] = "Z/X: Zoom";
	lines[2] = "Flechas: Mover mapa";
	lines[3] = "W/S: Rotar eje Y";
	lines[4] = "Q/E: Rotar eje X";
	lines[5] = "R/L: Rotar eje Z";
	lines[6] = "B: Cambiar proyeccion";
	lines[7] = "Backspace: Resetear vista";
	lines[8] = "H: Ocultar controles";
	lines[9] = NULL;
	i = 0;
	if (!fdf->show_panel)
		return ;
	while (lines[i])
	{
		mlx_string_put(fdf->mlx, fdf->win, 15, 20 + i * 20, 0xCCCCCC, lines[i]);
		i++;
	}
}
