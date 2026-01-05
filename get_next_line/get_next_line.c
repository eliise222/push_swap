/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srezzaq <srezzaq@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:16:22 by srezzaq           #+#    #+#             */
/*   Updated: 2025/11/25 14:50:31 by srezzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <stdio.h>

char	*ft_join_free_buffer(char *buffer, char *file)
{
	char	*ret;

	ret = ft_strjoin(buffer, file);
	free(buffer);
	return (ret);
}

char	*ft_delete_line(char *buffer)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	ret = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
	{
		ret[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (ret);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_file(int fd, char *ret)
{
	char	*buffer;
	int		a;

	if (!ret)
		ret = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	a = 1;
	while (a > 0)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			free(buffer);
			free(ret);
			return (NULL);
		}
		buffer[a] = 0;
		ret = ft_join_free_buffer(ret, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_delete_line(buffer);
	return (line);
}

// int main()
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char *a;
// 	// while ((a = get_next_line(fd)))
// 	// {
// 	// 	printf("%s", a);
// 	// }
// 	// printf("%s", get_next_line(fd)); 
//     //  printf("%s", get_next_line(fd));
//     //  printf("%s", get_next_line(fd));
// 	return 0;
// } 
