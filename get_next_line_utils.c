/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ssemanco <ssemanco@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 18:21:36 by ssemanco      #+#    #+#                 */
/*   Updated: 2020/12/10 16:50:19 by ssemanco      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char			*copy;
	unsigned int	i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (copy == 0)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*strj;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	strj = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (strj == NULL || !s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		strj[i] = s1[i];
		i++;
	}
	free(s1);
	s1 = NULL;
	j = 0;
	while (s2[j] != '\0')
	{
		strj[i + j] = s2[j];
		j++;
	}
	strj[i + j] = '\0';
	return (strj);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	subs = (char *)malloc(sizeof(*s) * (len + 1));
	if (subs == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			subs[j] = s[i];
			j++;
		}
		i++;
	}
	subs[j] = '\0';
	return (subs);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if ((!dst && !src) || len == 0)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((char *)dst)[i] = ((char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
