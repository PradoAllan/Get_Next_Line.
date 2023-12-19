/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:13:36 by aprado            #+#    #+#             */
/*   Updated: 2023/12/19 14:50:20 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *s);
char	*ft_strdup(char *s);

#endif
