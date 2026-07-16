/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:30:48 by muali             #+#    #+#             */
/*   Updated: 2025/08/19 17:50:36 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*ptr;
	int		i;

	i = 1;
	while (i < argc)
	{
		ptr = argv[i];
		while (*ptr)
		{
			write(1, ptr, 1);
			ptr++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
