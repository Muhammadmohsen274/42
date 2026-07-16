/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:06:55 by muali             #+#    #+#             */
/*   Updated: 2025/08/14 14:50:15 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	if (s1[i] == s2[i])
	{
		return (0);
	}
	else
		return (s1[i] - s2[i]);
}

// int main()
// {
//     char str_1[] = "ABE";
//     char str_2[] = "ABC";

//     printf("result = %d ",ft_strcmp(str_1, str_2));
// }