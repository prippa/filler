/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:52:08 by prippa            #+#    #+#             */
/*   Updated: 2018/02/05 15:52:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	fil;
	char		*line;
	int			i;

	line = NULL;
	get_next_line(0, &line);
	fil.mine = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
	fil.enemy = (fil.mine == 'O') ? 'X' : 'O';
	dprintf(2, "mine - %c, enemy - %c\n", fil.mine, fil.enemy);
	free(line);
	get_next_line(0, &line);
	fi_get_y_x(line, &fil.b_y, &fil.b_x);
	dprintf(2, "y - %d, x - %d\n", fil.b_y, fil.b_x);
	free(line);

	// i = 0;
	// while (i < 20)
	// {
	// 	get_next_line(0, &line);
	// 	write(2, line, ft_strlen(line));
	// 	write(2, "\n", 1);
	// 	free(line);
	// 	i++;
	// }
	write(1, "8 2\n", 4);
	return (0);
}
