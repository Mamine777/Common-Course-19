/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:02:18 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/16 15:28:18 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_da_sep(char s, char c)
{
	return (c == s);
}

static int	calcu_da_len(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && find_da_sep(str[i], sep))
			i++;
		if (str[i])
			count++;
		while (str[i] && !find_da_sep(str[i], sep))
			i++;
	}
	return (count);
}

static int	len_for_dup(char const *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && !find_da_sep(str[i], sep))
		i++;
	return (i);
}

static char	*dup_it(char const *str, char c)
{
	int		i;
	int		len;
	char	*tab;

	len = len_for_dup(str, c);
	i = 0;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (calcu_da_len(s, c) + 1));
	if (!tab)
		return (free(tab), NULL);
	while (*s)
	{
		while (*s && find_da_sep(*s, c))
			s++;
		if (*s)
		{
			tab[i] = dup_it(s, c);
			if (!tab[i++])
				return (free(tab), NULL);
		}
		while (*s && !find_da_sep(*s, c))
			s++;
	}
	tab[i] = NULL;
	return (tab);
}

// #include "libft.h"
// #include <stdio.h>
//
// void run_test(const char *input, char sep) {
//     char **result = ft_split(input, sep);
//     if (!result) {
//         printf("ft_split(%s, %c) returned NULL 
//				(expected for invalid input).\n", input, sep);
//         return;
//     }
//     for (int i = 0; result[i]; i++) {
//         printf("Result[%d]: %s\n", i, result[i]);
//         free(result[i]); // Free each allocated string
//     }
//     free(result); // Free the array of strings
// }
//
// int main() {
//     // Test cases that can cause segmentation faults or errors

//     // 1. NULL string
//     run_test(NULL, ' '); // Expect NULL
//
// //     // 2. Empty string
// //     run_test("", ' '); // Expect an empty array
//
// //     // 3. String with only separators
// //     run_test("~~~~~", '~'); // Expect an empty array
//
//     // 4. String with multiple separators at the beginning
//     run_test("~~~~hello~~~~world~~~~", '~'); // Expect ["hello", "world"]
//
//     // 5. String with multiple separators at the end
//     run_test("hello~~~world~~~~", '~'); // Expect ["hello", "world"]
//
//     // 6. String with single character
//     run_test("A", 'A'); // Expect [""]
//
//     // 7. Separator character is empty
//     run_test("abc", '\0'); // Undefined behavior
//
//     // 8. Very long string
//     char long_string[1000];
//     ft_memset(long_string, 'a', 999);
//     long_string[999] = '\0';
//     run_test(long_string, 'a'); // Expect []
//
//     // 9. Separator that does not exist in the string
//     run_test("hello world", ','); // Expect ["hello world"]
//
//     // 10. String with only one word
//     run_test("singleword", ' '); // Expect ["singleword"]
//
//     // 11. String with separators only
//     run_test(" ", ' '); // Expect []
//
//     // 12. Large number of separators
//     run_test(",,,,,,,,,,,,,,,,,,,,", ','); // Expect []
//
// //     // 13. String with leading spaces
// //     run_test("   leading spaces", ' '); // Expect ["leading", "spaces"]
//
// //     // 14. String with trailing spaces
// //     run_test("trailing spaces   ", ' ');
// }