/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:39:26 by ftrujill          #+#    #+#             */
/*   Updated: 2019/10/16 12:20:04 by ftrujill         ###   ########.fr       */
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
    int     min_depth;
    t_path  *paths;
}                   t_layer;

typedef struct      s_solution
{
    int     size;
    int     nbr_paths;
    int     max_length;
    int     **used_vertices;
    t_path  *paths;
}                   t_solution;

/*
** Initialization
*/
void                initialize(t_layer *layer, int size);
/*
** Printing
*/
void                prt_g(int **g, int size);
void                prt_path(t_path *path);
void                prt_layer(t_layer *layer);
void                prt_solution(t_solution *solution);
void                prt_possible(t_path **possible);
/*
** Copying
*/
void                copy_path(t_path *source, t_path *dest);
void                copy_solution(t_layer *new_layer, t_path *path);
/*
** Algorithm
*/ 
void                initialize_new_layer(t_layer *new_layer, t_layer *layer, int *ngbs);

#endif