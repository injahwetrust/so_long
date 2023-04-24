/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:39:17 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/09 14:39:19 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
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
	t_vector	per;
	int			perso;
	int			col;
	int			line;
	int			map_size;
	int			p;
	int			e;
	int			c;
	int			m;
	int			nl;
	int			fd;
}	t_map;

typedef struct s_program
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_image		p_sprite[8];
	t_image		e_sprite[6];
	t_image		lose[8];
	t_image		win[7];
	t_image		c_sprite;
	t_image		w_sprite;
	t_image		wi_sprite;
	t_image		f_sprite;
	t_image		b_sprite;
	t_image		m_sprite[2];
	t_image		corners[4];
	int			cases;
	int			step;
	int			frame;
	int			e_frame;
	int			e_cat;
	int			cat;
	int			anim;
	int			exit_cat;
	t_vector	sprite_position;
	int			move;
	int			stop;
}				t_program;

int		check_image1(t_program *prog);
int		check_image2(t_program *prog);
void	free_image2(t_program *prog);
char	*get_next_line(int fd);
void	free_maps(t_program *prog);
void	free_image1(t_program *prog);
int		end(t_program *prog);
void	move_up(t_program *prog);
void	move_right(t_program *prog);
void	move_down(t_program *prog);
void	move_left(t_program *prog);
int		handle_input(int key, t_program *prog);
void	edit_data(t_program *prog, char c);
void	check_rect(t_program *prog, char *str);
void	map(t_program *prog);
void	print_walls(t_program *prog, int i);
void	check_enter(t_program *prog);
int		map_size(t_program *prog);
char	*ft_mlxjoin(char *save, char *buff);
void	refresh(t_program *prog, char *str, char *str2, char *str3);
int		anim(t_program *prog, int frame);
int		ennemy_right(t_program *prog, int i);
int		ennemy_left(t_program *prog, int i);
void	ennemy(t_program *prog);
int		edit_sprites(t_program *prog);
void	render_info(t_program *prog);
void	render_lose(t_program *prog);
void	render_win(t_program *prog);
void	render_background(t_program *prog);
void	render(t_program *prog, int i);
int		build_screen(t_program *prog);
void	edit_win(t_program *prog);
void	edit_lose(t_program *prog);
void	edit_perso1(t_program *prog);
void	edit_perso2(t_program *prog);
void	edit_corners(t_program *prog);
void	edit_exit(t_program *prog);
void	ennemy_sprite(t_program *prog);
void	edit_sprites1(t_program *prog);
void	check_borders(t_program *prog);
char	*line_copy(t_program *prog, int a);
void	map_copy(t_program *prog);
void	fill(char **tab, t_vector size, t_vector cur, char to_fill);
void	flood_fill(t_program *prog);
int		error(t_program *prog, char **argv);
void	init_prog(t_program *prog, char **argv);
void	map_error(t_program *prog);

#endif
