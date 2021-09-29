#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "./mlx_linux/mlx.h"


#define ER_FILE -1
#define ER_CHAR -2
#define ER_RECTAN -3
#define ER_WALL -4
#define ER_ELE -5
#define ERRO -6
#define PH_WALL "./img/wall.xpm"
#define PH_FLOOR2 "./img/floor2.xpm"
#define PH_DIAMON "./img/diamond.xpm"
#define PH_EXIT "./img/exit.xpm"
#define PH_PLAYER "./img/player.xpm"
#define PH_EX_PY "./img/exit_player.xpm"

// char	*g_map;

typedef struct s_map {
   int	col_b;
   int	col_curr;
   int	row;
   int	n_e;
   int	n_c;
   int	n_p;
}	t_map; 


int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin_map(char **s1, char *s2);
void	init_map(t_map *map);
void	error_meg(int fd, int error, char *g_map);
int check_extension(char *av, char *g_map);
int		check_character(int fd, char c, char *g_map);
int		parse_map(int fd, char **g_map);
int check_wall(int fd, t_map *map,char *g_map);
int	check_elem(int fd, t_map *map,char *g_map);
int	check_map(int fd, t_map *map,char *g_map);
t_map read_map(char *av, char **g_map);

