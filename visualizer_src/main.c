/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_vis_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:47:59 by prippa            #+#    #+#             */
/*   Updated: 2018/03/15 15:48:00 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	fi_vis_init(t_visualizer *vis)
{
	vis->buf = NULL;
	vis->player_1 = NULL;
	vis->player_2 = NULL;
}

int		fi_vis_error(char *message)
{
	ft_printf("%s\n", message);
	return (-1);
}

void	fi_vis_free(t_visualizer *vis)
{
	ft_str_free(&vis->buf);
	ft_str_free(&vis->player_1);
	ft_str_free(&vis->player_2);
}

int		main(void)
{
	t_visualizer	vis;
	int				i;

	fi_vis_init(&vis);
	if (!(fi_vis_start_entry(&vis)))
		return (fi_vis_error("ERROR: in start entry"));
	ft_printf("%s\n%s\n", vis.player_1, vis.player_2);
	// while (get_next_line(0, &str) > 0)
	// {
	// 	ft_printf("%s\n", str);
	// 	if (ft_strstr(str, "got"))
	// 	{
	// 		usleep(100000);
	// 		ft_clear();
	// 	}
	// 	free(str);
	// }
	fi_vis_free(&vis);
	return (0);
}
