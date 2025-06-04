/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouali <ebouali@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:54:34 by ebouali           #+#    #+#             */
/*   Updated: 2025/06/01 17:54:36 by ebouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = malloc(len1 + len2 + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < len1)
		dst[i] = s1[i];
	i = -1;
	while (++i < len2)
		dst[len1 + i] = s2[i];
	dst[len1 + len2] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*copy;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		copy = (char *)malloc(1);
		if (!copy)
			return (NULL);
		copy[0] = '\0';
		return (copy);
	}
	if (len > s_len - start)
		len = s_len - start;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (i < len)
		copy[i++] = s[start++];
	copy[i] = '\0';
	return (copy);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	int		len;
	char	*copy;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/*char	**get_left_c_addr(void)
{
    static char	*left_c = NULL;
    return (&left_c);
}*/

