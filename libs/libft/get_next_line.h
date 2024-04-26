/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:19:19 by gamoraes          #+#    #+#             */
/*   Updated: 2024/02/05 02:33:05 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

size_t	ft_strlen(const char *string);

char	*ft_strcpy(char *dest, const char *src);

char	*ft_strdup(const char *str);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *string, unsigned int start, size_t length);

char	*get_next_line(int fd);

#endif
