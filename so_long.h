/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:04:19 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/22 11:48:29 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include <X11/X.h>
# include <fcntl.h>

typedef struct s_coin
{
	int		x;
	int		y;
	int		col;
	void	*img;
	char	*addr;
	int		bbp;
	int		l_len;
	int		end;
	int		o_w;
	int		o_h;
	int		n_w;
	int		n_h;
}	t_coin;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bbp;
	int		l_len;
	int		end;
	int		n_w;
	int		n_h;
	int		o_w;
	int		o_h;
	int		w_w;
	int		w_h;
	int		s_x;
	int		s_y;
	int		s_w;
	int		s_h;
	int		c_c;
	int		n_c;
	t_coin	*c;
	int		e_x;
	int		e_y;
	char	**map;
	int		count;
}	t_data;

#endif