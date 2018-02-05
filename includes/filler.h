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

typedef	struct		s_filler
{
	char			**board;
	int				b_x;
	int				b_y;
	char			**figur;
	int				f_x;
	int				f_y;
	int				i;
	int				j;
}					t_filler;

#endif
