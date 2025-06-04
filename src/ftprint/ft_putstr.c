/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouali <ebouali@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:32:12 by ebouali           #+#    #+#             */
/*   Updated: 2025/04/18 16:25:41 by ebouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_putstr(char *s)
{
	int	i;
	int	result;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		result = write(1, &s[i], 1);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}
