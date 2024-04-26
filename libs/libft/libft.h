/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:18:12 by gamoraes          #+#    #+#             */
/*   Updated: 2024/04/26 00:03:22 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "get_next_line.h"

typedef struct s_int_valid
{
	int			value;
	int			err;
}	t_int_valid;

/*
** Part 1 Functions
*/

t_int_valid	ft_atoi_list(const char *nptr);
int			ft_atoi(const char *nptr);
void		ft_bzero(void *string, size_t length);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int character);
int			ft_isalpha(int character);
int			ft_isascii(int character);
int			ft_isdigit(int character);
int			ft_isprint(int character);
void		*ft_memcpy(void *dest, const void *src, size_t length);
int			ft_memcmp(const void *s1, const void *s2, size_t length);
void		*ft_memmove(void *dest, const void *src, size_t length);
void		*ft_memset(void *string, int character, size_t length);
size_t		ft_strlcat(char *dest, const char *src, size_t length);
void		*ft_memchr(const void *string, int character, size_t length);
size_t		ft_strlcpy(char *dest, const char *src, size_t length);
char		*ft_strdup(const char *string);
size_t		ft_strlen(const char *string);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *string, int character);
char		*ft_strchr(const char *string, int character);
int			ft_strncmp(const char *s1, const char *s2, size_t length);
int			ft_tolower(int character);
int			ft_toupper(int character);

/*
** Part 2 Functions
*/

char		*ft_substr(char const *string, unsigned int start, size_t length);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *string, char character);
char		*ft_itoa(int number);
char		*ft_strmapi(char const *string, char (*f)(unsigned int, char));
void		ft_striteri(char *string, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char character, int fd);
void		ft_putstr_fd(char *string, int fd);
void		ft_putendl_fd(char *string, int fd);
void		ft_putnbr_fd(int number, int fd);

/*
** Bonus Functions
*/

/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
*/

#endif
