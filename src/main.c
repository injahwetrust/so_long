/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:41:10 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/28 13:41:13 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_enter(t_program *prog)
{
	int		i;
	char	c;

	i = 0;
	while (prog->map.ber[i])
	{
		c = prog->map.ber[i];
		if (c != 'E' && c != '0' && c != '1' && c != 'P' && c != 'C')
		{
			write (2, "Error\nWrong key\n", 16);
			end(prog);
		}
		i++;
	}
}

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

int	main(int argc, char **argv)
{
	t_program	prog;

	if (argc == 2)
	{
		init_prog(&prog, argv);
		error(&prog, argv);
		map_copy(&prog);
		prog.step = 2;
		flood_fill(&prog);
		prog.mlx = mlx_init();
		if (!prog.mlx)
			end(&prog);
		edit_sprites2(&prog);
		prog.step = 3;
		prog.window = mlx_new_window(prog.mlx,
				prog.f_sprite.size.x * prog.map.col,
				prog.f_sprite.size.y * prog.map.line, "so_long");
		mlx_key_hook(prog.window, &handle_input, &prog);
		mlx_hook(prog.window, 17, 1L << 1, &end, &prog);
		mlx_loop_hook(prog.mlx, &build_screen, &prog);
		mlx_loop(prog.mlx);
	}
	else
		return (write(2, "Error\nprogram need 1 .ber file\n", 31));
}
