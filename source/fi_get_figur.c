/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_get_figur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:12:15 by prippa            #+#    #+#             */
/*   Updated: 2018/02/06 12:12:16 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fi_get_figur(t_filler *fil)
{
	int		i;
	char	*line;

	if ((get_next_line(0, &line)) < 1)
		return (-1);
	fi_get_y_x(line, &fil->f_y, &fil->f_x);
	free(line);
	if (!(fil->figur = (char **)malloc(sizeof(char *) * fil->f_y + 1)))
		return (-1);
	fil->figur[fil->f_y] = NULL;
	i = 0;
	while (i < fil->f_y)
	{
		if ((get_next_line(0, &line)) < 1)
			return (-1);
		if (!(fil->figur[i] = ft_strdup(line)))
			return (-1);
		free(line);
		i++;
	}
	return (1);
}
