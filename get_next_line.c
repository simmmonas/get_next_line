/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ssemanco <ssemanco@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 16:02:15 by ssemanco      #+#    #+#                 */
/*   Updated: 2021/05/21 13:36:01 by ssemanco      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int		line_break(const char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		save_line(char *str, char **line, int i)
{
	int		len;

	*line = ft_substr(str, 0, i);
	if (*line == NULL)
		return (-1);
	++i;
	len = ft_strlen(str + i) + 1;
	ft_memmove(str, str + i, len);
	return (1);
}

int		ft_reminder(char *saved_l, char **line, int rbyte)
{
	*line = ft_strdup(saved_l);
	if (*line == NULL)
		return (-1);
	free(saved_l);
	saved_l = NULL;
	return (rbyte);
}

int		get_next_line(int fd, char **line)
{
	static char		buff[BUFFER_SIZE + 1];
	static char		*saved_l;
	int				rbyte;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (line_break(saved_l) != -1)
		return (save_line(saved_l, line, line_break(saved_l)));
	rbyte = read(fd, buff, BUFFER_SIZE);
	if (rbyte < 0)
		return (-1);
	while (rbyte > 0)
	{
		buff[rbyte] = '\0';
		saved_l = ft_strjoin1(saved_l, buff);
		if (saved_l == NULL)
			return (-1);
		if (line_break(saved_l) != -1)
			return (save_line(saved_l, line, line_break(saved_l)));
		rbyte = read(fd, buff, BUFFER_SIZE);
	}
	if (saved_l)
		return (ft_reminder(saved_l, line, rbyte));
	*line = ft_strdup("");
	return (rbyte);
}

int		main(void)
{
	int		fd;
	int		i;
	char	*line;
	int 	l = 1;

	fd = open("normal.txt", O_RDONLY);
	//fd = -1;
	//fd = 0;
	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("%i | %i | %s\n ", l, i, line);
		free(line);
		l++;
	}
	system("leaks a.out");
	//close(fd);
	return (0);
		
}