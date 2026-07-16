/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmichel <anmichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:48:50 by anmichel          #+#    #+#             */
/*   Updated: 2025/08/10 22:09:31 by anmichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_extend(int array[4][4], int brett[16], int row);

int	win_check(int array[4][4], int brett[16], int row)
{
	if (!(array[row][3] == array[row][2] || array[row][3] == array[row][1]
			|| array[row][3] == array[row][0]))
	{
		if (!(array[row][2] == array[row][1] || array[row][2] == array[row][0]))
		{
			if (!(array[row][1] == array[row][0]))
			{
				if (check_extend(array, brett, row))
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

int	check_row(int array[4][4], int brett[16], int row)
{
	int	count[2];

	count[0] = 1;
	count[1] = 1;
	if (array[row][1] > array[row][0])
		count[0]++;
	if (array[row][2] > array[row][1] && array[row][2] > array[row][0])
		count[0]++;
	if (array[row][3] > array[row][2] && array[row][3] > array[row][1]
		&& array[row][3] > array[row][0])
		count[0]++;
	if (array[row][2] > array[row][3])
		count[1]++;
	if (array[row][1] > array[row][2] && array[row][1] > array[row][3])
		count[1]++;
	if (array[row][0] > array[row][1] && array[row][0] > array[row][2]
		&& array[row][0] > array[row][3])
	{
		count[1]++;
	}
	if (count[0] == brett[8 + row] && count[1] == brett[12 + row])
	{
		return (1);
	}
	return (0);
}

int	check_column(int array[4][4], int brett[16], int row)
{
	int	count[2];

	count[0] = 1;
	count[1] = 1;
	if (array[1][row] > array[0][row])
		count[0]++;
	if (array[2][row] > array[1][row] && array[2][row] > array[0][row])
		count[0]++;
	if (array[3][row] > array[2][row] && array[3][row] > array[1][row]
		&& array[3][row] > array[0][row])
		count[0]++;
	if (array[2][row] > array[3][row])
		count[1]++;
	if (array[1][row] > array[2][row] && array[1][row] > array[3][row])
		count[1]++;
	if (array[0][row] > array[1][row] && array[0][row] > array[2][row]
		&& array[0][row] > array[3][row])
	{
		count[1]++;
	}
	if (count[0] == brett[row] && count[1] == brett[4 + row])
	{
		return (1);
	}
	return (0);
}

int	check_extend(int array[4][4], int brett[16], int row)
{
	if (!(array[3][row] == array[2][row] || array[3][row] == array[1][row]
			|| array[3][row] == array[0][row]))
	{
		if (!(array[2][row] == array[1][row] || array[2][row] == array[0][row]))
		{
			if (!(array[1][row] == array[0][row]))
			{
				if (check_row(array, brett, row) && check_column(array, brett,
						row))
				{
					return (1);
				}
			}
		}
	}
	return (0);
}
