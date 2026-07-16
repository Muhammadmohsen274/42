/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmichel <anmichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:47:30 by anmichel          #+#    #+#             */
/*   Updated: 2025/08/10 22:16:59 by anmichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ascii_from_int(int n, int space);

void	counter(int array[4][4], int row);

int		win_check(int array[4][4], int brett[16], int row);

void	game_board_printer(int array[4][4]);


int	while_counter(int array[4][4], int brett[16])
{
	int	win[8];

	array[0][0] = 0;
	while (array[0][0] <= 4)
	{
		array[0][0]++;
		counter(array, 0);
		counter(array, 1);
		counter(array, 2);
		counter(array, 3);
		win[0] = win_check(array, brett, 0);
		win[1] = win_check(array, brett, 1);
		win[2] = win_check(array, brett, 2);
		win[3] = win_check(array, brett, 3);
		if (win[0] && win[1] && win[2] && win[3])
		{
			game_board_printer(array);
			return (0);
		}
	}
	write(1, "Error\n", 6);
	return (0);
}

void	counter(int array[4][4], int row)
{
	if (array[row][0] == 5)
	{
		array[row][0] = 1;
		array[row][1]++;
	}
	if (array[row][1] == 5)
	{
		array[row][1] = 1;
		array[row][2]++;
	}
	if (array[row][2] == 5)
	{
		array[row][2] = 1;
		array[row][3]++;
	}
	if (array[row][3] == 5)
	{
		array[row][3] = 1;
		array[row + 1][0]++;
		if (row == 3)
		{
			array[0][0] = 6;
		}
	}
}

void	game_board_printer(int array[4][4])
{
	int	i;

	i = -1;
	while (i++ < 3)
		ascii_from_int(array[0][i], i);
	write(1, "\n", 1);
	i = -1;
	while (i++ < 3)
		ascii_from_int(array[1][i], i);
	write(1, "\n", 1);
	i = -1;
	while (i++ < 3)
		ascii_from_int(array[2][i], i);
	write(1, "\n", 1);
	i = -1;
	while (i++ < 3)
		ascii_from_int(array[3][i], i);
}
