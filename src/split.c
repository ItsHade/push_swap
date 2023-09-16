/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:47:18 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/16 20:47:32 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		mem;
	void	*ptr;

	mem = size * nmemb;
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (mem / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, mem);
	return (ptr);
}

int	ft_wordcount(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != '\0')
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

int	ft_getwordlen(char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

void	ft_freemalloc(char **strs, int a)
{
	while (a >= 0)
	{
		free(strs[a]);
		a--;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		a;
	int		b;
	char	**strs;

	i = 0;
	a = -1;
	strs = ft_calloc(sizeof(char *), (ft_wordcount((char *)s, c) + 1));
	if (!strs)
		return (NULL);
	while (++a < ft_wordcount((char *)s, c))
	{
		b = 0;
		while (s[i] && s[i] == c)
			i++;
		strs[a] = ft_calloc(sizeof(char), (ft_getwordlen((char *)s, c, i) + 1));
		if (!strs[a])
		{	
			ft_freemalloc(strs, a);
			return (NULL);
		}
		while (s[i] && s[i] != c)
			strs[a][b++] = s[i++];
	}
	strs[a] = ft_calloc(sizeof(char), 1);
	return (strs);
}
