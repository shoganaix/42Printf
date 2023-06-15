/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:26:36 by msoriano          #+#    #+#             */
/*   Updated: 2023/06/15 17:47:53 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static void ft_formatcheck(char c, va_list args, int *result)
{
    if(c == 's')
        ft_string(va_arg(args, char*), result);
    else if(c == 'p')
        ft_pointer(va_arg(args, size_t*), result);
    else if(c == 'd' || c == 'i')
        ft_decimal(va_arg(args, int*), result);
    else if(c == 'u')
        ft_unsignedint(va_arg(args, unsigned int*), result);
    else if(c == 'x')
        ft_hexadecimal(va_arg(args, unsigned int*), result, 'X');
    else if(c == 'X')
        ft_hexadecimal(va_arg(args, unsigned int*), result, 'x');
	/*
	else if(c == 'c' || c == '%')
	result = result + write(1, c, 1);
	*/
}

int ft_printf(char const *format, ...)
//format porque este será el formato
{
	int result;
	va_list args;

	//va_list es un tipo especial de variable para manejar argumentos cambiables y/o variables
    va_start(args, format);
	result = 0;
	// esto es necesario para procesar estos argumentos
	while(*format)
	{
		//Se mira el carácter actual para ver si es una especificación de formato o un carácter normal
		if(*format == '%')
		//Se analiza para determinar el tipo de formato
		{
			//result = vprintf(format, args);
			format ++;
			ft_formatcheck(*format, args, &result);
		}
		else
			result = result + write(1,format, 1);
		//se imprime tal cual
	format ++;
	}
	// vprintf es una funcion que toma una cadena de formato y una lista de args
	//y la imprime según "format"

	 va_end(args);
	 // para termianr de procesar los datos
	return result;
}

/*
#include <stdio.h>

int main()
{
    int num = 123;
    char *str = "Hello, world!";

    ft_printf("Testing ft_printf:\n");
    ft_printf("Integer: %d\n", num);
    ft_printf("String: %s\n", str);
    ft_printf("Hexadecimal: %x\n", num);
    ft_printf("Character: %c\n", 'A');
    ft_printf("Percent sign: %%\n");

	printf("Testing ft_printf:\n");
    printf("Integer: %d\n", num);
    printf("String: %s\n", str);
    printf("Hexadecimal: %x\n", num);
    printf("Character: %c\n", 'A');
    printf("Percent sign: %%\n");
}
*/
