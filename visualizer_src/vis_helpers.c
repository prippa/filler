/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:31:44 by prippa            #+#    #+#             */
/*   Updated: 2018/05/07 13:31:45 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		vis_skip_line(int how_many)
{
	char	*line;
	int		che;

	while (how_many && (che = get_next_line(0, &line)) > 0)
	{
		ft_str_free(&line);
		how_many--;
	}
	if (che == -1)
		return (-1);
	return (1);
}

void	vis_print_frame(int count, char c, char *color)
{
	char	buf[count + 3];
	int		i;

	ft_bzero(buf, count + 3);
	buf[0] = '|';
	buf[count + 1] = '|';
	i = 1;
	while (i < count + 1)
	{
		buf[i] = c;
		i++;
	}
	ft_printf("%s%s%s\n", color, buf, COLOR_RESET);
}
