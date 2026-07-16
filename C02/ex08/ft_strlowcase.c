/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 23:28:41 by muali             #+#    #+#             */
/*   Updated: 2025/08/11 23:31:41 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char str[] = "AbCdEF";
//     ft_strlowcase(str);

// 	write(1, &str, 4);
// }