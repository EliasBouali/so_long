/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouali <ebouali@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:51:06 by ebouali           #+#    #+#             */
/*   Updated: 2025/06/01 17:51:08 by ebouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	copy_map(t_data *data)
{
	int	i;

	data->map_valid = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map_valid)
	{
		ft_printf("Error: Fail malloc copy map\n");
		free_data(data);
	}
	i = 0;
	while (i < data->map_height)
	{
		data->map_valid[i] = ft_strdup(data->map[i]);
		if (!data->map_valid[i])
		{
			ft_printf("Error: strdup copy map failed\n");
			free_data(data);
		}
		i++;
	}
	data->map_valid[i] = NULL;
}

static void	init_move(t_data *data)
{
	data->moves[0][0] = -1;
	data->moves[0][1] = 0;
	data->moves[1][0] = 1;
	data->moves[1][1] = 0;
	data->moves[2][0] = 0;
	data->moves[2][1] = -1;
	data->moves[3][0] = 0;
	data->moves[3][1] = 1;
}

static int	valide_move(t_data *data, int move_x, int move_y)
{
	if (move_x < 0 || move_x >= data->map_width || move_y < 0
		|| move_y >= data->map_height)
		return (0);
	if (data->map[move_y][move_x] == '1')
		return (0);
	return (1);
}

static int	flood_fill(t_data *data, int x, int y)
{
	int	new_x;
	int	new_y;
	int	i;

	i = 0;
	init_move(data);
	if (data->map[y][x] == 'E')
		data->exit_find++;
	if (data->map[y][x] == 'C')
		data->collectibles_find++;
	data->map[y][x] = '1';
	while (i < 4)
	{
		new_x = x + data->moves[i][0];
		new_y = y + data->moves[i][1];
		if (valide_move(data, new_x, new_y))
			flood_fill(data, new_x, new_y);
		i++;
	}
	return (1);
}

void	game_tracking(t_data *data)
{
	copy_map(data);
	flood_fill(data, data->player_x, data->player_y);
	if (data->collectibles == data->collectibles_find
		&& data->exit_find == data->exit)
		ft_printf("Hello.\n");
	else
	{
		ft_printf("the game is unplayable.\n");
		free_data(data);
	}
}
