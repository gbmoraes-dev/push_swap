/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:51:04 by gamoraes          #+#    #+#             */
/*   Updated: 2023/12/20 15:49:31 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	ft_putnbr(int nb);

int	ft_putnbr_uns(unsigned int nb);

int	ft_puthx(unsigned int hx, char *base);

int	ft_putptr(unsigned long ptr, char *base);

int	ft_checkformat(char type, va_list arg);

int	ft_printf(const char *format, ...);

#endif
