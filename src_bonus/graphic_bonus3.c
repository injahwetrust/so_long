/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_bonus3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:59:26 by bvaujour          #+#    #+#             */
/*   Updated: 2023/03/09 14:59:29 by bvaujour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	edit_data(t_program *prog, char c)
{
	if (c == 'P')
		prog->map.p++;
	if (c == 'E')
		prog->map.e++;
	if (c == 'C')
		prog->map.c++;
	if (c == 'M')
		prog->map.m++;
	if (c == '\n')
		prog->map.nl++;
}

void	print_walls(t_program *prog, int i)
{
	static int	corner = 0;

	if (prog->map.ber[i] == '1' && !(i > prog->map.col
			&& i < prog->map.col * (prog->map.line - 1)
			&& (i + 1) % prog->map.col > 1))
	{
		if (i == 0 || i == prog->map.col - 1
			|| i == prog->map.col * prog->map.line - 1
			|| i == prog->map.col * (prog->map.line - 1))
			mlx_put_image_to_window(prog->mlx, prog->window,
				prog->corners[corner++].ref,
				prog->sprite_position.x, prog->sprite_position.y);
		else
			mlx_put_image_to_window(prog->mlx, prog->window, prog->w_sprite.ref,
				prog->sprite_position.x, prog->sprite_position.y);
	}
	if (prog->map.ber[i] == '1' && (i > prog->map.col
			&& i < prog->map.col * (prog->map.line - 1)
			&& (i + 1) % prog->map.col > 1))
		mlx_put_image_to_window(prog->mlx, prog->window,
			prog->wi_sprite.ref, prog->sprite_position.x,
			prog->sprite_position.y);
	corner %= 4;
}

char	*ft_mlxjoin(char *save, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!save)
	{
		save = (char *)malloc(1 * sizeof(char));
		save[0] = '\0';
	}
	if (!save || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(buff) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (save[++i] != '\0')
		str[i] = save[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(save);
	free(buff);
	return (str);
}

void	refresh(t_program *prog, char *str, char *str2, char *str3)
{
	mlx_destroy_image(prog->mlx, prog->p_sprite[prog->cat].ref);
	mlx_destroy_image(prog->mlx, prog->c_sprite.ref);
		prog->c_sprite.ref = mlx_xpm_file_to_image
		(prog->mlx, str2, &prog->c_sprite.size.x, &prog->c_sprite.size.y);
	prog->p_sprite[prog->cat].ref = mlx_xpm_file_to_image
		(prog->mlx, str, &prog->p_sprite[prog->cat].size.x,
			&prog->p_sprite[prog->cat].size.y);
	mlx_destroy_image(prog->mlx, prog->m_sprite[prog->e_cat].ref);
	prog->m_sprite[prog->e_cat].ref = mlx_xpm_file_to_image
		(prog->mlx, str3, &prog->m_sprite[prog->e_cat].size.x,
			&prog->m_sprite[prog->e_cat].size.y);
}

int	anim(t_program *prog, int frame)
{
	char	*str;
	char	*str2;
	char	*str3;

	str = ft_mlxjoin(ft_mlxjoin(ft_strdup(prog->p_sprite[prog->cat].path),
				ft_itoa(prog->stop % prog->p_sprite[prog->cat].img_s)),
			ft_strdup(".xpm"));
	str2 = ft_mlxjoin(ft_mlxjoin(ft_strdup(prog->c_sprite.path),
				ft_itoa(prog->anim % prog->c_sprite.img_s)), ft_strdup(".xpm"));
	str3 = ft_mlxjoin(ft_mlxjoin(ft_strdup(prog->m_sprite[prog->e_cat].path),
				ft_itoa(prog->anim % prog->m_sprite[prog->e_cat].img_s)),
			ft_strdup(".xpm"));
	if (frame == prog->frame)
		refresh(prog, str, str2, str3);
	return (free(str), free(str2), free(str3), 1);
}
