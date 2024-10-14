/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:49:14 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/14 17:16:28 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search_str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)search_str)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (search_str == '\0')
		return ((char *)str + i);
	return (NULL);
}

/*#include <stdio.h>
int	main()
{
	char *s = "toma hello ooe ";
	char c = 97;
	printf("%s\n", ft_strchr(s, c)); // passing str + i to printf it 
	//prints everything from I to \0
}*/