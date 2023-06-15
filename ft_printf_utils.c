/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:26:36 by msoriano          #+#    #+#             */
/*   Updated: 2023/06/15 18:22:06 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_decimal(int nb, int *length)
{
	if (nb == -2147483648)
	{
		ft_decimal(nb / 10, lenght);
		write(1, "8", 1);
	}
	if (number < 0)
	{
		write(1, "-", length);
		ft_decimal(-nb, length);
	}
	else
	{
		if (number > 9)
			ft_decimal(nb / 10, length);
		write(1, (nb % 10 + '0'), length);
	}
	return (lenght(nb, 10));
}
void ft_pointer()
{

}
void ft_hexadecimal()
{

}
void ft_string(char *args, int *length)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		ft_string("(null)");
		return (6);
	}
	while (args[i] != '\0')
	{
		write(1, &args[i], length);
		i++;
	}
}
void ft_unsignedint(unsigned int u, int *lenght)
{
	if (u >= 10)
	ft_unsigned_int(u / 10, length);
	write(1, (u % 10 + '0'), lenght);
}
