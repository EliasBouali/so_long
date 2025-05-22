#include "../so_long.h"
void	message_error(char *message)
{
	ft_printf("%s", message);
	exit(0);
}


int	load_textures(t_data *data)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	// data->img_wall = mlx_xpm_file_to_image(data->mlx, "../textures/wall.xpm",
	// 		&w, &h);
	// data->img_floor = mlx_xpm_file_to_image(data->mlx, "../textures/floor.xpm",
	// 		&w, &h);
	// data->img_player = mlx_xpm_file_to_image(data->mlx,
	// 		"../textures/player.xpm", &w, &h);
	// data->img_collectible = mlx_xpm_file_to_image(data->mlx,
	// 		"../textures/collectible.xpm", &w, &h);
	// data->img_exit = mlx_xpm_file_to_image(data->mlx, "../textures/exit.xpm",
	// 		&w, &h);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "../textures/wall.xpm",
			&w, &h);
	data->img_floor = mlx_xpm_file_to_image(data->mlx, "../textures/wall.xpm",
			&w, &h);
	data->img_player = mlx_xpm_file_to_image(data->mlx,
			"../textures/wall.xpm", &w, &h);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx,
			"../textures/wall.xpm", &w, &h);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "../textures/wall.xpm",
			&w, &h);
	if (!data->img_wall || !data->img_floor || !data->img_collectible
		|| !data->img_exit || !data->img_player)
		message_error("ERROR: Failed to load one or more texture(s)\n");
	return (1);
}

void ft_put_picture(t_data *data, void *mlx, void *win, char **map_valid)
{
  if (map_valid[data->mapv_height][data->mapv_width] == '1')
    mlx_put_image_to_window(mlx, win, data->img_wall, data->mapv_width * PICTURE_SIZE,
        data->mapv_height * PICTURE_SIZE);
  else if (map_valid[data->mapv_height][data->mapv_width] == '0')
    mlx_put_image_to_window(mlx, win, data->img_floor, data->mapv_width * PICTURE_SIZE,
        data->mapv_height * PICTURE_SIZE);
  else if (map_valid[data->mapv_height][data->mapv_width] == 'C')
    mlx_put_image_to_window(mlx, win, data->img_collectible,
        data->mapv_width * PICTURE_SIZE, data->mapv_height * PICTURE_SIZE);
  else if (map_valid[data->mapv_height][data->mapv_width] == 'E')
    mlx_put_image_to_window(mlx, win, data->img_exit,
        data->mapv_width * PICTURE_SIZE, data->mapv_height * PICTURE_SIZE);
  else if (map_valid[data->mapv_height][data->mapv_width] == 'P')
    mlx_put_image_to_window(mlx, win, data->img_player,
        data->mapv_width * PICTURE_SIZE, data->mapv_height * PICTURE_SIZE);
}

void    *ft_memset(void *s, int c, size_t n)
{
        unsigned char           *a;
        size_t                          i;

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

