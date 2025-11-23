/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:14:59 by esakgul           #+#    #+#             */
/*   Updated: 2025/11/19 19:41:22 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	last;

	last = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + last));
	while (last > 0)
	{
		if (s[last - 1] == (char)c)
			return ((char *)(s + last - 1));
		last--;
	}
	return (NULL);
}

int has_ber_extension(char *filename)
{
    char *dot;

    dot = ft_strrchr(filename, '.'); 
    if (!dot)
        return (0);
    return (ft_strncmp(dot, ".ber", 4) == 0);
}

