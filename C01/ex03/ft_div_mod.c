/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:57:34 by muali             #+#    #+#             */
/*   Updated: 2025/08/05 21:10:40 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}

// int	main(void)
// {
// 	int	a;
// 	int	b;
// 	int	division;
// 	int	modulus;

// 	a = 10;
// 	b = 8;
// 	ft_div_mod(a, b, &division, &modulus);
// }
