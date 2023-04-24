/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:00:54 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/09 15:00:56 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_up(t_program *prog)
{
	if (prog->map.ber[prog->map.perso - prog->map.col] == 'M')
		prog->cat = prog->cat % 2 + 6;
	if (prog->cat < 6 && prog->exit_cat < 4)
	{
		prog->stop = 0;
		if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
			prog->exit_cat = 0;
		if (prog->map.ber[prog->map.perso] != 'E')
			prog->map.ber[prog->map.perso] = '0';
		if (prog->map.ber[prog->map.perso - prog->map.col] == 'C')
			prog->map.c--;
		if (prog->map.ber[prog->map.perso - prog->map.col] != 'E')
			prog->map.ber[prog->map.perso - prog->map.col] = 'P';
		prog->map.perso = prog->map.perso - prog->map.col;
		prog->move += 1;
		if (prog->cat < 2)
			prog->cat += 2;
		if (prog->cat >= 4)
			prog->cat -= 2;
		if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
			prog->exit_cat = prog->cat;
	}
}

void	move_down(t_program *prog)
{
	if (prog->map.ber[prog->map.perso + prog->map.col] == 'M')
		prog->cat = prog->cat % 2 + 6;
	if (prog->cat < 6 && prog->exit_cat < 4)
	{
		prog->stop = 0;
		if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
			prog->exit_cat = 0;
		if (prog->map.ber[prog->map.perso] != 'E')
			prog->map.ber[prog->map.perso] = '0';
		if (prog->map.ber[prog->map.perso + prog->map.col] == 'C')
			prog->map.c--;
		if (prog->map.ber[prog->map.perso + prog->map.col] != 'E')
			prog->map.ber[prog->map.perso + prog->map.col] = 'P';
		prog->map.perso = prog->map.perso + prog->map.col;
		prog->move += 1;
		if (prog->cat < 2)
			prog->cat += 2;
		if (prog->cat >= 4)
			prog->cat -= 2;
		if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
			prog->exit_cat = prog->cat;
	}
}

void	move_right(t_program *prog)
{
	if (prog->map.ber[prog->map.perso + 1] == 'M')
		prog->cat = prog->cat % 2 + 6;
	if (prog->cat < 6 && prog->exit_cat < 4)
	{
		prog->stop = 0;
		if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
			prog->exit_cat = 0;
		if (prog->map.ber[prog->map.perso] != 'E')
			prog->map.ber[prog->map.perso] = '0';
		if (prog->map.ber[prog->map.perso + 1] == 'C')
			prog->map.c--;
		if (prog->map.ber[prog->map.perso + 1] != 'E')
			prog->map.ber[prog->map.perso + 1] = 'P';
		prog->map.perso = prog->map.perso + 1;
		prog->move += 1;
		prog->cat = 3;
		if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
			prog->exit_cat = prog->cat;
	}
}

void	move_left(t_program *prog)
{
	if (prog->map.ber[prog->map.perso - 1] == 'M')
		prog->cat = prog->cat % 2 + 6;
	if (prog->cat < 6 && prog->exit_cat < 4)
	{
		prog->stop = 0;
		if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
			prog->exit_cat = 0;
		if (prog->map.ber[prog->map.perso] != 'E')
			prog->map.ber[prog->map.perso] = '0';
		if (prog->map.ber[prog->map.perso - 1] == 'C')
			prog->map.c--;
		if (prog->map.ber[prog->map.perso - 1] != 'E')
			prog->map.ber[prog->map.perso - 1] = 'P';
		prog->map.perso = prog->map.perso - 1;
		prog->move += 1;
		prog->cat = 2;
		if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
			prog->exit_cat = prog->cat;
	}
}

int	handle_input(int key, t_program *prog)
{
	if (key == 65307)
		end(prog);
	if (prog->exit_cat < 4 && prog->cat < 6)
	{
		if (key == 100 && prog->map.ber[prog->map.perso + 1] != '1')
			move_right(prog);
		else if (key == 97 && prog->map.ber[prog->map.perso - 1] != '1')
			move_left(prog);
		else if (key == 115
			&& prog->map.ber[prog->map.perso + prog->map.col] != '1')
			move_down(prog);
		else if (key == 119
			&& prog->map.ber[prog->map.perso - prog->map.col] != '1')
			move_up(prog);
		else if (key == 65451)
			prog->frame -= 2;
		else if (key == 65453)
			prog->frame += 2;
		if (prog->map.ber[prog->map.perso] == 'E' && !prog->map.c)
			prog->exit_cat = prog->cat % 2 + 4;
		else if (!prog->map.c && prog->map.ber[prog->map.perso] != 'E')
			prog->exit_cat = 1;
	}
	return (0);
}
