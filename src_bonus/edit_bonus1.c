/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_bonus1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:47:37 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/09 14:47:39 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	edit_win(t_program *prog)
{
	prog->win[0].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/win/y.xpm",
			&prog->win[0].size.x, &prog->win[0].size.y);
	prog->win[1].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/win/o.xpm",
			&prog->win[1].size.x, &prog->win[1].size.y);
	prog->win[2].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/win/u.xpm",
			&prog->win[2].size.x, &prog->win[2].size.y);
	prog->win[3].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/win/w.xpm",
			&prog->win[3].size.x, &prog->win[3].size.y);
	prog->win[4].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/win/i.xpm",
			&prog->win[4].size.x, &prog->win[4].size.y);
	prog->win[5].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/win/n.xpm",
			&prog->win[5].size.x, &prog->win[5].size.y);
	prog->win[6].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/win/!.xpm",
			&prog->win[6].size.x, &prog->win[6].size.y);
}

void	edit_lose(t_program *prog)
{
	prog->lose[0].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/lose/y.xpm",
			&prog->lose[0].size.x, &prog->lose[0].size.y);
	prog->lose[1].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/lose/o.xpm",
			&prog->lose[1].size.x, &prog->lose[1].size.y);
	prog->lose[2].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/lose/u.xpm",
			&prog->lose[2].size.x, &prog->lose[2].size.y);
	prog->lose[3].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/lose/l.xpm",
			&prog->lose[3].size.x, &prog->lose[3].size.y);
	prog->lose[4].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/lose/o.xpm",
			&prog->lose[4].size.x, &prog->lose[4].size.y);
	prog->lose[5].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/lose/s.xpm",
			&prog->lose[5].size.x, &prog->lose[5].size.y);
	prog->lose[6].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/lose/e.xpm",
			&prog->lose[6].size.x, &prog->lose[6].size.y);
	prog->lose[7].ref = mlx_xpm_file_to_image(prog->mlx, "xpm/lose/!.xpm",
			&prog->lose[7].size.x, &prog->lose[7].size.y);
}

void	edit_perso1(t_program *prog)
{
	prog->p_sprite[0].path = ft_strdup("xpm/Gstand/LGstand");
	prog->p_sprite[0].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/Gstand/LGstand0.xpm", &prog->p_sprite[0].size.x,
			&prog->p_sprite[0].size.y);
	prog->p_sprite[0].img_s = 9;
	prog->p_sprite[1].path = ft_strdup("xpm/Gstand/RGstand");
	prog->p_sprite[1].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/Gstand/RGstand0.xpm", &prog->p_sprite[1].size.x,
			&prog->p_sprite[1].size.y);
	prog->p_sprite[1].img_s = 9;
	prog->p_sprite[2].path = ft_strdup ("xpm/Grun/LGrun");
	prog->p_sprite[2].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/Grun/LGrun0.xpm", &prog->p_sprite[2].size.x,
			&prog->p_sprite[2].size.y);
	prog->p_sprite[2].img_s = 8;
	prog->p_sprite[3].path = ft_strdup("xpm/Grun/RGrun");
	prog->p_sprite[3].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/Grun/RGrun0.xpm", &prog->p_sprite[3].size.x,
			&prog->p_sprite[3].size.y);
	prog->p_sprite[3].img_s = 8;
}

void	edit_perso2(t_program *prog)
{
	prog->p_sprite[4].path = ft_strdup("xpm/show/lanim");
	prog->p_sprite[4].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/show/lanim0.xpm", &prog->p_sprite[4].size.x,
			&prog->p_sprite[4].size.y);
	prog->p_sprite[4].img_s = 35;
	prog->p_sprite[5].path = ft_strdup("xpm/show/ranim");
	prog->p_sprite[5].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/show/ranim0.xpm", &prog->p_sprite[5].size.x,
			&prog->p_sprite[5].size.y);
	prog->p_sprite[5].img_s = 35;
	prog->p_sprite[6].path = ft_strdup("xpm/Gdead/LGdead");
	prog->p_sprite[6].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/Gdead/LGdead0.xpm", &prog->p_sprite[6].size.x,
			&prog->p_sprite[6].size.y);
	prog->p_sprite[6].img_s = 6;
	prog->p_sprite[7].path = ft_strdup("xpm/Gdead/RGdead");
	prog->p_sprite[7].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/Gdead/RGdead0.xpm", &prog->p_sprite[7].size.x,
			&prog->p_sprite[7].size.y);
	prog->p_sprite[7].img_s = 6;
}

void	edit_corners(t_program *prog)
{
	prog->corners[0].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/corners/co0.xpm", &prog->corners[0].size.x,
			&prog->corners[0].size.y);
	prog->corners[1].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/corners/co1.xpm", &prog->corners[1].size.x,
			&prog->corners[1].size.y);
	prog->corners[2].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/corners/co2.xpm", &prog->corners[2].size.x,
			&prog->corners[2].size.y);
	prog->corners[3].ref = mlx_xpm_file_to_image(prog->mlx,
			"xpm/corners/co3.xpm", &prog->corners[3].size.x,
			&prog->corners[3].size.y);
	if (check_image1(prog) || check_image2(prog))
	{
		write(2, "ERROR!!!\nxpm hacked\n", 20);
		free_image1(prog);
		free_image2(prog);
		mlx_destroy_display(prog->mlx);
		free(prog->mlx);
		end(prog);
	}
}
