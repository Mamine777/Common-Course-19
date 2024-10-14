/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:44:20 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/12 21:35:02 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strrchr(const char *str, int c)
{
	size_t			i;
	unsigned char	search_char;

	i = ft_strlen(str);
	search_char = (unsigned char)c;
	while (i > 0)
	{
		if ((unsigned char)str[i - 1] == search_char)
			return (&str[i - 1]);
		i--;
	}
	if (search_char == '\0')
		return (&str[i]);
	return (NULL);
}

/*#include <stdio.h>
int	main()
{
	char *s = "toma hello ooe ";
	char c = 't';
	printf("%s\n", ft_strrchr(s, c)); // passing str + i to printf it 
									//prints everything from I to \0
}*/