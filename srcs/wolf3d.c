/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 16:53:36 by mnguyen           #+#    #+#             */
/*   Updated: 2015/06/11 16:58:17 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	mlx_put_pixel_to_img(t_struct *s, int x, int y, int color)
{
	ft_memcpy(&s->img[(x * 4) + (y * s->sz)], &color, (sizeof(size_t)));
}

int		expose_hook(t_struct *s)
{
	raycaster(s);
	put_minimap(s);
	mlx_put_image_to_window(s->mlx, s->win, s->new, 0, 0);
	mlx_put_image_to_window(s->mlx, s->win, s->new_mini, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_struct *s)
{
	ft_bzero(s->img, s->bt * 512 + 384 * s->sz);
	if (keycode == ESCAPE)
		exit(0);
	if (keycode == DOWN)
		moveup(s->map, s);
	if (keycode == UP)
		movedown(s->map, s);
	if (keycode == LEFT)
		moveright(s);
	if (keycode == RIGHT)
		moveleft(s);
	if (keycode == R)
		init_pos(s);
	if (keycode == C)
		col(s);
	if (s->map[(int)s->x][(int)s->y] == 2)
	{
		s->x = 6;
		s->y = 17;
	}
	expose_hook(s);
	return (0);
}

void	draw(int x, t_struct *s)
{
	int y;

	y = 0;
	while (y < MAPH)
	{
		if (y < s->drawstart)
			mlx_put_pixel_to_img(s, x, y, 0x99FFFF);
		else if (y < s->drawend)
			mlx_put_pixel_to_img(s, x, y, s->color);
		else
			mlx_put_pixel_to_img(s, x, y, 0x663300);
		y++;
	}
}

int		main(void)
{
	t_struct s;

	init_pos(&s);
	if (!(s.mlx = mlx_init()))
		coderror('m');
	s.win = mlx_new_window(s.mlx, MAPH, MAPW, "wolf");
	if (!(s.new = mlx_new_image(s.mlx, MAPW, MAPH)))
		coderror('m');
	s.img = mlx_get_data_addr(s.new, &s.bt, &s.sz, &s.end);
	if (!(s.img))
		coderror('m');
	remp(createfd(1), &s);
	create_minimap(&s);
	mlx_expose_hook(s.win, expose_hook, &s);
	mlx_hook(s.win, 2, 1L << 0, key_hook, &s);
	mlx_loop(s.mlx);
}
