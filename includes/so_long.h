/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:39:24 by bvaujour          #+#    #+#             */
/*   Updated: 2023/02/27 16:39:29 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_image {
	void		*ref;
	char		*path;
	int			img_s;
	t_vector	size;
}				t_image;

typedef struct s_map
{
	char		*ber;
	char		**cpy;
	int			perso;
	t_vector	per;
	int			col;
	int			line;
	int			fd;
	int			map_size;
	int			p;
	int			c;
	int			e;
	int			nl;
}	t_map;

typedef struct s_program
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_image		p_sprite[8];
	t_image		w_sprite;
	t_image		f_sprite;
	t_image		c_sprite;
	t_image		e_sprite[4];
	t_image		k_sprite[2];
	int			exit_cat;
	int			cat;
	int			step;
	t_vector	sprite_position;
	int			move;
}	t_program;

int		check_sprites(t_program *prog);
void	map(t_program *prog);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
void	free_maps(t_program *prog);
void	check_enter(t_program *prog);
void	destroy_image(t_program *prog);
int		end(t_program *prog);
void	edit_sprites1(t_program *prog);
void	edit_sprites2(t_program *prog);
void	edit_sprites3(t_program *prog);
void	print_back1(t_program *prog, char c);
void	print_back2(t_program *prog, char c);
void	edit_data(t_program *prog, char c);
int		build_screen(t_program *prog);
void	map_error(t_program *prog);
char	*line_copy(t_program *prog, int a);
void	map_copy(t_program *prog);
void	print_map_cpy(t_program *prog);
void	fill(char **tab, t_vector size, t_vector cur, char to_fill);
void	flood_fill(t_program *prog);
void	check_borders(t_program *prog);
int		map_size(t_program *prog);
void	check_rect(t_program *prog, char *str);
void	init_prog(t_program *prog, char **argv);
int		error(t_program *prog, char **argv);
void	win(t_program *prog);
void	move_up(t_program *prog);
void	move_down(t_program *prog);
void	move_right(t_program *prog);
void	move_left(t_program *prog);
int		handle_input(int key, t_program *prog);

#endif
