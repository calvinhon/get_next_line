/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:24:54 by chon              #+#    #+#             */
/*   Updated: 2024/08/14 17:05:57 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	if (!ptr)
		return (NULL);
	while (*ptr && *ptr != (char)c)
		ptr++;
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;

	if (!dest && !src)
		return (dest);
	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	while (n > 0)
	{
		*dest_ptr++ = *src_ptr++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len + s2_len == 0)
		return (NULL);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	ft_memcpy(str, s1, s1_len);
	i += s1_len;
	ft_memcpy(str + i, s2, s2_len);
	i += s2_len;
	str[i] = '\0';
	free(s1);
	return (str);
}
