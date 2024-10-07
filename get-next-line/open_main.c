/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:57:07 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/07 11:52:08 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	fd;
	int	line;

	line = 1;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!fd)
		{
			return (0);
		}
		while (line < 3)
		{
			printf("%d->%s", line++, get_next_line(fd));
		}
		close(fd);
	}
}
