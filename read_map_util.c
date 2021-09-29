#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' || s2[i] == '\0')
		return (s1[i] - s2[i]);
	return (0);
}

char	*ft_strjoin_map(char **s1, char *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;

	if (!(*s1) || !s2)
		return (0);
	arr = (char *)malloc((ft_strlen(*s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!arr)
		return (0);
	i = 0;
	while ((*s1)[i])
	{
		arr[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	free(*s1);
	(*s1) = NULL;
	return (arr);
}

void	init_map(t_map *map)
{
	(map)->col_b = 0;
	(map)->col_curr = 0;
	(map)->row = 1;
	(map)->n_e = 0;
	(map)->n_c = 0;
	(map)->n_p = 0;
}

void	error_meg(int fd, int error, char *g_map)
{
	if (fd)
		close(fd);
	if (g_map)
		free(g_map);
	ft_putstr_fd("Error\n", 2);
	if (error == -1)
		write(2, "File is not valid\n", 18);
	else if (error == -2)
		write(2, "Characters are not valid\n", 25);
	else if (error == -3)
		write(2, "Map is not a rectangular\n",25);
	else if (error == -4)
		write(2, "Map is not surrounded by wall\n",30);
	else if (error == -5)
		write(2, "Map must have at least a P, a E and a C\n",40);
	else
		write(2, "Error happaned!\n",16);
	exit(1);
}

int check_extension(char *av, char *g_map)
{
	char *str;
	str = ft_strchr(av, '.');
	if (!str)
		error_meg(0, ER_FILE, g_map);
	str++;
	if (ft_strcmp(str, "ber"))
		error_meg(0, ER_FILE, g_map);
	return (0);
}
