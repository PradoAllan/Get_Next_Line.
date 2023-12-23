/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:54:05 by aprado            #+#    #+#             */
/*   Updated: 2023/12/23 13:39:05 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*add_piece(char *cake, char *piece)
{
	char	*new_cake;

	new_cake = ft_strjoin(cake, piece);
	free(cake);
	return (new_cake);
}

static char	*cut_cake(char *cake)
{
	char	*final_cake;
	int		i;

	i = 0;
	while (cake[i] && cake[i] != '\n')
		i++;
	if (cake[i] == '\n')
		i++;
	final_cake = malloc(sizeof(char) * (i + 1));
	if (!final_cake)
		return (NULL);
	final_cake[i] = '\0';
	while (i--)
		final_cake[i] = cake[i];
	if (final_cake[0] == '\0')
	{
		free(final_cake);
		return (NULL);
	}
	return (final_cake);
}

static char	*extra_piece(char *cake)
{
	char	*new_cake;
	int		i;

	i = 0;
	while (cake[i] && cake[i] != '\n')
		i++;
	if (cake[i] == '\n')
		i++;
	if (cake[i] == '\0')
	{
		free(cake);
		return (NULL);
	}
	new_cake = ft_strdup(&cake[i]);
	free(cake);
	return (new_cake);
}

static char	*get_next_line_core(int fd)
{
	static char	*cake;
	char		*piece;
	char		*right_cake;
	int			chars_read;

	chars_read = 1;
	piece = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!piece)
		return (NULL);
	while (chars_read > 0 && (!cake || !ft_strchr(cake, '\n')))
	{
		chars_read = read(fd, piece, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(piece);
			return (NULL);
		}
		piece[chars_read] = '\0';
		cake = add_piece(cake, piece);
	}
	free(piece);
	right_cake = cut_cake(cake);
	cake = extra_piece(cake);
	return (right_cake);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	return (get_next_line_core(fd));
}
