/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:55:49 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/27 16:55:51 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_back1(t_program *prog, char c)
{
	if (c == '0')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->f_sprite.ref, prog->sprite_position.x,
			prog->sprite_position.y);
	if (c == '1')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->w_sprite.ref, prog->sprite_position.x,
			prog->sprite_position.y);
	if (c == 'P')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->p_sprite[prog->cat].ref,
			prog->sprite_position.x, prog->sprite_position.y);
}

void	print_back2(t_program *prog, char c)
{
	if (c == 'C')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->c_sprite.ref, prog->sprite_position.x,
			prog->sprite_position.y);
	if (c == 'E')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->e_sprite[prog->exit_cat].ref,
			prog->sprite_position.x, prog->sprite_position.y);
	if (c == 'K')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->k_sprite[0].ref, prog->sprite_position.x,
			prog->sprite_position.y);
	if (c == 'O')
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->k_sprite[1].ref, prog->sprite_position.x,
			prog->sprite_position.y);
}

void	edit_data(t_program *prog, char c)
{
	if (c == 'P')
		prog->map.p++;
	if (c == 'E')
		prog->map.e++;
	if (c == 'C')
		prog->map.c++;
	if (c == '\n')
		prog->map.nl++;
}

int	build_screen(t_program *prog)
{
	int	i;

	i = 0;
	prog->sprite_position.x = 0;
	prog->sprite_position.y = 0;
	while (prog->map.ber[i] != '\0')
	{
		if (prog->map.ber[i] == 'P')
			prog->map.perso = i;
		print_back1(prog, prog->map.ber[i]);
		print_back2(prog, prog->map.ber[i]);
		prog->sprite_position.x += prog->f_sprite.size.x;
		if (prog->sprite_position.x == prog->f_sprite.size.x * prog->map.col)
		{
			prog->sprite_position.x = 0;
			prog->sprite_position.y += prog->f_sprite.size.y;
		}
		i++;
	}
	return (0);
}

void	map_error(t_program *prog)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	error = 0;
	while (i < prog->map.line)
	{
		j = 0;
		while (prog->map.cpy[i][j])
		{
			if (prog->map.cpy[i][j] == 'E')
				error = write (2, "Error\nexit can't be reached\n", 29);
			if (prog->map.cpy[i][j] == 'C')
				error = write (2, "Error\nitem can't be reached\n", 29);
			j++;
		}
		i++;
	}
	if (error)
	{
		prog->step = 2;
		end(prog);
	}
}
