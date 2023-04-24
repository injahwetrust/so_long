/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:51:39 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/27 16:51:41 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_program *prog)
{
	if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
		prog->exit_cat = 0;
	if (prog->map.ber[prog->map.perso] != 'E')
		prog->map.ber[prog->map.perso] = '0';
	if (prog->map.ber[prog->map.perso - prog->map.col] == 'C')
		prog->map.c--;
	if (prog->map.ber[prog->map.perso - prog->map.col] != 'E')
		prog->map.ber[prog->map.perso - prog->map.col] = 'P';
	prog->map.perso = prog->map.perso - prog->map.col;
	if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
		prog->exit_cat = 1;
	if (prog->map.ber[prog->map.perso] == 'E' && !prog->map.c)
		win(prog);
	if (prog->map.c == 0 && prog->exit_cat != 3)
		prog->exit_cat = 2;
	prog->move += 1;
	prog->cat = 6 + (prog->move % 2);
}

void	move_down(t_program *prog)
{
	if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
		prog->exit_cat = 0;
	if (prog->map.ber[prog->map.perso] != 'E')
		prog->map.ber[prog->map.perso] = '0';
	if (prog->map.ber[prog->map.perso + prog->map.col] == 'C')
		prog->map.c--;
	if (prog->map.ber[prog->map.perso + prog->map.col] != 'E')
		prog->map.ber[prog->map.perso + prog->map.col] = 'P';
	prog->map.perso = prog->map.perso + prog->map.col;
	if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
		prog->exit_cat = 1;
	prog->move += 1;
	prog->cat = 2 + (prog->move % 2);
}

void	move_right(t_program *prog)
{
	if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
		prog->exit_cat = 0;
	if (prog->map.ber[prog->map.perso] != 'E')
		prog->map.ber[prog->map.perso] = '0';
	if (prog->map.ber[prog->map.perso + 1] == 'C')
		prog->map.c--;
	if (prog->map.ber[prog->map.perso + 1] != 'E')
		prog->map.ber[prog->map.perso + 1] = 'P';
	prog->map.perso = prog->map.perso + 1;
	if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
		prog->exit_cat = 1;
	prog->move += 1;
	prog->cat = 4 + (prog->move % 2);
}

void	move_left(t_program *prog)
{
	if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
		prog->exit_cat = 0;
	if (prog->map.ber[prog->map.perso] != 'E')
		prog->map.ber[prog->map.perso] = '0';
	if (prog->map.ber[prog->map.perso - 1] == 'C')
		prog->map.c--;
	if (prog->map.ber[prog->map.perso - 1] != 'E')
		prog->map.ber[prog->map.perso - 1] = 'P';
	prog->map.perso = prog->map.perso - 1;
	if (prog->map.ber[prog->map.perso] == 'E' && prog->map.c)
		prog->exit_cat = 1;
	prog->move += 1;
	prog->cat = 0 + (prog->move % 2);
}

int	handle_input(int key, t_program *prog)
{
	if (key == 65307)
		end(prog);
	if (key == 100 && prog->map.ber[prog->map.perso + 1] != '1'
		&& prog->exit_cat != 3)
		move_right(prog);
	else if (key == 97 && prog->map.ber[prog->map.perso - 1] != '1'
		&& prog->exit_cat != 3)
		move_left(prog);
	else if (key == 115
		&& prog->map.ber[prog->map.perso + prog->map.col] != '1'
		&& prog->exit_cat != 3)
		move_down(prog);
	else if (key == 119
		&& prog->map.ber[prog->map.perso - prog->map.col] != '1'
		&& prog->exit_cat != 3)
		move_up(prog);
	if (prog->map.c == 0)
		prog->exit_cat = 2;
	if (prog->map.ber[prog->map.perso] == 'E' && !prog->map.c)
		win(prog);
	ft_printf("pommes = %d     moves = %d\n",
		prog->map.c, prog->move);
	return (0);
}
