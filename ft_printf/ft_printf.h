/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:52:14 by esakgul           #+#    #+#             */
/*   Updated: 2025/07/09 16:33:10 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_putchar(char c);
int				ft_putnbr(int n);
unsigned int	ft_unbr(unsigned int n);
int				ft_putstr(char *str);
unsigned int	ft_puthex(unsigned long n, char type);
int				verifier(char c);
int				printer(char c, va_list args);
int				ft_printf(const char *s, ...);

#endif
