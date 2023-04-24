/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:52:27 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/09 14:52:29 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

void	check_rect(t_program *prog, char *str)
{
	static int	save = 0;
	int			check;

	check = 0;
	if (!save)
		while (str[save])
			save++;
	else if (save)
		while (str[check])
			check++;
	if ((save && check) && (save != check))
	{
		write(2, "Error\nmap not rectangle\n", 24);
		prog->step = 1;
	}
}

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
		if (ret && buff[0] == 'P')
			prog->map.perso = check;
		if (ret && buff[0] != '\n')
			check++;
	}
	return (free(buff), check);
}
