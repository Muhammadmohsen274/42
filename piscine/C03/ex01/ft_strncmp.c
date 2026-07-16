/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:54:34 by muali             #+#    #+#             */
/*   Updated: 2025/08/14 15:27:41 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	else
	{
		while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		{
			i++;
		}
		if (s1[i] == s2[i])
		{
			return (0);
		}
		else
		{
			return (s1[i] - s2[i]);
		}
	}
}

// int	main(void)
// {
// 	char str_1[] = "ABCDE";
// 	char str_2[] = "ABC";
// 	int n;
// 	n = 4;

// 	printf("result = %d ", ft_strncmp(str_1, str_2, n));
// }