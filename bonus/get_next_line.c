/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:06:03 by maburnet          #+#    #+#             */
/*   Updated: 2023/10/03 23:09:11 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

char	*ft_strjoin(char *tmp, char *buf)
{
	char	*ptr;

	if (!tmp)
	{
		tmp = (char *)malloc(1 * sizeof(char));
		if (!tmp)
			return (NULL);
		tmp[0] = '\0';
	}
	if (!tmp || !buf)
		return (NULL);
	ptr = (char *)malloc((1 + ft_strlen(tmp) + ft_strlen(buf)) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_strjoin2(ptr, tmp, buf);
	free(tmp);
	return (ptr);
}

char	*ft_strjoin2(char *ptr, char *s1, char *s2)
{
	int	i;
	int	a;

	i = 0;
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	a = 0;
	while (s2 && s2[a])
	{
		ptr[i + a] = s2[a];
		a++;
	}
	ptr[i + a] = '\0';
	return (ptr);
}

char	*get_next_line(int fd, int *nb_bytes)
{
	int		buffer_size;
	char	*tmp;
	char	*buf;

	buffer_size = 1;
	tmp = NULL;
	buf = (char *)malloc(sizeof(char) * (buffer_size + 1));
	if (!buf)
		return (NULL);
	while (*nb_bytes != 0)
	{
		*nb_bytes = read(fd, buf, buffer_size);
		if (*nb_bytes == -1 || (*nb_bytes == 0 && tmp == NULL))
			return (free(buf), tmp);
		buf[*nb_bytes] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (tmp == NULL)
			return (NULL);
		if (buf[0] == '\n')
			break ;
	}
	free(buf);
	return (tmp);
}
