/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:24:29 by aprado            #+#    #+#             */
/*   Updated: 2023/12/20 15:30:23 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	new_line_len(char *cake)
{
	int	i;

	i = 0;
	if (!cake)
		return (i);
	while (cake[i] != '\0')
	{
		if (cake[i++] == '\n')
			return (i);
	}
	return (i);
}

char	*get_right_cake(char *cake)
{
	int		i;
	int		final_cake_len;
	char	*final_cake;

	i = 0;
	if (!cake)
		return (NULL);
	final_cake_len = new_line_len(cake);
	final_cake = malloc(sizeof(char) * (final_cake_len + 1));
	if (!final_cake)
		return (NULL);
	final_cake[final_cake_len] = '\0';
	while (i < final_cake_len)
	{
		final_cake[i] = cake[i];
		i++;
	}
	free(cake);
	return (final_cake);
}

int	chars_read_check(int chars_read, char *buf)
{
	if (chars_read == -1)
	{
		free(buf);
		return (1);
	}
	return (0);
}

char	*gnl_core(int fd)
{
	int			chars_read;
	char		*piece;
	char		*temp;
	static char	*cake;

	piece = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!piece)
		return (NULL);
	chars_read = 1;
	while (chars_read != 0)
	{
		chars_read = read(fd, piece, BUFFER_SIZE);
		if (chars_read_check(chars_read, piece))
			return (NULL);
		piece[chars_read] = '\0';
		cake = free_swap(cake, piece);
		if (is_complete_line(piece))
			break ;
	}
	free(piece);
	if (!cake || ft_strlen(cake) == 0)
		return (NULL);
	temp = cake;
	cake = ft_strdup(&cake[new_line_len(cake)]);
	return (get_right_cake(temp));
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	return (gnl_core(fd));
}
