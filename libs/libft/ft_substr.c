/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:10:48 by gamoraes          #+#    #+#             */
/*   Updated: 2023/10/26 15:21:46 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t length)
{
	size_t	size;
	size_t	substrlen;
	char	*substr;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	substrlen = size - (size_t) start;
	if (start > size)
		return ((char *)malloc(1 * sizeof(char)));
	if (length > size)
		length = (size - start) + 1;
	if (substrlen > length)
		substrlen = length;
	substr = (char *)malloc((substrlen + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strcpy(substr, (s + start));
	return (substr);
}
