/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:12:55 by luviso-p          #+#    #+#             */
/*   Updated: 2025/05/28 12:17:05 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_types(char specifier, va_list args)
{
	if (specifier == '%')
		return (ft_putchar('%'));
	else if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putnbru(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_nbr_hex((unsigned int)va_arg(args, int), specifier));
	else if (specifier == 'p')
		return (ft_nbr_pointer((unsigned long)va_arg(args, void *)));
	else
		return (ft_putchar(specifier));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			len += ft_search_types(*format, args);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	int		a;
	char	c = 'a';
	char	*str = "Hola mundo";
	int		num = 2389237;
	int		num2 = 42;

	a = ft_printf("%c\n", c);
	ft_printf("EN EL CASO DE UN CARACTER LA LONGITUD IMPRESA ES: %d\n", a);
	a = ft_printf("%s\n", str);
	ft_printf("EN EL CASO DE UN STRING LA LONGITUD IMPRESA ES: %d\n", a);
	a = ft_printf("%d\n", num2);
	ft_printf("EN EL CASO DE NUMEROS LA LONGITUD IMPRESA ES: %d\n", a);
	a = ft_printf("%p\n", str);
	ft_printf("EN EL CASO DEL PUNTERO LA LONGITUD IMPRESA ES: %d\n", a);
	a = ft_printf("%X\n", num);
	ft_printf("EN EL CASO DE NUMERO HEXADECIMAL EN MINUSCULA O 
	MAYUSCULA LA LONGITUD IMPRESA ES: %d\n", a);
	return (0);
}*/