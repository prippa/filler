/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:28:17 by prippa            #+#    #+#             */
/*   Updated: 2018/05/07 13:28:18 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIS_H
# define VIS_H

# include "libft.h"
# include "ft_printf.h"
# include <signal.h>

# define VIS_PLAYER_1 "😇"
# define VIS_PLAYER_2 "😈"
# define VIS_PLAYER_1_PIECE "🔵"
# define VIS_PLAYER_2_PIECE "🔴"
# define VIS_SPACE "⚫"
# define VIS_PIECE "🍰"
# define VIS_OP_CHAR ' '

# define VIS_FLAGS_SIZE 2
# define VIS_FLAG_D 0
# define VIS_FLAG_S 1

typedef	struct		s_visualizer
{
	char			*player_1;
	char			*player_2;
	int				player_1_score;
	int				player_2_score;
	char			*buf;
	int				map_y;
	int				map_x;
	int				piece_y;
	int				piece_x;
	int				i;
	int				j;
	int				sleep;
	int				bonus_flags[VIS_FLAGS_SIZE];
}					t_visualizer;

int					vis_start_entry(t_visualizer *vis);
int					vis_game(t_visualizer *vis);
void				fi_get_y_x(char *str, int *y, int *x);
int					vis_skip_line(int how_many);
void				vis_print_frame(int count, char c, char *color);
int					vis_end(t_visualizer *vis);
int					vis_the_end(t_visualizer *vis);
int					vis_print_board(t_visualizer *vis);
int					vis_print_piece(t_visualizer *vis, int flag);
int					vis_break(t_visualizer *vis);
int					vis_sound_on(int key, int flag);
int					vis_sound_off(int flag);
void				vis_sound_off_signal(int sig);
int					vis_get_bonus_flags(t_visualizer *vis, char **argv);
void				vis_print_score(t_visualizer *vis);

#endif
