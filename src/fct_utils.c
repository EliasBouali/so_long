/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouali <ebouali@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:50:59 by ebouali           #+#    #+#             */
/*   Updated: 2025/06/01 17:51:01 by ebouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_picture(t_data *data)
{
	if (data->img_wall)
	{
		mlx_destroy_image(data->mlx, data->img_wall);
		data->img_wall = NULL;
	}
	if (data->img_floor)
	{
		mlx_destroy_image(data->mlx, data->img_floor);
		data->img_floor = NULL;
	}
	if (data->img_player)
	{
		mlx_destroy_image(data->mlx, data->img_player);
		data->img_player = NULL;
	}
	if (data->img_collectible)
	{
		mlx_destroy_image(data->mlx, data->img_collectible);
		data->img_collectible = NULL;
	}
	if (data->img_exit)
	{
		mlx_destroy_image(data->mlx, data->img_exit);
		data->img_exit = NULL;
	}
}

static void	free_window(t_data *data)
{
	if (data->window)
	{
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

static void	free_map(t_data *data)
{
	int	i;
	int	j;

	if (data->map)
	{
		i = 0;
		while (i < data->map_height)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
	if (data->map_valid)
	{
		j = 0;
		while (data->map_valid[j])
		{
			free(data->map_valid[j]);
			j++;
		}
		free(data->map_valid);
		data->map_valid = NULL;
	}
}

void	free_data(t_data *data)
{
	free_picture(data);
	free_window(data);
	free_map(data);
	get_next_line(-1);
	exit(0);
}

int	close_window(t_data *data)
{
	ft_printf("See you next game.");
	free_data(data);
	return (0);
}
