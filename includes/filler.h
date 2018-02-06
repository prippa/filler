/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:51:31 by prippa            #+#    #+#             */
/*   Updated: 2018/02/05 15:51:35 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf.h"
# include "get_next_line.h"

# define Y 			fil->i
# define X 			fil->j

typedef	struct		s_filler
{
	char			mine;
	char			enemy;
	char			**board;
	int				b_x;
	int				b_y;
	char			**figur;
	int				f_x;
	int				f_y;
	int				i;
	int				j;
	int				point_y;
	int				point_x;
}					t_filler;

void				fi_get_y_x(char *str, int *x, int *y);
int					fi_get_board(t_filler *fil);
int					fi_get_figur(t_filler *fil);
int					fi_skip_line();
void				fi_algo(t_filler *fil);

#endif
