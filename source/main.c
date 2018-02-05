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
	i = 0;
	while (i < 20)
	{
		get_next_line(0, &line);
		write(2, line, ft_strlen(line));
		write(2, "\n", 1);
		free(line);
		i++;
	}
	write(1, "8 2\n", 4);
	return (0);
}
