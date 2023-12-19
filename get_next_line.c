/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:24:29 by aprado            #+#    #+#             */
/*   Updated: 2023/12/19 13:47:48 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*free_swap(char *cake, char *buf)
{
	char	*temp;

	temp = ft_strjoin(cake, buf);
	//free(temp);
	//com o free(temp), ao chamar a gnl pela segunda vez, da erro.
	return (temp);
}

int	is_complete_line(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n' || buf[i] == '\0')
			return (0);
	}
	return (1);
}

int	new_line_len(char *cake)
{
	int	i;

	i = 0;
	while (cake[i] != '\n')
		i++;
	return (i);
}

char	*get_right_cake(char *cake)
{
	int	i;
	int	final_cake_len;
	char	*final_cake;

	i = 0;
	final_cake_len = new_line_len(cake);
	final_cake = malloc(sizeof(char) * (final_cake_len + 1));
	if (!final_cake)
		return (NULL);
	final_cake[final_cake_len] = '\0';
	while (i <= final_cake_len)
	{
		final_cake[i] = cake[i];
		i++;
	}
	return (final_cake);
}

char	*get_next_line(int fd)
{
	int	chars_read;
	char	*buf;
	char	*temp;
	static char	*cake;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	chars_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (chars_read != 0 && is_complete_line(buf))
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[chars_read] = '\0';
		cake = free_swap(cake, buf);
	}
	free(buf);
	temp = cake;
	cake = &cake[new_line_len(cake) + 1];
	return (get_right_cake(temp));
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("teste.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("<--MAIN-->\n:%s:\n", str);
	free(str);
	str = get_next_line(fd);
	printf("<--MAIN-->\n:%s:\n", str);
	free(str);
	close(fd);
	return (0);
}
