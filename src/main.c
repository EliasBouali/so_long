
#include "../so_long.h"


int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	// Init la mémoire à 0 (optionnel si tout bien initialisé ailleurs)
	ft_memset(&data, 0, sizeof(t_data));

	if (argc != 2)
	{
		write(2, "Usage: ./so_long map.ber\n", 26);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error: failed to open map file");
		return (1);
	}

	if (load_map(&data, fd) != 1)
	{
		write(2, "Error: failed to load map\n", 27);
		close(fd);
		return (1);
	}
	close(fd);

	init_window(&data);
	return (0);
}
