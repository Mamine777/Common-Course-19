/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:33:53 by mokariou          #+#    #+#             */
/*   Updated: 2024/09/09 17:49:08 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcat(char	*dest, char	*src, unsigned int num_of_bytes)
{
	unsigned int	slen;
	unsigned int	dlen;
	unsigned int	i;
	unsigned int	j;

	slen = strlen(src);
	dlen = strlen(dest);
	j = dlen;
	if (num_of_bytes == 0 || dlen >= num_of_bytes)
		return (slen + num_of_bytes);
	while (src[i] && i < num_of_bytes - dlen - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (slen + dlen);
}

int	main()
{
	char *src = "hello you";
	char dest[300] = "toma";

	printf("%d", ft_strlcat(dest, src, 300));
}