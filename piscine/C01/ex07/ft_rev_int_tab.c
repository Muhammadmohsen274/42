/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:26:18 by muali             #+#    #+#             */
/*   Updated: 2025/08/05 21:04:43 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while (i < size / 2)
	{
		swap = tab[i];
		tab[i] = tab[size - i -1];
		tab[size - i -1] = swap;
		i++;
	}
}

// int	main(void)
// {
// 	int	arr[] = {1, 2, 3, 4, 5, 6};
// 	int	size;

// 	size = 6;
// 	ft_rev_int_tab(arr, size);
// }
