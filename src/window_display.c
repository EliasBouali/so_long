/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouali <ebouali@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:51:30 by ebouali           #+#    #+#             */
/*   Updated: 2025/06/01 17:51:31 by ebouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	render_map(t_data *data, void *mlx, void *win, char **map_valid);

static int	move_player(t_data *data, int x, int y)
{
	if (data->map_valid[y][x] == '1')
		return (0);
	else if (data->map_valid[y][x] == '0')
	{
		data->map_valid[y][x] = 'P';
		data->map_valid[data->player_y][data->player_x] = '0';
	}
	else if (data->map_valid[y][x] == 'C')
	{
		data->map_valid[y][x] = 'P';
		data->map_valid[data->player_y][data->player_x] = '0';
		data->collectibles_find++;
	}
	else if (data->map_valid[y][x] == 'E')
	{
		ft_printf("YOU WIN WITH %d WALK\n", data->walk);
		free_picture(data);
		free_data(data);
	}
	data->player_x = x;
	data->player_y = y;
	ft_printf("%d\n", ++data->walk);
	if (data->collectibles_find == data->collectibles)
		data->map_valid[data->exit_y][data->exit_x] = 'E';
	return (1);
}

static int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 119)
		move_player(data, data->player_x, data->player_y - 1);
	else if (keycode == 115)
		move_player(data, data->player_x, data->player_y + 1);
	else if (keycode == 97)
		move_player(data, data->player_x - 1, data->player_y);
	else if (keycode == 100)
		move_player(data, data->player_x + 1, data->player_y);
	free_picture(data);
	render_map(data, data->mlx, data->window, data->map_valid);
	return (0);
}

static void	load_xpm(t_data *data, void *mlx)
{
	if (!load_textures(data, mlx))
	{
		ft_printf("ERROR: Failed to load one or more texture(s)\n");
		free_data(data);
	}
}

static void	render_map(t_data *data, void *mlx, void *win, char **map_valid)
{
	load_xpm(data, mlx);
	data->mapv_height = 0;
	while (map_valid[data->mapv_height] != NULL)
	{
		data->mapv_width = 0;
		while (map_valid[data->mapv_height][data->mapv_width] != '\0')
		{
			ft_put_picture(data, mlx, win, map_valid);
			data->mapv_width++;
		}
		data->mapv_height++;
	}
}

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_printf("ERROR: FAiled to initialize mlx\n");
	data->window = mlx_new_window(data->mlx, data->map_width * 64,
			data->map_height * 64, "WELKOME");
	render_map(data, data->mlx, data->window, data->map_valid);
	mlx_hook(data->window, 17, 0, close_window, data);
	mlx_key_hook(data->window, handle_key, data);
	mlx_loop(data->mlx);
}
