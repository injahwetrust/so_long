/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_bonus1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:55:02 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/09 14:55:05 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	render_lose(t_program *prog)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (prog->sprite_position.x < prog->f_sprite.size.x * prog->map.col)
	{
		if (prog->map.col - (2 * i) < 8 && j < 8)
		{
			mlx_put_image_to_window(prog->mlx, prog->window, prog->lose[j].ref,
				prog->sprite_position.x, prog->sprite_position.y);
			j++;
		}
		prog->sprite_position.x += prog->f_sprite.size.x;
		i++;
	}
}

void	render_win(t_program *prog)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (prog->sprite_position.x < prog->f_sprite.size.x * prog->map.col)
	{
		if (prog->map.col - (2 * i) < 7 && j < 7)
		{
			mlx_put_image_to_window(prog->mlx, prog->window, prog->win[j].ref,
				prog->sprite_position.x, prog->sprite_position.y);
			j++;
		}
		prog->sprite_position.x += prog->f_sprite.size.x;
		i++;
	}
}

void	render_background(t_program *prog)
{
	if (prog->cat >= 6 && prog->map.col > 8)
		render_lose(prog);
	if (!prog->map.c && prog->map.col > 7
		&& prog->map.ber[prog->map.perso] == 'E')
	{
		prog->cat = prog->cat % 2 + 4;
		render_win(prog);
	}
	prog->sprite_position.x = 0;
	prog->sprite_position.y += prog->f_sprite.size.y;
	while (prog->sprite_position.x < prog->f_sprite.size.x * prog->map.col)
	{
		mlx_put_image_to_window(prog->mlx, prog->window, prog->b_sprite.ref,
			prog->sprite_position.x, prog->sprite_position.y);
		prog->sprite_position.x += prog->f_sprite.size.x;
	}
	render_info(prog);
}

void	render(t_program *prog, int i)
{
	if (prog->map.ber[i] == '0')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->f_sprite.ref, prog->sprite_position.x,
			prog->sprite_position.y);
	if (prog->map.ber[i] == '1')
		print_walls(prog, i);
	if (prog->map.ber[i] == 'P')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->p_sprite[prog->cat].ref, prog->sprite_position.x,
			prog->sprite_position.y);
	if (prog->map.ber[i] == 'M')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->m_sprite[prog->e_cat].ref, prog->sprite_position.x,
			prog->sprite_position.y);
	if (prog->map.ber[i] == 'E')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->e_sprite[prog->exit_cat].ref, prog->sprite_position.x,
			prog->sprite_position.y);
	if (prog->map.ber[i] == 'C')
		mlx_put_image_to_window(prog->mlx, prog->window, prog->c_sprite.ref,
			prog->sprite_position.x, prog->sprite_position.y);
}

int	build_screen(t_program *prog)
{
	int	i;

	edit_sprites(prog);
	i = 0;
	prog->sprite_position.x = 0;
	prog->sprite_position.y = 0;
	while (prog->map.ber[i] != '\0')
	{
		render(prog, i);
		prog->sprite_position.x += prog->f_sprite.size.x;
		if (prog->sprite_position.x == prog->f_sprite.size.y * prog->map.col)
		{
			prog->sprite_position.x = 0;
			prog->sprite_position.y += prog->f_sprite.size.y;
		}
		i++;
	}
	render_background(prog);
	return (0);
}
