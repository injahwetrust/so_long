/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:37:40 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/27 16:37:42 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_newlines(t_program *prog, char *str)
{
	prog->map.nl--;
	if (str[0] == '\n' && prog->map.nl)
	{
		write (2, "Error\nNewlines\n", 15);
		prog->step = 1;
	}
}

void	map(t_program *prog)
{
	int		i;
	char	*str;

	prog->map.ber = malloc(sizeof(char) * prog->map.map_size + 1);
	if (!prog->map.ber)
		end(prog);
	str = get_next_line(prog->map.fd);
	i = 0;
	while (str)
	{
		if (str[0] != '\n')
		{
			check_rect(prog, str);
			prog->map.col = 0;
			while (str[prog->map.col] != '\n')
				prog->map.ber[i++] = str[prog->map.col++];
			prog->map.line++;
		}
		check_newlines(prog, str);
		free(str);
		str = get_next_line(prog->map.fd);
	}
	prog->map.ber[i] = '\0';
}

void	init_prog(t_program *prog, char **argv)
{
	prog->exit_cat = 0;
	prog->map.nl = 0;
	prog->step = 0;
	prog->map.e = 0;
	prog->map.p = 0;
	prog->map.c = 0;
	prog->map.col = 0;
	prog->map.line = 0;
	prog->move = 0;
	prog->cat = 0;
	prog->map.fd = open(argv[1], O_RDONLY);
	prog->map.map_size = map_size(prog);
	if (prog->map.map_size == -1)
	{
		write (2, "Error\nInvalid file\n", 19);
		exit(0);
	}
	close (prog->map.fd);
	prog->map.fd = open(argv[1], O_RDONLY);
	map(prog);
	close (prog->map.fd);
	if (prog->step == 1)
		end(prog);
	prog->step = 1;
	check_enter(prog);
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

void	win(t_program *prog)
{
	prog->exit_cat = 3;
	if (prog->map.line % 2 == 0)
	{
		prog->map.ber[prog->map.map_size / 2 + prog->map.col / 2] = 'K';
		prog->map.ber[prog->map.map_size / 2 + prog->map.col / 2 + 1] = 'O';
	}
	else
	{
		prog->map.ber[prog->map.map_size / 2] = 'K';
		prog->map.ber[prog->map.map_size / 2 + 1] = 'O';
	}
}
