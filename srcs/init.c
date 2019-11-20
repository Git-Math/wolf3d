/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 18:54:05 by mnguyen           #+#    #+#             */
/*   Updated: 2015/06/11 16:29:37 by mnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_pos(t_struct *s)
{
	s->x = 10;
	s->y = 3;
	s->dx = -1;
	s->dy = 0;
	s->px = 0;
	s->py = 0.66;
	s->c = 1;
}

int		createfd(int map)
{
	int	fd;

	if (map == 2)
		fd = open("./maps/map02", O_RDONLY);
	if (map == 3)
		fd = open ("./maps/map03", O_RDONLY);
	else
		fd = open("./maps/map01", O_RDONLY);
	if (fd == -1)
		coderror('O');
	return (fd);
}

void	remp(int fd, t_struct *s)
{
	int		k;
	char	*str;

	if (!(s->map = (int **)malloc(sizeof(int *) * 24)))
		coderror('M');
	if (!(str = ft_strnew(BUFF_SIZE)))
		coderror('M');
	k = 0;
	while (read(fd, str, BUFF_SIZE) > 0)
	{
		if (!(s->map[k] = (int *)malloc(sizeof(int) * 24)))
			coderror('M');
		remp2(str, s, k++);
		if (str)
			free(str);
		if (!(str = ft_strnew(BUFF_SIZE)) && k < 24)
			coderror('M');
	}
	if (str)
		free(str);
}

void	remp2(char *str, t_struct *s, int k)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < BUFF_SIZE)
	{
		while (str[i] == ' ')
			i++;
		if (i < BUFF_SIZE && str[i] != ' ')
			s->map[k][j++] = ft_atoi(str + i);
		while (i < BUFF_SIZE && str[i] != ' ')
			i++;
	}
}

void	coderror(char c)
{
	if (c == 'O')
		perror("open ");
	else if (c == 'C')
		perror("close ");
	else if (c == 'M')
		perror("malloc ");
	else if (c == '1')
		perror("libft (strdup) ");
	exit(0);
}
