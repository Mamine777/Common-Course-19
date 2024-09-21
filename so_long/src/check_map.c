/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:43:39 by mokariou          #+#    #+#             */
/*   Updated: 2024/09/18 17:50:31 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_character(char c)
{
	if (c != 'P' && c != '1' && c != 'C' && c != '0' && c != 'E')
	{
		printf("wopwoop🗺️, found undefined characters, fix the map please..\n");
		return (1);
	}
	return (0);
}

static int	count_lines(char *buffer)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			line++;
		i++;
	}
	return (line);
}

int	checkmap(int fd)
{
	char	*buffer;
	int		index;

	while ((buffer = get_next_line(fd)) != NULL)
	{
		if (buffer[0] == '\0')
		{
			free(buffer);
			break ;
		}
		index = 0;
		while (buffer[index])
		{
			if (check_character(buffer[index]) == 1)
			{
				free(buffer);
				close(fd);
				exit(1);
			}
			index++;
		}
		free(buffer);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	fd;
	(void) ac;

	fd = open(av[1], O_RDONLY);
	printf("%d", checkmap(fd));
}
