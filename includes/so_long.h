#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"
# ifdef __linux__
   # include "./mlx_linux/mlx.h"
# else
   # include <mlx.h>
# endif

# ifdef __linux__
#  define KEY_W		119
#  define KEY_A		97
#  define KEY_S		115
#  define KEY_D		100
#  define KEY_ESC	   65307
#  define OS         1
# else
#  define KEY_W		13
#  define KEY_S		1
#  define KEY_A		0
#  define KEY_D		2
#  define KEY_ESC	53
#  define OS   0
# endif

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

typedef struct	s_position 
{
	int		p;
	int		x;
	int		y;
	int		col;
    int		row;

}		t_position;

typedef struct s_allimg
{
	void	*wall;
	void	*floor;
	void	*diamond;
	void	*exit;
	void	*player;
	void	*ex_pl;
	t_position *position;
	void	*mlx;
	void	*win;
	char	*g_map;
}	t_allimg;

typedef struct s_w {
	void	*mlx;
	void	*win;
}	t_w;

void destroy(t_allimg **allimg);
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

void	init_postion(t_map *map, t_position **position, char *g_map);
void	init_img(t_allimg **allimg, t_w	*w_p, t_map *map, char *g_map);
void	initial_map(t_map *map, t_w	*w_p,t_allimg **allimg, char *g_map);
void new_imgandpostion(t_allimg **allimg, int *step,int current, int p, int x1, int x2, int y1, int y2);
void free_all(t_allimg **allimg);
int check_gmap(char *g_map);
int	handle_input(int key, t_allimg **allimg);
int	close_game(int keycode, t_allimg *allimg);
int	close_game_mouse(t_allimg *allimg);
void	in_the_windows(t_map *map,char	*g_map);



