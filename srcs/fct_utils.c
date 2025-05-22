#include "../so_long.h"

void  free_picture(t_data *data)
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

static void free_window(t_data *data)
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

int close_window(t_data *data)
{
  free_data(data);
  return (0);
}

void free_data(t_data *data)
{
  free_picture(data);
  free_window(data);
  free(data);
  exit(0);
}
