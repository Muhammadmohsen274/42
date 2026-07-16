/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:49:41 by muali             #+#    #+#             */
/*   Updated: 2025/08/15 22:12:50 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	while (dest_len < size && dest[dest_len] != '\0')
		dest_len++;
	i = dest_len;
	src_len = 0;
	while (src[src_len] != '\0' && (dest_len + 1) < size)
	{
		dest[dest_len] = src[src_len];
		dest_len++;
		src_len++;
	}
	if (i < size)
		dest[dest_len] = '\0';
	while (src[src_len] != '\0')
		src_len++;
	return (i + src_len);
}

// int main(void)
// {
//     char dest[] = "test";
//     char src[] = "test";
//     int size;
//     size = 4;

//     printf("%d", ft_strlcat(dest, src, size));
// }