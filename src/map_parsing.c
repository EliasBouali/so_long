/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouali <ebouali@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:51:23 by ebouali           #+#    #+#             */
/*   Updated: 2025/06/01 17:51:25 by ebouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_map_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_width)
	{
		if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1')
		{
			ft_printf("Error: Map must be surrounded by walls\n");
			free_data(data);
		}
		i++;
	}
	j = 1;
	while (j < data->map_height - 1)
	{
		if (data->map[j][0] != '1' || data->map[j][data->map_width - 1] != '1')
		{
			ft_printf("Error: Map must be surrounded by walls\n");
			free_data(data);
		}
		j++;
	}
}

static void	check_map_elements(t_data *data)
{
	data->player = 0;
	data->exit = 0;
	data->collectibles = 0;
	parse_map_elements(data);
	if (data->player != 1 || data->exit != 1 || data->collectibles < 1)
	{
		ft_printf("ERROR:\n content not respected.");
		free_data(data);
	}
}

// static void	check_map(t_data *data)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y < data->map_height)
// 	{
// 		if ((int)ft_strlen(data->map[y]) != data->map_width)
// 		{
// 			ft_printf("Erro: Map is not rectangular\n");
// 			free_data(data);
// 		}
// 		x = 0;
// 		while (x < data->map_width)
// 		{
// 			if (data->map[y][x] != '1' && data->map[y][x] != '0'
// 				&& data->map[y][x] != 'C' && data->map[y][x] != 'E'
// 				&& data->map[y][x] != 'P')
// 			{
// 				ft_printf("Error: Invalid character in the map\n");
// 				free_data(data);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }
static int	check_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_height)
	{
		if ((int)ft_strlen(data->map[y]) != data->map_width)
		{
			ft_printf("Erro: Map is not rectangular\n");
			return (1);
		}
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0'
				&& data->map[y][x] != 'C' && data->map[y][x] != 'E'
				&& data->map[y][x] != 'P')
				return (ft_printf("Error: Invalid character in the map\n"),1);
			x++;
		}
		y++;
	}
	return (0);
}
static void	read_map_lines(t_data *data, int fd, char *line)
{
	while (line)
	{
		if (data->map_height >= SIZE_Y_MAP)
		{
			ft_printf("Error: Map is too large\n");
			free_data(data);
			free(line);
			return ;
		}
		data->map[data->map_height] = line;
		if (check_map(data))
		{
			free(line);
			free_data(data);
			return ;
		}
		line = get_next_line(fd);
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		data->map_height++;
	}
	data->map[data->map_height] = NULL;
	free(line);
}

int	load_map(t_data *data, int fd)
{
	char	*line;

	data->map = malloc(sizeof(char *) * (SIZE_Y_MAP + 1));
	if (!data->map)
		return (free_data(data),
			ft_printf("Error: Memory allocation failed\n"));
	line = get_next_line(fd);
	 if (!line)
    {
        free_data(data);
        ft_printf("Error: empty map or read error\n");
    }
	data->map_height = 0;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	data->map_width = ft_strlen(line);
	read_map_lines(data, fd, line);
	get_next_line(-1);
	check_map_wall(data);
	check_map_elements(data);
	game_tracking(data);
	return (1);
}
