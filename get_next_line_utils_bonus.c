/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:57:32 by aprado            #+#    #+#             */
/*   Updated: 2023/12/22 11:05:15 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (s)
		while (s[len])
			len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	int		i;
	int		j;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (s1 && i < s1len)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && j < s2len)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(char *s)
{
	int		strlen;
	int		i;
	char	*dup;

	i = 0;
	strlen = ft_strlen(s);
	dup = (char *)malloc((strlen + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < strlen)
		dup[i++] = *s++;
	dup[strlen] = '\0';
	return (dup);
}
