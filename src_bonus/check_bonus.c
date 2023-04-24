/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:50:37 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/15 12:50:39 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_borders(t_program *prog)
{
	int	i;
	int	j;
	int	error;

	error = 0;
	i = 0;
	while (i < prog->map.line && !error)
	{
		j = 0;
		while (prog->map.cpy[i][j] && !error)
		{
			if ((i == 0 || i == prog->map.line - 1)
				&& prog->map.cpy[i][j] != '1')
				error = write(2, "Error\nMap need be surounded by walls\n", 37);
			if ((j == 0 || j == prog->map.col - 1)
				&& prog->map.cpy[i][j] != '1')
				error = write(2, "Error\nMap need be surounded by walls\n", 37);
			j++;
		}
		i++;
	}
	if (error)
		end(prog);
}

int	check_image1(t_program *prog)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	if (!prog->w_sprite.ref)
		check++;
	while (i < 7)
	{
		if (i < 2)
		{
			if (!prog->m_sprite[i].ref)
				check++;
			if (!prog->m_sprite[i].path)
				check++;
		}
		if (i < 4 && !prog->corners[i].ref)
			check++;
		if (i < 6 && !prog->e_sprite[i].ref)
			check++;
		if (i < 7 && !prog->win[i].ref)
			check++;
		i++;
	}
	return (check);
}

int	check_image2(t_program *prog)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < 8)
	{
		if (!prog->lose[i].ref)
			check++;
		if (!prog->p_sprite[i].ref)
			check++;
		if (!prog->p_sprite[i].path)
			check++;
		i++;
	}
	if (!prog->wi_sprite.ref || !prog->b_sprite.ref)
		check++;
	if (!prog->c_sprite.ref)
		check++;
	if (!prog->c_sprite.path)
		check++;
	if (!prog->f_sprite.ref)
		check++;
	return (check);
}
