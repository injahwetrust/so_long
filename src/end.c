/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:56:42 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/27 16:56:47 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_image(t_program *prog)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (i <= 1 && prog->k_sprite[i].ref)
			mlx_destroy_image(prog->mlx, prog->k_sprite[i].ref);
		if (i <= 3 && prog->e_sprite[i].ref)
			mlx_destroy_image(prog->mlx, prog->e_sprite[i].ref);
		if (prog->p_sprite[i].ref)
			mlx_destroy_image(prog->mlx, prog->p_sprite[i].ref);
		i++;
	}
	if (prog->c_sprite.ref)
		mlx_destroy_image(prog->mlx, prog->c_sprite.ref);
	if (prog->f_sprite.ref)
		mlx_destroy_image(prog->mlx, prog->f_sprite.ref);
	if (prog->w_sprite.ref)
		mlx_destroy_image(prog->mlx, prog->w_sprite.ref);
}

int	end(t_program *prog)
{
	if (prog->step >= 1)
		free(prog->map.ber);
	if (prog->step >= 2)
		free_maps(prog);
	if (prog->step >= 3)
	{
		destroy_image(prog);
		mlx_destroy_window(prog->mlx, prog->window);
		mlx_destroy_display(prog->mlx);
		free (prog->mlx);
	}
	exit(0);
}

void	edit_sprites1(t_program *prog)
{
	prog->p_sprite[0].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/lpackman.xpm",
			&prog->p_sprite[0].size.x, &prog->p_sprite[0].size.y);
	prog->p_sprite[1].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/lpackman2.xpm",
			&prog->p_sprite[1].size.x, &prog->p_sprite[1].size.y);
	prog->p_sprite[2].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/dpackman.xpm",
			&prog->p_sprite[2].size.x, &prog->p_sprite[2].size.y);
	prog->p_sprite[3].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/dpackman2.xpm",
			&prog->p_sprite[3].size.x, &prog->p_sprite[3].size.y);
	prog->p_sprite[4].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/rpackman.xpm",
			&prog->p_sprite[4].size.x, &prog->p_sprite[4].size.y);
	prog->p_sprite[5].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/rpackman2.xpm",
			&prog->p_sprite[5].size.x, &prog->p_sprite[5].size.y);
	prog->p_sprite[6].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/upackman.xpm",
			&prog->p_sprite[6].size.x, &prog->p_sprite[6].size.y);
	prog->p_sprite[7].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/upackman2.xpm",
			&prog->p_sprite[7].size.x, &prog->p_sprite[7].size.y);
}

void	edit_sprites2(t_program *prog)
{
	prog->f_sprite.ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/backpack.xpm",
			&prog->f_sprite.size.x, &prog->f_sprite.size.y);
	prog->c_sprite.ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/pomme.xpm",
			&prog->c_sprite.size.x, &prog->c_sprite.size.y);
	prog->w_sprite.ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/wall.xpm",
			&prog->w_sprite.size.x, &prog->w_sprite.size.y);
	prog->k_sprite[0].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/win1.xpm",
			&prog->k_sprite[0].size.x, &prog->k_sprite[0].size.y);
	prog->k_sprite[1].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/win2.xpm",
			&prog->k_sprite[1].size.x, &prog->k_sprite[1].size.y);
	edit_sprites1(prog);
	edit_sprites3(prog);
}

void	edit_sprites3(t_program *prog)
{
	prog->e_sprite[0].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/exitclose.xpm",
			&prog->e_sprite[0].size.x, &prog->e_sprite[0].size.y);
	prog->e_sprite[1].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/exit1.xpm",
			&prog->e_sprite[1].size.x, &prog->e_sprite[1].size.y);
	prog->e_sprite[2].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/exitopen.xpm",
			&prog->e_sprite[2].size.x, &prog->e_sprite[2].size.y);
	prog->e_sprite[3].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/packman/exit2.xpm",
			&prog->e_sprite[3].size.x, &prog->e_sprite[3].size.y);
	if (check_sprites(prog))
	{
		write(2, "ERROR!!!\nxpm hacked\n", 20);
		destroy_image(prog);
		mlx_destroy_display(prog->mlx);
		free(prog->mlx);
		end(prog);
	}
}
