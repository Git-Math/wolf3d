/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 18:04:19 by mnguyen           #+#    #+#             */
/*   Updated: 2015/06/11 17:13:46 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycaster(t_struct *s)
{
	int x;

	x = 0;
	while (x < MAPW)
	{
		ray1(s, x);
		ray2(s);
		ray3(s);
		ray4(s);
		ray5(s);
		draw(x, s);
		x++;
	}
}

void	ray1(t_struct *s, int x)
{
	s->camx = 2 * x / (double)MAPW - 1;
	s->rayx = s->x;
	s->rayy = s->y;
	s->raydx = s->dx + s->px * s->camx;
	s->raydy = s->dy + s->py * s->camx;
	s->mapx = (int)s->rayx;
	s->mapy = (int)s->rayy;
	s->deltadistx = sqrt(1 + (s->raydy * s->raydy) / (s->raydx * s->raydx));
	s->deltadisty = sqrt(1 + (s->raydx * s->raydx) / (s->raydy * s->raydy));
	s->hit = 0;
}

void	ray2(t_struct *s)
{
	if (s->raydx < 0)
	{
		s->stepx = -1;
		s->distx = (s->rayx - s->mapx) * s->deltadistx;
	}
	else
	{
		s->stepx = 1;
		s->distx = (s->mapx + 1 - s->rayx) * s->deltadistx;
	}
	if (s->raydy < 0)
	{
		s->stepy = -1;
		s->disty = (s->rayy - s->mapy) * s->deltadisty;
	}
	else
	{
		s->stepy = 1;
		s->disty = (s->mapy + 1 - s->rayy) * s->deltadisty;
	}
}

void	ray3(t_struct *s)
{
	while (s->hit == 0)
	{
		if (s->distx < s->disty)
		{
			s->distx += s->deltadistx;
			s->mapx += s->stepx;
			s->side = 0;
		}
		else
		{
			s->disty += s->deltadisty;
			s->mapy += s->stepy;
			s->side = 1;
		}
		if (s->map[s->mapx][s->mapy] > 0)
			s->hit = 1;
	}
}

void	ray4(t_struct *s)
{
	if (s->side == 0)
		s->perpwalldist = fabs((s->mapx - s->rayx + (1 - s->stepx) / 2)
							/ s->raydx);
	else
		s->perpwalldist = fabs((s->mapy - s->rayy + (1 - s->stepy) / 2)
							/ s->raydy);
	if (s->perpwalldist == 0)
		s->perpwalldist = 0.01;
	s->lineh = abs((int)(MAPH / s->perpwalldist));
	s->drawstart = -s->lineh / 2 + MAPH / 2;
	if (s->drawstart < 0)
		s->drawstart = 0;
	s->drawend = s->lineh / 2 + MAPH / 2;
	if (s->drawend >= MAPH)
		s->drawend = MAPH - 1;
}
