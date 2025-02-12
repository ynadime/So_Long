#include "so_long.h"

size_t	init_map(t_data *data, char *map_path)
{
	ssize_t	fd;
	size_t	i;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), 1);
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		return (perror("Error\n"), 1);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		data->map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!data->map[i])
			return (perror("Error\n"), free_map(data));
		i++;
	}
	data->map[i] = NULL;
	close(fd);
	return (0);
}

size_t	count_lines(char *map_path, t_data *data)
{
	ssize_t	fd;
	size_t	lines;
	char	*line;

	lines = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), 1);
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Error\nYour file is empty!"), 1);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->height = lines;
	return (0);
}

void	load_map(char *map_path, t_data *data)
{
	if (count_lines(map_path, data) || !(data->height))
		exit(1);
	if (init_map(data, map_path))
		exit(1);
}
