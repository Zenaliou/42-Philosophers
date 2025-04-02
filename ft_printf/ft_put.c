/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:24:12 by niclee            #+#    #+#             */
/*   Updated: 2025/03/17 12:30:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	while (s[count])
		count++;
	return (write(fd, s, count));
}

int	ft_putnbr_fd(int n, int fd)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	count += write(fd, &c, 1);
	return (count);
}

int	ft_putnbr_base(unsigned long nbr, int base, int uppercase)
{
	char	digit;
	int		count;

	count = 0;
	if (nbr >= (unsigned long)base)
		count += ft_putnbr_base(nbr / base, base, uppercase);
	if (nbr % base < 10)
		digit = '0' + (nbr % base);
	else
	{
		if (uppercase)
			digit = 'A' + (nbr % base - 10);
		else
			digit = 'a' + (nbr % base - 10);
	}
	write(1, &digit, 1);
	return (count + 1);
}
