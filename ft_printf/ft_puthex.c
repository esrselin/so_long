/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:51:23 by esakgul           #+#    #+#             */
/*   Updated: 2025/07/09 16:24:56 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_puthex_rec(unsigned long n, char *base)
{
	unsigned int	res;

	res = 0;
	if (n >= 16)
		res += ft_puthex_rec(n / 16, base);
	res += write(1, &base[n % 16], 1);
	return (res);
}

unsigned int	ft_puthex(unsigned long n, char type)
{
	unsigned int	res;

	res = 0;
	if (type == 'p')
	{
		if (!n)
			return (ft_putstr("(nil)"));
		res += write(1, "0x", 2);
		res += ft_puthex_rec(n, "0123456789abcdef");
	}
	else if (type == 'x')
		res += ft_puthex_rec(n, "0123456789abcdef");
	else if (type == 'X')
		res += ft_puthex_rec(n, "0123456789ABCDEF");
	return (res);
}
