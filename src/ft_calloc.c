/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:50:50 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/16 20:50:51 by maburnet         ###   ########.fr       */
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
