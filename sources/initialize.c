/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:05:55 by ftrujill          #+#    #+#             */
/*   Updated: 2019/10/16 12:07:11 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void        initialize(t_layer *layer, int size)
{
    t_path  *path;

    layer->size = size;
    layer->nbr_paths = 1;
    layer->sol_depth = size + 1;
    layer->min_depth = 1;
    layer->paths = (t_path*)malloc(sizeof(t_path));
    path = layer->paths;
    path->endpoint = 0;
    path->depth = 1;
    path->path = (int*)malloc(2 * sizeof(int));
    path->path[0] = 0;
    path->path[1] = -1;
    path->depths = (int*)malloc(2 * sizeof(int));
    path->depths[0] = 1;
}

void        initialize_new_layer(t_layer *new_layer, t_layer *layer, int *ngbs)
{
    int     i;
    int     s;
    int     v;

    i = 0;
    s = 0;
    while (i < layer->nbr_paths)
        s += ngbs[layer->paths[i++].endpoint];
    new_layer->nbr_paths = 0;
    new_layer->paths = (t_path*)malloc((s + 1) * sizeof(t_path));
    new_layer->size = layer->size;
    new_layer->sol_depth = layer->size + 1;
    //new_layer->min_depth = layer->min_depth;
}