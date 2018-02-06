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

int			fi_skip_line()
{
	char *line;

	if ((get_next_line(0, &line)) < 1)
		return (-1);
	free(line);
	return (1);
}

int		fi_get_board(t_filler *fil)
{
	int		i;
	char	*line;

	if ((get_next_line(0, &line)) < 1)
		return (-1);
	fi_get_y_x(line, &fil->b_y, &fil->b_x);
	free(line);
	if ((fi_skip_line()) == -1)
		return (-1);
	if (!(fil->board = (char **)malloc(sizeof(char *) * fil->b_y + 1)))
		return (-1);
	fil->board[fil->b_y] = NULL;
	i = 0;
	while (i < fil->b_y)
	{
		if ((get_next_line(0, &line)) < 1)
			return (-1);
		if (!(fil->board[i] = ft_strdup(line + 4)))
			return (-1);
		free(line);
		i++;
	}
	return (1);
}
