/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 00:35:16 by muali             #+#    #+#             */
/*   Updated: 2026/07/04 01:41:15 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_nbr(unsigned long long n, int base, int is_upper)
{
	char	*digits;
	char	buf[25];
	int		i;
	int		len;

	if (is_upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	i = 0;
	if (n == 0)
		buf[i++] = '0';
	while (n > 0)
	{
		buf[i++] = digits[n % base];
		n /= base;
	}
	len = i;
	while (i > 0)
		write(1, &buf[--i], 1);
	return (len);
}

int	print_signed(int n)
{
	int				len;
	unsigned int	num;

	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		len = 1;
		num = -n;
	}
	else
		num = n;
	return (len + print_nbr(num, 10, 0));
}

int	print_ptr(unsigned long ptr)
{
	if (!ptr)
		return (print_str("(nil)"));
	write(1, "0x", 2);
	return (2 + print_nbr(ptr, 16, 0));
}
