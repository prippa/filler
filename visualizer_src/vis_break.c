/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_break.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:28:54 by prippa            #+#    #+#             */
/*   Updated: 2018/05/07 13:28:57 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		vis_break(t_visualizer *vis)
{
	while (42)
	{
		vis_print_pice(vis, 0);
		ft_str_free(&vis->buf);
		if ((get_next_line(0, &vis->buf)) == -1)
			return (-1);
		if (ft_strstr(vis->buf, "Plateau"))
			return (1);
		else if (ft_strstr(vis->buf, "fin"))
			return (vis_the_end(vis));
	}
	return (1);
}
