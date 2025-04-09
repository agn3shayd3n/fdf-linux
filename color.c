/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-06 11:21:35 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-06 11:21:35 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z)
{
	if (z <= 0)
		return (0x8B3A3A);
	if (z <= 40)
		return (0xE99696);
	if (z <= 80)
		return (0xFADDDD);
	if (z <= 100)
		return (0xEDEDED);
	return (0xFFFFFF);
}

/* only for cyber02
int	get_color(int z)
{
	if (z <= 100)
		return (0x8B3A3A); // rosa salmón pastel
	if (z <= 200)
		return (0xE99696); // rosa más claro
	if (z <= 300)
		return (0xFADDDD); // rosa suave
	if (z <= 500)
		return (0xEDEDED); // grisáceo suave
	return (0xFFFFFF);     // blanco
}
*/