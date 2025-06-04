/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouali <ebouali@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:51:14 by ebouali           #+#    #+#             */
/*   Updated: 2025/06/01 17:51:17 by ebouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	print_usage_error(void)
{
	ft_printf("Usage: ./so_long maps/filename.ber\n");
	return (1);
}

static int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("Error: failed to open map file");
	return (fd);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < (n - 1) && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	is_ber_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 2)
		return (print_usage_error());
	if (!is_ber_file(argv[1]))
	{
		ft_printf("Error: file must have .ber extension\n");
		return (1);
	}
	fd = open_map_file(argv[1]);
	if (fd < 0)
		return (1);
	if (load_map(&data, fd) != 1)
	{
		ft_printf("Error: failed to load map\n");
		close(fd);
		return (1);
	}
	close(fd);
	data.collectibles_find = 0;
	data.map_valid[data.exit_y][data.exit_x] = '0';
	init_window(&data);
	return (0);
}
