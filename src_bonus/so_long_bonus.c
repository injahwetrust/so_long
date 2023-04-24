/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:21:43 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/20 16:21:46 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_program	prog;

	if (argc == 2)
	{
		prog.exit_cat = 0;
		init_prog(&prog, argv);
		check_enter(&prog);
		error(&prog, argv);
		map_copy(&prog);
		flood_fill(&prog);
		prog.mlx = mlx_init();
		if (!prog.mlx)
			end(&prog);
		edit_sprites1(&prog);
		prog.window = mlx_new_window(prog.mlx, prog.f_sprite.size.x
				* prog.map.col, prog.f_sprite.size.y * (prog.map.line + 2),
				"so_long");
		prog.step = 3;
		mlx_key_hook(prog.window, &handle_input, &prog);
		mlx_hook(prog.window, 17, 1L << 1, &end, &prog);
		mlx_loop_hook(prog.mlx, &build_screen, &prog);
		mlx_loop(prog.mlx);
	}
	else
		return (write(2, "Error\nprogram need 1 .ber file\n", 31));
}
