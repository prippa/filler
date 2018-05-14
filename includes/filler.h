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

# include "libft.h"
# include "ft_printf.h"

# define Y 			fil->i
# define X 			fil->j

typedef	struct		s_point
{
	int				touched_y;
	int				touched_x;
	int				point_y;
	int				point_x;
	int				radius;
	int				y_up;
	int				y_down;
	int				x_left;
	int				x_right;
	int				y;
	int				x;
	struct s_point	*next;
}					t_point;

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
	int				point_y;
	int				point_x;
	int				game;
	int				i;
	int				j;
	t_point			*point;
}					t_filler;

void				fi_get_y_x(char *str, int *x, int *y);
int					fi_get_board(t_filler *fil);
int					fi_get_figur(t_filler *fil);
int					fi_get_points(t_filler *fil);

int					fi_get_radius(t_filler *fil, t_point *tmp);
void				fi_algorithm(t_filler *fil);

void				fi_point_free(t_filler *fil);
int					fi_point_add(t_filler *fil);

#endif
