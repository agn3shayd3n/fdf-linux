/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-04 20:36:47 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-04 20:36:47 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "minilibx/mlx.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**points;
}	t_map;

/*-*- image in buffer *-*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp; // bits per pixel
	int		line_len;
	int		endian;
}	t_data;

/*-*- trigonometry, 3D illusion *-*/

typedef struct s_proj
{
	int	x;
	int	y;
	int	z;
}	t_proj;

/*-*- draw lines, bresenham's algorithm *-*/

typedef struct s_line
{
	int		dx;
	int		dy;
	int		st_x;
	int		st_y;
	int		err;
	int		color;
	t_proj	a;
	t_proj	b;
	t_data	*img;
}	t_line;

/*-*- views and controls *-*/

typedef struct s_view
{
	float	scale;
	float	z_scale;
	float	offset_y;
	float	offset_x;
	float	angle_z;
	float	angle_x;
	float	angle_y;
	int		projection_mode;
	int		map_width;
	int		map_height;
}	t_view;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	*map;
	t_view	view;
	t_view	reset_view;
	int		show_panel;
}	t_fdf;

/*-*- read map *-*/
t_map	*read_map(const char *filename);
int		get_height(const char *filename);
int		get_width(const char *filename);
char	**ft_split(char *s, char c);
int		map_filler(t_map *map, const char *filename);
void	filler_aux(t_point *row, char **split, int y, int width);

/*-*- draw topography *-*/
void	draw_map(t_map *map, t_data *img, t_view *view);
t_proj	project(t_point p, t_view *view);
void	bresenham(t_proj a, t_proj b, t_data *img, int color);
void	bresenham_ii(t_line *line);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_proj a, t_proj b, t_data *img);

/*-*- coloring *-*/
int		get_color(int z);

/*-*- text *-*/
void	instructions(t_fdf *fdf);

/*-*- key hooks *-*/
int		handle_key(int keycode, void *param);
int		handle_close(void *param);

/*-*- utils *-*/
int		ft_atoi(const char *str);

#endif