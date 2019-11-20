/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 17:04:50 by mnguyen           #+#    #+#             */
/*   Updated: 2015/06/11 20:33:19 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	mlx_put_pixel_to_mini(t_struct *s, int x, int y, int color)
{
	ft_memcpy(&s->img_mini[(x * 4) + (y * s->sz_mini)], &color,
			(sizeof(size_t)));
}

void	put_minimap(t_struct *s)
{
	int		x;
	int		y;

	x = 0;
	while (x < WMINI - 1)
	{
		y = 0;
		while (y < HMINI - 1)
		{
			if (x / 8 == (int)s->y && y / 8 == (int)s->x)
				mlx_put_pixel_to_mini(s, x, y, 0x003300FF);
			else if (s->map[y / 8][x / 8] == 1)
			{
				mlx_put_pixel_to_mini(s, x, y, 0x00000000);
			}
			else if (s->map[y / 8][x / 8] == 2)
				mlx_put_pixel_to_mini(s, x, y, 0x0000FF00);
			else
				mlx_put_pixel_to_mini(s, x, y, 0x77FFFFFF);
			y++;
		}
		x++;
	}
}

void	create_minimap(t_struct *s)
{
	if (!(s->new_mini = mlx_new_image(s->mlx, WMINI, HMINI)))
		coderror('m');
	s->img_mini = mlx_get_data_addr(s->new_mini, &s->bt_mini,
										&s->sz_mini, &s->end_mini);
	if (!(s->img_mini))
		coderror('m');
	put_minimap(s);
}

void	ray5(t_struct *s)
{
	if (s->map[s->mapx][s->mapy] == 2 && s->c)
		s->color = 0x000000;
	else if (s->map[s->mapx][s->mapy] == 2 && !s->c)
		s->color = 0xFFFFFF;
	else if (s->side == 0 && s->raydx >= 0 && s->c)
		s->color = 0xFF3300;
	else if (s->side == 0 && s->raydx >= 0 && !s->c)
		s->color = 0x00CCFF;
	else if (s->side == 0 && s->raydx < 0 && s->c)
		s->color = 0xFFFF00;
	else if (s->side == 0 && s->raydx < 0 && !s->c)
		s->color = 0x0000FF;
	else if (s->side >= 1 && s->raydy >= 0 && s->c)
		s->color = 0x00FF00;
	else if (s->side >= 1 && s->raydy >= 0 && !s->c)
		s->color = 0xFF00FF;
	else if (s->side >= 1 && s->raydy < 0 && s->c)
		s->color = 0xCC66FF;
	else if (s->side >= 1 && s->raydy < 0 && !s->c)
		s->color = 0x339900;
}
