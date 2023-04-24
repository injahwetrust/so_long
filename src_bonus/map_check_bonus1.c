/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:50:11 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/09 14:50:13 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	map_error(t_program *prog)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	error = 0;
	while (i < prog->map.line)
	{
		j = 0;
		while (prog->map.cpy[i][j])
		{
			if (prog->map.cpy[i][j] == 'E')
				error = write (2, "Error\nexit can't be reached\n", 29);
			if (prog->map.cpy[i][j] == 'C')
				error = write (2, "Error\nitem can't be reached\n", 29);
			j++;
		}
		i++;
	}
	if (error)
	{
		prog->step = 2;
		end(prog);
	}
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
	prog->step = 2;
}

void	fill(char **tab, t_vector size, t_vector cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || (tab[cur.y][cur.x] != to_fill
		&& tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'P'
		&& tab[cur.y][cur.x] != 'E'))
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

int	error(t_program *prog, char **argv)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e'
	|| argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
		a = write(2, "Error\n.ber map needed\n", 22);
	if (!prog->map.c)
		a = write(2, "Error\nmap need at least 1 item\n", 32);
	if (prog->map.e != 1)
		a = write(2, "Error\nmap need 1 single exit\n", 29);
	if (prog->map.p != 1)
		a = write(2, "Error\nmap need 1 single hero\n", 29);
	if (a)
		end(prog);
	return (0);
}
