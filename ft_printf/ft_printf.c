/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:23:35 by zena              #+#    #+#             */
/*   Updated: 2025/03/17 12:29:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_conversion(char c, va_list args)
{
	unsigned long	ptr;

	if (c == 'c')
		return (write(1, &(char){va_arg(args, int)}, 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), 10, 1));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), 16, 0));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), 16, 1));
	else if (c == 'p')
	{
		ptr = (unsigned long)va_arg(args, void *);
		if (ptr == 0)
			return (write(1, "(nil)", 5));
		write(1, "0x", 2);
		return (2 + ft_putnbr_base(ptr, 16, 0));
	}
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			printed += ft_conversion(format[++i], args);
		}
		else
		{
			write(1, &format[i], 1);
			printed++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}
/*
int	main(void)
{
	ft_printf("Char: %c\n", 'A');
	ft_printf("String: %s\n", "Hello");
	ft_printf("Int: %d\n", -123);
	ft_printf("Unsigned: %u\n", 123);
	ft_printf("Hex: %x\n", 255);
	ft_printf("Pointer: %p\n", NULL);
	ft_printf("%%\n");
}*/
