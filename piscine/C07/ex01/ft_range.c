/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:26:57 by muali             #+#    #+#             */
/*   Updated: 2025/08/20 12:47:04 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	size;
	int	*arr;

	if (min >= max)
		return (NULL);
	size = max - min;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	ptr = arr;
	while (min < max)
	{
		*ptr = min;
		ptr++;
		min++;
	}
	return (arr);
}

// int	main(void)
// {
// 	int	min;
// 	int	max;
// 	int	i;
// 	int	*range;

// 	min = 1;
// 	max = 10;
// 	i = 0;
// 	while (i < max - min)
// 	{
// 		range = ft_range(min, max);
// 		printf("%d", range[i]);
// 		i++;
// 	}
// 	free(range);
// }
