/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 22:07:37 by muali             #+#    #+#             */
/*   Updated: 2026/07/02 01:11:11 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char spec, va_list *ap)
{
	char	c;

	if (spec == 'c')
	{
		c = (char)va_arg(*ap, int);
		return (write(1, &c, 1));
	}
	if (spec == 's')
		return (print_str(va_arg(*ap, char *)));
	if (spec == 'p')
		return (print_ptr((unsigned long)va_arg(*ap, void *)));
	if (spec == 'd' || spec == 'i')
		return (print_signed(va_arg(*ap, int)));
	if (spec == 'u')
		return (print_nbr(va_arg(*ap, unsigned int), 10, 0));
	if (spec == 'x')
		return (print_nbr(va_arg(*ap, unsigned int), 16, 0));
	if (spec == 'X')
		return (print_nbr(va_arg(*ap, unsigned int), 16, 1));
	if (spec == '%')
		return (write(1, "%", 1));
	write(1, "%", 1);
	write(1, &spec, 1);
	return (2);
}

static int	print_next(const char **format, va_list *ap)
{
	if (**format == '%' && *(++(*format)))
		return (handle_format(**format, ap));
	else if (**format != '%')
		return (write(1, *format, 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		ret = print_next(&format, &ap);
		if (ret == -1)
			return (-1);
		count += ret;
		if (*format)
			format++;
	}
	va_end(ap);
	return (count);
}

/*
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int     ret1;
    int     ret2;
    int     x;

    x = 42;

    printf("========== CHAR ==========\n");
    ret1 = printf("printf    : %c\n", 'A');
    ret2 = ft_printf("ft_printf : %c\n", 'A');
    printf("Return printf    : %d\n", ret1);
    printf("Return ft_printf : %d\n\n", ret2);

    printf("========== STRING ==========\n");
    ret1 = printf("printf    : %s\n", "Hello 42");
    ret2 = ft_printf("ft_printf : %s\n", "Hello 42");
    printf("Return printf    : %d\n", ret1);
    printf("Return ft_printf : %d\n\n", ret2);

    printf("========== NULL STRING ==========\n");
    ret1 = printf("printf    : %s\n", (char *)NULL);
    ret2 = ft_printf("ft_printf : %s\n", (char *)NULL);
    printf("Return printf    : %d\n", ret1);
    printf("Return ft_printf : %d\n\n", ret2);

    printf("========== POINTER ==========\n");
    ret1 = printf("printf    : %p\n", &x);
    ret2 = ft_printf("ft_printf : %p\n", &x);
    printf("Return printf    : %d\n", ret1);
    printf("Return ft_printf : %d\n\n", ret2);

    printf("========== NULL POINTER ==========\n");
    ret1 = printf("printf    : %p\n", (void *)NULL);
    ret2 = ft_printf("ft_printf : %p\n", (void *)NULL);

    printf("========== SIGNED ==========\n");
    ret1 = printf("printf    : %d %d %d\n", 0, INT_MAX, INT_MIN);
    ret2 = ft_printf("ft_printf : %d %d %d\n", 0, INT_MAX, INT_MIN);
    printf("Return printf    : %d\n", ret1);
    printf("Return ft_printf : %d\n\n", ret2);

    printf("========== UNSIGNED ==========\n");
    ret1 = printf("printf    : %u\n", UINT_MAX);
    ret2 = ft_printf("ft_printf : %u\n", UINT_MAX);
    printf("Return printf    : %d\n", ret1);
    printf("Return ft_printf : %d\n\n", ret2);

    printf("========== HEX LOWER ==========\n");
    ret1 = printf("printf    : %x\n", UINT_MAX);
    ret2 = ft_printf("ft_printf : %x\n", UINT_MAX);
    printf("Return printf    : %d\n", ret1);
    printf("Return ft_printf : %d\n\n", ret2);

    printf("========== HEX UPPER ==========\n");
    ret1 = printf("printf    : %X\n", UINT_MAX);
    ret2 = ft_printf("ft_printf : %X\n", UINT_MAX);
    printf("Return printf    : %d\n", ret1);
    printf("Return ft_printf : %d\n\n", ret2);

    printf("========== PERCENT ==========\n");
    ret1 = printf("printf    : %%\n");
    ret2 = ft_printf("ft_printf : %%\n");
    printf("Return printf    : %d\n", ret1);
    printf("Return ft_printf : %d\n\n", ret2);

    printf("========== MIXED ==========\n");
    ret1 = printf("printf    : %c %s %p %d %i %u %x %X %%\n",
        'Z', "FortyTwo", &x, -42, 42, 3000000000U, 48879, 48879);
    ret2 = ft_printf("ft_printf : %c %s %p %d %i %u %x %X %%\n",
        'Z', "FortyTwo", &x, -42, 42, 3000000000U, 48879, 48879);
    printf("Return printf    : %d\n", ret1);
    printf("Return ft_printf : %d\n\n", ret2);

    printf("========== EMPTY STRING ==========\n");
    ret1 = printf("");
    ret2 = ft_printf("");
    printf("\nReturn printf    : %d\n", ret1);
    printf("Return ft_printf : %d\n\n", ret2);

    printf("========== TRAILING %% ==========\n");
    ret2 = ft_printf("abc%");
    printf("\nReturn ft_printf : %d\n", ret2);

    return (0);
}
*/