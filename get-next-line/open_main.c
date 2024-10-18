/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:57:07 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/18 15:18:37 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!fd)
		{
			return (0);
		}
		while (1)
		{
			line = get_next_line(fd);
			printf("%s", line);
			if (line == NULL)
				break ;
			free(line);
			line = NULL;
		}
		free(line);
		close(fd);
	}
}
