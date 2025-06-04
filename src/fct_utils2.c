/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouali <ebouali@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:50:48 by ebouali           #+#    #+#             */
/*   Updated: 2025/06/01 17:50:54 by ebouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_textures(t_data *data, void *mlx)
{
	int	w;
	int	h;

	data->img_wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &w, &h);
	data->img_floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &w, &h);
	data->img_player = mlx_xpm_file_to_image(mlx, "textures/player.xpm", &w,
			&h);
	data->img_collectible = mlx_xpm_file_to_image(mlx,
			"textures/collectibles.xpm", &w, &h);
	data->img_exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &w, &h);
	if (!data->img_wall || !data->img_floor || !data->img_collectible
		|| !data->img_exit || !data->img_player)
	{
		ft_printf("ERROR: Failed to load one or more texture(s)\n");
		free_data(data);
	}
	return (1);
}

void	ft_put_picture(t_data *data, void *mlx, void *win, char **map_valid)
{
	if (map_valid[data->mapv_height][data->mapv_width] == '1')
		mlx_put_image_to_window(mlx, win, data->img_wall, data->mapv_width
			* PICTURE_SIZE, data->mapv_height * PICTURE_SIZE);
	else if (map_valid[data->mapv_height][data->mapv_width] == '0')
		mlx_put_image_to_window(mlx, win, data->img_floor, data->mapv_width
			* PICTURE_SIZE, data->mapv_height * PICTURE_SIZE);
	else if (map_valid[data->mapv_height][data->mapv_width] == 'C')
		mlx_put_image_to_window(mlx, win, data->img_collectible,
			data->mapv_width * PICTURE_SIZE, data->mapv_height * PICTURE_SIZE);
	else if (map_valid[data->mapv_height][data->mapv_width] == 'E')
		mlx_put_image_to_window(mlx, win, data->img_exit, data->mapv_width
			* PICTURE_SIZE, data->mapv_height * PICTURE_SIZE);
	else if (map_valid[data->mapv_height][data->mapv_width] == 'P')
		mlx_put_image_to_window(mlx, win, data->img_player, data->mapv_width
			* PICTURE_SIZE, data->mapv_height * PICTURE_SIZE);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	if (!s)
		return (0);
	i = 0;
	a = (unsigned char *)s;
	while (i < n)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	handle_map_char(t_data *data, char c, int x, int y)
{
	if (c == 'P')
	{
		data->player++;
		data->player_x = x;
		data->player_y = y;
	}
	else if (c == 'E')
	{
		data->exit++;
		data->exit_x = x;
		data->exit_y = y;
	}
	else if (c == 'C')
		data->collectibles++;
}

void	parse_map_elements(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			handle_map_char(data, data->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
