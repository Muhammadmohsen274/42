/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:51:19 by muali             #+#    #+#             */
/*   Updated: 2025/08/11 22:50:41 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a'
					&& str[i] <= 'z')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// int main(void)
// {
//     char only_alpha[] = "ACDR";
//     char res;

//     res = ft_str_is_alpha(only_alpha) + '0';
//     write(1, &res, 1);
// }