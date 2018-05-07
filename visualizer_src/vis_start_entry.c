/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_start_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:30:38 by prippa            #+#    #+#             */
/*   Updated: 2018/05/07 13:30:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static char	*vis_get_player(char *str)
{
	int i;
	int j;

	str = ft_strchr(str, '[');
	i = 1;
	j = 1;
	while (str[i])
	{
		if (str[i] == '.')
			return (ft_strsub(str, j, i - j));
		else if (str[i] == '/')
			j = i + 1;
		i++;
	}
	return (NULL);
}

static int	vis_while_body(t_visualizer *vis, int i)
{
	if (i == 6)
	{
		if (!(vis->player_1 = vis_get_player(vis->buf)))
			return (-1);
	}
	else if (i == 8)
	{
		if (!(vis->player_2 = vis_get_player(vis->buf)))
			return (-1);
	}
	return (1);
}

static int	vis_preparation_for_the_game(t_visualizer *vis)
{
	ft_str_free(&vis->buf);
	ft_str_to_upper(&vis->player_1);
	ft_str_to_upper(&vis->player_2);
	if ((get_next_line(0, &vis->buf)) == -1)
		return (-1);
	fi_get_y_x(vis->buf, &vis->map_y, &vis->map_x);
	ft_str_free(&vis->buf);
	return (1);
}

int			vis_start_entry(t_visualizer *vis)
{
	int		i;
	int		catch_error;

	i = 0;
	while (i < 9 && (catch_error = get_next_line(0, &vis->buf)) > 0)
	{
		if ((vis_while_body(vis, i)) == -1)
			return (-1);
		ft_str_free(&vis->buf);
		i++;
	}
	if (catch_error == -1)
		return (-1);
	if ((vis_preparation_for_the_game(vis)) == -1)
		return (-1);
	return (1);
}
