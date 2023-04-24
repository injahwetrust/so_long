/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:49:13 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/09 14:49:15 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_enter(t_program *prog)
{
	int		i;
	char	c;

	prog->step = 1;
	i = 0;
	while (prog->map.ber[i])
	{
		c = prog->map.ber[i];
		if (c != 'E' && c != '0' && c != '1' && c != 'P'
			&& c != 'C' && c != 'M')
		{
			write (2, "Error\nWrong key\n", 16);
			end(prog);
		}
		i++;
	}
}

void	edit_exit(t_program *prog)
{
	prog->e_sprite[0].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/exit/DoorUnlocked.xpm", &prog->e_sprite[0].size.x,
			&prog->e_sprite[0].size.y);
	prog->e_sprite[1].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/exit/DoorOpen.xpm", &prog->e_sprite[1].size.x,
			&prog->e_sprite[1].size.y);
	prog->e_sprite[2].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/exit/leftD.xpm", &prog->e_sprite[2].size.x,
			&prog->e_sprite[2].size.y);
	prog->e_sprite[3].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/exit/rightD.xpm", &prog->e_sprite[3].size.x,
			&prog->e_sprite[3].size.y);
	prog->e_sprite[4].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/win/GLwin0.xpm", &prog->e_sprite[4].size.x,
			&prog->e_sprite[4].size.y);
	prog->e_sprite[5].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/win/GRwin0.xpm", &prog->e_sprite[5].size.x,
			&prog->e_sprite[5].size.y);
}

void	ennemy_sprite(t_program *prog)
{
	prog->m_sprite[0].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/Zwalk/LZwalk0.xpm", &prog->m_sprite[0].size.x,
			&prog->m_sprite[0].size.y);
	prog->m_sprite[0].path = ft_strdup("xpm/Zwalk/LZwalk");
	prog->m_sprite[0].img_s = 10;
	prog->m_sprite[1].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/Zwalk/RZwalk0.xpm", &prog->m_sprite[1].size.x,
			&prog->m_sprite[1].size.y);
	prog->m_sprite[1].path = ft_strdup("xpm/Zwalk/RZwalk");
	prog->m_sprite[1].img_s = 10;
	prog->e_cat = 0;
}

void	edit_sprites1(t_program *prog)
{
	edit_perso1(prog);
	edit_perso2(prog);
	edit_exit(prog);
	edit_lose(prog);
	edit_win(prog);
	ennemy_sprite(prog);
	prog->f_sprite.ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/StoneBlock.xpm", &prog->f_sprite.size.x,
			&prog->f_sprite.size.y);
	prog->b_sprite.ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/wall/wall1.xpm", &prog->f_sprite.size.x,
			&prog->f_sprite.size.y);
	prog->w_sprite.ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/wall/wall6.xpm", &prog->w_sprite.size.x,
			&prog->w_sprite.size.y);
	prog->wi_sprite.ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/wall/wall1.xpm", &prog->w_sprite.size.x,
			&prog->w_sprite.size.y);
	prog->c_sprite.ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/crane/col0.xpm", &prog->c_sprite.size.x,
			&prog->c_sprite.size.y);
	prog->c_sprite.path = ft_strdup("xpm/crane/col");
	prog->c_sprite.img_s = 12;
	edit_corners(prog);
}
