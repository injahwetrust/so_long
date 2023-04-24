/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initend_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:02:45 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/09 15:02:47 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_maps(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->map.line)
	{
		free (prog->map.cpy[i]);
		i++;
	}
	free(prog->map.cpy);
}

void	free_image1(t_program *prog)
{
	int	i;

	i = 0;
	if (prog->f_sprite.ref)
		mlx_destroy_image(prog->mlx, prog->f_sprite.ref);
	if (prog->w_sprite.ref)
		mlx_destroy_image(prog->mlx, prog->w_sprite.ref);
	while (i < 7)
	{
		if (i < 2)
		{
			if (prog->m_sprite[i].ref)
				mlx_destroy_image(prog->mlx, prog->m_sprite[i].ref);
			if (prog->m_sprite[i].path)
				free(prog->m_sprite[i].path);
		}
		if (i < 4 && prog->corners[i].ref)
			mlx_destroy_image(prog->mlx, prog->corners[i].ref);
		if (i < 6 && prog->e_sprite[i].ref)
			mlx_destroy_image(prog->mlx, prog->e_sprite[i].ref);
		if (i < 7 && prog->win[i].ref)
			mlx_destroy_image(prog->mlx, prog->win[i].ref);
		i++;
	}
}

void	free_image2(t_program *prog)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (prog->lose[i].ref)
			mlx_destroy_image(prog->mlx, prog->lose[i].ref);
		if (prog->p_sprite[i].ref)
			mlx_destroy_image(prog->mlx, prog->p_sprite[i].ref);
		if (prog->p_sprite[i].path)
			free(prog->p_sprite[i].path);
		i++;
	}
	if (prog->wi_sprite.ref)
		mlx_destroy_image(prog->mlx, prog->wi_sprite.ref);
	if (prog->b_sprite.ref)
		mlx_destroy_image(prog->mlx, prog->b_sprite.ref);
	if (prog->c_sprite.ref)
		mlx_destroy_image(prog->mlx, prog->c_sprite.ref);
	if (prog->c_sprite.path)
		free(prog->c_sprite.path);
}

int	end(t_program *prog)
{
	if (prog->step >= 1)
		free(prog->map.ber);
	if (prog->step >= 2)
		free_maps(prog);
	if (prog->step == 3)
	{
		free_image1(prog);
		free_image2(prog);
		mlx_destroy_window(prog->mlx, prog->window);
		mlx_destroy_display(prog->mlx);
		free (prog->mlx);
	}
	exit(0);
}

void	init_prog(t_program *prog, char **argv)
{
	prog->anim = 0;
	prog->step = 0;
	prog->map.nl = 0;
	prog->stop = 0;
	prog->map.m = 0;
	prog->map.e = 0;
	prog->map.p = 0;
	prog->map.c = 0;
	prog->map.col = 0;
	prog->frame = 25;
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
	if (prog->step)
		end(prog);
}
