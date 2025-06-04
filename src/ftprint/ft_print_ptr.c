/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouali <ebouali@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:31:25 by ebouali           #+#    #+#             */
/*   Updated: 2025/04/16 18:31:28 by ebouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// Fonction récursive pour afficher un entier en base 16
static int	ft_putptr_base(uintptr_t n)
{
	char	*hex;
	int		count;
	int		res;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		res = ft_putptr_base(n / 16);
		if (res == -1)
			return (-1);
		count += res;
	}
	res = write(1, &hex[n % 16], 1);
	if (res == -1)
		return (-1);
	return (count + res);
}

// Fonction principale
int	ft_print_ptr(void *ptr)
{
	int	count;
	int	res;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	res = ft_putptr_base((uintptr_t)ptr);
	if (res == -1)
		return (-1);
	return (count + res);
}
