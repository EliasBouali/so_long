#ifndef SO_LONG_H
#define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1023
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

# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{	void	*mlx;
	void	*window;
	void	*image;
	char	**map;
  int		map_height;
	int		map_width;
  char  **map_valid;
  int   mapv_height;
  int   mapv_width;
	int		player_x;
	int		player_y;
  int   player;
  int   exit;
  int   exit_x;
  int   exit_y;
	int		collectibles;
	int		moves;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
}               t_data;

void  init_window(t_data *data);
int load_map(int fd, t_data *data);
void  free_picture(t_data *data);
int close_window(t_data *data);
void free_data(t_data *data);
void	message_error(char *message);
void	load_textures(t_data *data, void *mlx);
void ft_put_picture(t_data *data, void *mlx, void *win, char **map_valid);
char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int	ft_print_ptr(void *ptr);
int	ft_put_unsigned(unsigned int n);
int	ft_putchar(char c);
int	ft_puthex(unsigned int n, int is_upper);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_count(const char *format, int i, va_list args);
int	ft_printf(const char *format, ...);

#endif
