/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:24:29 by aprado            #+#    #+#             */
/*   Updated: 2023/12/19 16:13:23 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	int	i;
	int	final_cake_len;
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
	while (chars_read != 0)
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[chars_read] = '\0';
		cake = free_swap(cake, buf);
		if (is_complete_line(buf))
			break;
	}
	free(buf);
	if (!cake)
		return (NULL);
	if (ft_strlen(cake) == 0)
		return (NULL);
	temp = cake;
	cake = ft_strdup(&cake[new_line_len(cake)]);
	return (get_right_cake(temp));
}

/*
int	main(void)
{
	int	fd;
	char	*str;

	fd = open("teste.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("<--MAIN-->\n:%s", str);
	free(str);
	str = get_next_line(fd);
	printf("<--MAIN-->\n:%s:\n", str);
	free(str);
	str = get_next_line(fd);
	printf("\n%s\n", str);
	free(str);

	close(fd);
	return (0);
}
*/
