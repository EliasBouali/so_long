#include "../so_long.h"

static void check_map_wall(t_data *data)
{
  int i;
  int j;

  i = 0;
  while (i < data->map_width)
  {
    if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1')
      message_error("Error: Map must be surrounded by walls\n");
    i++;
  }
  j = 0;
  while (j < data->map_height - 1)
  {
    if (data->map[j][0] != '1' || data->map[j][data->map_width - 1] != '1')
      message_error("Error: Map must be surrounded by walls\n");
    j++;
  }
}

/*static void add_character(t_data *data, char c, int map_width, int map_height)
{
  if (c == 'P')
  {
    data->player++;
    data->player_x = map_width;
    data->player_y = map_height;
  }
  if (c == 'C')
    data->collectibles++;
  if (c == 'E')
  {
    data->exit++;
    data->exit_x = map_width;
    data->exit_y = map_height;
  }
}*/

static void check_map_elements(t_data *data )
{
  if (data->player < 1)
    message_error("Error: There must be one player in the map\n");
  if (data->exit < 1)
    message_error("Error: There must be one exit in the map\n");
  if (data->collectibles < 1)
    message_error("Error: There must be at least one collectible in the map\n");
}

static void check_map(t_data *data)
{
  int y;
  int x;

  y = 0;
  while (y < data->map_height)
  {
    if ((int)ft_strlen(data->map[y]) != data->map_height)
      message_error("Erro: Map is not rectangular\n");
    x = 0;
    while (x < data->map_width)
    {
      if (data->map[y][x] != '1' && data->map[y][x] != '0' && data->map[y][x] != 'C' && data->map[y][x] != 'E' && data->map[y][x] != 'P')
        message_error("Error: Invalid character in the map\n");
      x++;
    }
    y++;
  }
}

int load_map(t_data *data, int fd)
{
  char *line;

  data->map = malloc(sizeof(char *) * SIZE_Y_MAP );
  if (!data->map)
    message_error("Error: Memory allocation failed\n");
  line = get_next_line(fd);
  data->map_height = 0;
  while (line)
  {
    if (data->map_height >= SIZE_Y_MAP)
    {
      message_error("Error: Map is too large\n");
      free(line);
    }
    printf("%s",line);
    data->map[data->map_height] = line;
    check_map(data);
    line = get_next_line(fd);
    break;
  }
  free(line);
  data->map[data->map_height] = NULL;
  check_map_wall(data);
  check_map_elements(data);
  return (1);
}
