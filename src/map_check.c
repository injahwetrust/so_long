/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:53:41 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/27 16:53:43 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*line_copy(t_program *prog, int a)
{	
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = a * prog->map.col;
	line = malloc(sizeof(char) * prog->map.col + 1);
	if (!line)
		end(prog);
	while (i < prog->map.col * (a + 1))
	{
		line[j] = prog->map.ber[i];
		j++;
		i++;
	}
	line[j] = '\0';
	return (line);
}

void	map_copy(t_program *prog)
{
	int	i;
	int	j;

	i = 0;
	prog->map.cpy = malloc (sizeof(char *) * (prog->map.line + 1));
	if (!prog->map.cpy)
		end(prog);
	while (i < prog->map.line)
	{
		j = 0;
		prog->map.cpy[i] = line_copy(prog, i);
		while (prog->map.cpy[i][j])
		{
			if (prog->map.cpy[i][j] == 'P')
			{
				prog->map.per.x = j;
				prog->map.per.y = i;
			}
			j++;
		}
		i++;
	}
	prog->map.cpy[i] = 0;
}

void	fill(char **tab, t_vector size, t_vector cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.y][cur.x] == '1'
		|| tab[cur.y][cur.x] == 'F')
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_vector){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_vector){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_vector){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_vector){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(t_program *prog)
{
	t_vector	size;
	t_vector	cur;

	check_borders(prog);
	size.x = prog->map.col;
	size.y = prog->map.line;
	cur.x = prog->map.per.x;
	cur.y = prog->map.per.y;
	fill(prog->map.cpy, size, cur, '0');
	map_error(prog);
}

int	map_size(t_program *prog)
{
	char	*buff;
	int		ret;
	int		check;

	ret = 1;
	check = 0;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		exit(0);
	while (ret)
	{
		ret = read(prog->map.fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (-1);
		}
		if (ret)
			edit_data(prog, buff[0]);
		if (ret && buff[0] != '\n')
			check++;
	}
	free(buff);
	return (check);
}
