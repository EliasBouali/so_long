#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef SIZE_X_MAP
#  define SIZE_X_MAP 80
# endif
# ifndef SIZE_Y_MAP
#  define SIZE_Y_MAP 45
# endif
# ifndef PICTURE_SIZE
#  define PICTURE_SIZE 64
# endif

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*image;
	char	**map;
	int		map_height;
	int		map_width;
	char	**map_valid;
	int		mapv_height;
	int		mapv_width;
	int		player_x;
	int		player_y;
	int		player;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		exit_find;
	int		collectibles;
	int		collectibles_find;
	int		moves[4][2];
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	int		walk;
}			t_data;

void		init_window(t_data *data);
int			load_map(t_data *data, int fd);
void		free_picture(t_data *data);
int			close_window(t_data *data);
void		free_data(t_data *data);
int			load_textures(t_data *data, void *mlx);
void		ft_put_picture(t_data *data, void *mlx, void *win,
				char **map_valid);
char		*get_next_line(int fd);
//char	**get_left_c_addr(void);
//void	free_gnl_static(void);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
int			ft_print_ptr(void *ptr);
int			ft_put_unsigned(unsigned int n);
int			ft_putchar(char c);
int			ft_puthex(unsigned int n, int is_upper);
int			ft_putnbr(int n);
int			ft_putstr(char *s);
int			ft_count(const char *format, int i, va_list args);
int			ft_printf(const char *format, ...);
void		*ft_memset(void *s, int c, size_t n);
void		game_tracking(t_data *data);
void		handle_map_char(t_data *data, char c, int x, int y);
void		parse_map_elements(t_data *data);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
