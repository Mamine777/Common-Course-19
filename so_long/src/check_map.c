/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:43:39 by mokariou          #+#    #+#             */
/*   Updated: 2024/09/28 13:36:23 by mokariou         ###   ########.fr       */
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

	buffer = get_next_line(fd);
	while (buffer != NULL && buffer[0] != '\0')
	{
		index = 0;
		while (buffer[index])
		{
			if (check_character(buffer[index]) == 1)
			{
				free(buffer);
				close(fd);
				return (1);
			}
			index++;
		}
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (0);
}
