/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:50:22 by muali             #+#    #+#             */
/*   Updated: 2025/08/20 12:46:59 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*str_cpy(char *str, char *dest)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * i);
	if (!dest)
		return (NULL);
	return (str_cpy(src, dest));
}

// int	main(void)
// {
// 	char	str[] = "Robotics";

// 	write(1, ft_strdup(str), 8);
// }
