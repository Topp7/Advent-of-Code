/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:26:56 by stopp             #+#    #+#             */
/*   Updated: 2024/12/01 15:28:15 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	get_input(int **row1, int **row2)
{
	char	*buf = malloc(14);
	FILE	*fd;
	int		i = 0;
	size_t	n;

	n = 14;
	fd = fopen("input.txt", "r");
	while (getline(&buf, &n, fd) != -1)
	{
		buf[5] = '\0';
		(*row1)[i] = atoi(buf);
		(*row2)[i] = atoi(&buf[8]);
		i++;
	}
}

void	sort_input(int *row)
{
	int	tmp;
	int	i = 0;
	int	stop = 0;

	while(row[i + 1])
	{
		if (row[i] > row[i + 1])
		{
			tmp = row[i];
			row[i] = row[i + 1];
			row[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	calc_diff(int *row1, int *row2)
{
	int	dif = 0;
	int	total_dif = 0;
	int	i = 0;

	while (row1[i])
	{
		dif = row1[i] - row2[i];
		if (dif < 0)
			dif *= -1;
		total_dif += dif;
		i++;
	}
	return (total_dif);
}

// Part One

// int	main(void)
// {
// 	int	difference;
// 	int	*row1 = malloc(sizeof(int) * 1000);
// 	int	*row2 = malloc(sizeof(int) * 1000);

// 	get_input(&row1, &row2);
// 	sort_input(row1);
// 	sort_input(row2);
// 	difference = calc_diff(row1, row2);
// 	printf("%i\n", difference);
// }

// Part Two

int	calc_sim(int *row1, int *row2)
{
	int	sim = 0;
	int	total_sim = 0;
	int	i = 0;
	int	j = 0;
	int	num_count = 0;

	while (row1[i])
	{
		j = 0;
		num_count = 0;
		while(row2[j])
		{
			if(row1[i] == row2[j])
				num_count++;
			j++;
		}
		sim = row1[i] * num_count;
		if (sim < 0)
			sim *= -1;
		total_sim += sim;
		i++;
	}
	return (total_sim);
}

int	main(void)
{
	int	similarity;
	int	*row1 = malloc(sizeof(int) * 1000);
	int	*row2 = malloc(sizeof(int) * 1000);

	get_input(&row1, &row2);
	sort_input(row1);
	sort_input(row2);
	similarity = calc_sim(row1, row2);
	printf("%i\n", similarity);
}
