/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_sounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:29:18 by prippa            #+#    #+#             */
/*   Updated: 2018/05/07 13:29:19 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int		vis_sound_off(int flag)
{
	if (!flag)
		return (0);
	system("killall iTunes");
	return (1);
}

void	vis_sound_off_signal(int sig)
{
	if (sig == 2)
	{
		vis_sound_off(1);
		exit(0);
	}
}

int		vis_sound_on(int key, int flag)
{
	if (!flag)
		return (0);
	if (key == 1)
		system("open -j sounds/Mortal_Kombat_main_song.mp3");
	return (1);
}
