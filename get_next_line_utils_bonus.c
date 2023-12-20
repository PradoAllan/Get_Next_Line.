/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:13:09 by aprado            #+#    #+#             */
/*   Updated: 2023/12/20 13:16:06 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_swap(char *cake, char *buf)
{
	char	*temp;

	temp = ft_strjoin(cake, buf);
	if (!cake)
		return (temp);
	free(cake);
	return (temp);
}

int	is_complete_line(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n' || buf[i] == '\0')
			return (1);
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	int		i;
	int		j;
	char	*new;

	i = -1;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!new)
		return (NULL);
	while (++i < s1len)
		new[i] = s1[i];
	j = 0;
	while (j < s2len)
		new[i++] = s2[j++];
	new[s1len + s2len] = '\0';
	return (new);
}

char	*ft_strdup(char *s)
{
	size_t	strlen;
	size_t	i;
	char	*dup;

	i = 0;
	strlen = ft_strlen(s);
	if (strlen == 0)
		return (NULL);
	dup = (char *)malloc((strlen + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < strlen)
		dup[i++] = *s++;
	dup[strlen] = '\0';
	return (dup);
}
