/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:57:55 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 15:57:57 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int fd, int n)
{
	if (n == -2147483648)
	{
		ft_putchar_fd(fd, '-');
		ft_putchar_fd(fd, '2');
		ft_putnbr_fd(fd, 147483648);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd(fd, '-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(fd, n / 10);
		ft_putnbr_fd(fd, n % 10);
	}
	else
		ft_putchar_fd(fd, n + '0');
}
