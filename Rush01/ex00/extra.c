/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmichel <anmichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:46:29 by anmichel          #+#    #+#             */
/*   Updated: 2025/08/10 22:17:18 by anmichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	inpt_conv(int brett[16], char *inpt);

void	ascii_from_int(int n, int space)
{
	char	ascii_conved;

	ascii_conved = n + 48;
	write(1, &ascii_conved, 1);
	if (space != 3)
	{
		write(1, " ", 1);
	}
}

void	inpt_conv(int brett[16], char *inpt)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		brett[i] = inpt[i * 2] - 48;
		i++;
	}
}
