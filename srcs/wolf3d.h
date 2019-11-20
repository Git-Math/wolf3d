/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 16:29:05 by mnguyen           #+#    #+#             */
/*   Updated: 2015/06/11 20:30:07 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <complex.h>
# include <math.h>
# include "../libft/libft.h"

# define UP 125
# define DOWN 126
# define LEFT 123
# define RIGHT 124
# define PLUS 116
# define MINUS 121
# define SPACE	49
# define ESCAPE 53
# define R 15
# define C 8
# define MAPW 1200
# define MAPH 1200
# define BUFF_SIZE 48
# define ROT 69
# define WMINI 192
# define HMINI 192

typedef struct	s_struct
{
	int			**map;
	void		*mlx;
	void		*win;
	void		*img;
	void		*new;
	void		*img_mini;
	void		*new_mini;
	int			bt;
	int			sz;
	int			end;
	int			bt_mini;
	int			sz_mini;
	int			end_mini;
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		px;
	double		py;
	double		camx;
	double		rayx;
	double		rayy;
	double		raydx;
	double		raydy;
	int			mapx;
	int			mapy;
	double		distx;
	double		disty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	double		stepx;
	double		stepy;
	int			hit;
	int			side;
	int			lineh;
	int			drawstart;
	int			drawend;
	int			color;
	int			c;
}				t_struct;

void			moveup(int **map, t_struct *s);
void			movedown(int **map, t_struct *s);
void			moveright(t_struct *s);
void			moveleft(t_struct *s);
int				createfd(int map);
void			remp(int fd, t_struct *s);
void			remp2(char *str, t_struct *s, int k);
int				expose_hook(t_struct *s);
int				key_hook(int keycode, t_struct *s);
void			raycaster(t_struct *s);
void			mlx_put_pixel_to_img(t_struct *s, int x, int y, int color);
void			coderror(char c);
void			draw(int x, t_struct *s);
void			put_minimap(t_struct *s);
void			create_minimap(t_struct *s);
void			mlx_put_pixel_to_mini(t_struct *s, int x, int y, int color);
void			ray1(t_struct *s, int x);
void			ray2(t_struct *s);
void			ray3(t_struct *s);
void			ray4(t_struct *s);
void			ray5(t_struct *s);
void			init_pos(t_struct *s);
void			col(t_struct *s);

#endif
