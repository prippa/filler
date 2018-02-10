/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_get_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:54:17 by prippa            #+#    #+#             */
/*   Updated: 2018/02/06 11:54:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			fi_mem_board(t_filler *fil)
{
	char	*line;

	if ((get_next_line(0, &line)) < 1)
		return (-1);
	fi_get_y_x(line, &fil->b_y, &fil->b_x);
	free(line);
	if ((get_next_line(0, &line)) < 1)
		return (-1);
	free(line);
	if (!fil->board)
	{
		if (!(fil->board = (char **)malloc(sizeof(char *) * fil->b_y + 1)))
			return (-1);
		Y = 0;
		while (Y <= fil->b_y)
		{
			fil->board[Y] = NULL;
			Y++;
		}
	}
	return (1);
}

int		fi_get_board(t_filler *fil)
{
	char	*line;

	if ((fi_mem_board(fil)) == -1)
		return (-1);
	Y = 0;
	while (Y < fil->b_y)
	{
		if ((get_next_line(0, &line)) < 1)
			return (-1);
		if (fil->board[Y])
			free(fil->board[Y]);
		if (!(fil->board[Y] = ft_strdup(line + 4)))
			return (-1);
		free(line);
		Y++;
	}
	return (1);
}
