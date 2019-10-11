/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:39:26 by ftrujill          #+#    #+#             */
/*   Updated: 2019/10/11 16:52:49 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct      s_path
{
    int     endpoint;
    int     depth;
    int     *path;
    int     *depths;
}                   t_path;

typedef struct      s_layer
{
    int     size;
    int     nbr_paths;
    int     sol_depth;
    int     sol;
    t_path  *paths;
}                   t_layer;

typedef struct      s_solution
{
    int     nbr_paths;
    int     **used_vertices;
    t_path  *paths;
}                   t_solution;

#endif