/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:56:59 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/09 14:57:01 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ennemy_right(t_program *prog, int i)
{
	int	move;

	move = 0;
	if (prog->map.ber[i + 1] && prog->map.ber[i] == 'M' && prog->e_cat)
	{
		if (prog->map.ber[i + 1] == 'P')
		{
			prog->cat = (prog->cat % 2) + 6;
			prog->stop = 0;
		}
		else if (prog->map.ber[i + 1] != '1' && prog->map.ber[i + 1] != 'E'
			&& prog->map.ber[i + 1] != 'C')
		{
			prog->map.ber[i] = '0';
			prog->map.ber[i + 1] = 'M';
			move++;
			i++;
		}
	}
	return (move);
}

int	ennemy_left(t_program *prog, int i)
{
	int	move;

	move = 0;
	if (i > 0 && prog->map.ber[i] == 'M' && !prog->e_cat)
	{
		if (prog->map.ber[i - 1] == 'P')
		{
			prog->cat = (prog->cat % 2) + 6;
			prog->stop = 0;
		}
		else if (prog->map.ber[i - 1] != '1' && prog->map.ber[i - 1] != 'E'
			&& prog->map.ber[i - 1] != 'C')
		{
			prog->map.ber[i] = '0';
			prog->map.ber[i - 1] = 'M';
			move++;
		}
	}
	return (move);
}

void	ennemy(t_program *prog)
{
	int			i;
	static int	move = 0;
	int			debug;

	debug = move;
	i = 0;
	while (prog->map.ber[i] && !(prog->anim % prog->e_frame))
	{
		if (prog->map.ber[i] == 'M')
		{
			move += ennemy_left(prog, i);
			move += ennemy_right(prog, i);
			i++;
			if (debug == move)
				move += prog->map.col;
		}
		i++;
	}
	if (move >= (prog->cases * prog->map.m))
	{
		prog->e_cat = (prog->e_cat + 1) % 2;
		move = 0;
	}
}

int	edit_sprites(t_program *prog)
{
	static int	frame = 0;

	prog->e_frame = prog->map.c * prog->frame + 10;
	prog->cases = prog->map.col / 4 + 1 / (prog->map.c + 1);
	frame += anim(prog, frame);
	ennemy(prog);
	prog->anim %= 1200;
	prog->anim++;
	prog->stop++;
	if (prog->stop / 2 > 4 * prog->frame && prog->cat < 4)
		prog->cat = prog->cat % 2;
	if ((prog->cat >= 6 || prog->exit_cat >= 4) && prog->stop == 2000)
		end(prog);
	if (prog->stop > 50 * prog->frame && prog->cat < 2)
		prog->cat += 4;
	if (frame > prog->frame)
		frame = 0;
	return (0);
}

void	render_info(t_program *prog)
{
	char	*str;
	char	*str2;

	str2 = ft_itoa(prog->map.c);
	str = ft_itoa(prog->move);
	mlx_string_put(prog->mlx, prog->window, 140, prog->f_sprite.size.y
		* (prog->map.line + 1) + 20, 0x00FFFFFF, str);
	mlx_string_put(prog->mlx, prog->window, 10, prog->f_sprite.size.y
		* (prog->map.line + 1) + 19, 0x00FFFFFF, "nombre de movements :");
	mlx_string_put(prog->mlx, prog->window, 10, prog->f_sprite.size.y
		* (prog->map.line + 1) + 35, 0x00FFFFFF, "nombre de collectible :");
	mlx_string_put(prog->mlx, prog->window, 150, prog->f_sprite.size.y
		* (prog->map.line + 1) + 35, 0x00FFFFFF, str2);
	free(str2);
	free(str);
}
