/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:22:09 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/15 12:22:12 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	check_sprites(t_program *prog)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i <= 7)
	{
		if (i <= 1 && !prog->k_sprite[i].ref)
			check++;
		if (i <= 3 && !prog->e_sprite[i].ref)
			check++;
		if (!prog->p_sprite[i].ref)
			check++;
		i++;
	}
	if (!prog->c_sprite.ref)
		check++;
	if (!prog->f_sprite.ref)
		check++;
	if (!prog->w_sprite.ref)
		check++;
	return (check);
}
