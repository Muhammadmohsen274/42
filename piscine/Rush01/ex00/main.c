/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmichel <anmichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:01:00 by anmichel          #+#    #+#             */
/*   Updated: 2025/08/10 22:17:30 by anmichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ascii_from_int(int n, int space);

void	inpt_conv(int brett[16], char *inpt);

int		while_counter(int array[4][4], int brett[16]);

void	counter(int array[4][4], int row);

void	game_board_printer(int array[4][4]);

int		win_check(int array[4][4], int brett[16], int row);

int		check_row(int array[4][4], int brett[16], int row);

int		check_column(int array[4][4], int brett[16], int row);

int		check_extend(int array[4][4], int brett[16], int row);

int	main(int numb, char *inpt[1])
{
	int	array[4][4];
	int	brett[16];
	int	i;
	int	j;

	numb++;
	inpt_conv(brett, inpt[1]);
	i = 0;
	j = 0;
	while (i < 4 && j < 4)
	{
		while (j < 4)
		{
			array[i][j] = 1;
			j++;
		}
		j = 0;
		i++;
	}
	while_counter(array, brett);
	write(1, "\n", 1);
	return (0);
}
