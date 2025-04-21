/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnes <agnes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:21:35 by agnesgar          #+#    #+#             */
/*   Updated: 2025/04/13 11:17:13 by agnes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
/*
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
*/
int	get_color(int z)
{
	if (z <= 100)
		return (0x8B3A3A);
	if (z <= 200)
		return (0xE99696);
	if (z <= 300)
		return (0xFADDDD);
	if (z <= 500)
		return (0xEDEDED);
	return (0xFFFFFF);
}
