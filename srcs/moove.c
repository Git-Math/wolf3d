/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 17:57:23 by mnguyen           #+#    #+#             */
/*   Updated: 2015/06/11 17:12:41 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	moveup(int **map, t_struct *s)
{
	if (map[(int)(s->x + s->dx * 0.5)][(int)(s->y)] != 1)
		s->x += s->dx * 0.5;
	if (map[(int)(s->x)][(int)(s->y + s->dy * 0.5)] != 1)
		s->y += s->dy * 0.5;
}

void	movedown(int **map, t_struct *s)
{
	if (map[(int)(s->x - s->dx * 0.5)][(int)(s->y)] != 1)
		s->x -= s->dx * 0.5;
	if (map[(int)(s->x)][(int)(s->y - s->dy * 0.5)] != 1)
		s->y -= s->dy * 0.5;
}

void	moveright(t_struct *s)
{
	double	oldx;
	double	oldpx;

	oldx = s->dx;
	oldpx = s->px;
	s->dx = s->dx * cos(-ROT) - s->dy * sin(-ROT);
	s->dy = oldx * sin(-ROT) + s->dy * cos(-ROT);
	s->px = s->px * cos(-ROT) - s->py * sin(-ROT);
	s->py = oldpx * sin(-ROT) + s->py * cos(-ROT);
}

void	moveleft(t_struct *s)
{
	double	oldx;
	double	oldpx;

	oldx = s->dx;
	oldpx = s->px;
	s->dx = s->dx * cos(ROT) - s->dy * sin(ROT);
	s->dy = oldx * sin(ROT) + s->dy * cos(ROT);
	s->px = s->px * cos(ROT) - s->py * sin(ROT);
	s->py = oldpx * sin(ROT) + s->py * cos(ROT);
}

void	col(t_struct *s)
{
	if (s->c)
		s->c = 0;
	else
		s->c = 1;
}
