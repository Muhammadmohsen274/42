/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:54:56 by muali             #+#    #+#             */
/*   Updated: 2025/08/18 12:59:28 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (res);
	while (nb > 0)
	{
		res *= nb;
		nb--;
	}
	return (res);
}

// int	main(void)
// {
// 	int	n;

// 	n = 5;
// 	printf("%d", ft_iterative_factorial(n));
// }
