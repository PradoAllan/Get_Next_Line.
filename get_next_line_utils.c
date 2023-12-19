/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:13:09 by aprado            #+#    #+#             */
/*   Updated: 2023/12/19 12:59:35 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int	s1len;
	int	s2len;
	int	i;
	int	j;
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
