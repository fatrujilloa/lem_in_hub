/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:39:54 by ftrujill          #+#    #+#             */
/*   Updated: 2019/10/11 11:59:03 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void        mbfs(int **g, int size, int *ngbs, int l, t_layer *layer) //Modified Breadth First Search
{
    int     *visited;

    visited = (int*)ft_memalloc(size * sizeof(int));
    while(layer->sol == 0 || layer->sol_depth != l)
        layer = next_layer(g, size, ngbs, layer, visited);
}

void        initialize(t_layer *layer)
{
    layer->nbr_paths = 1;
    layer->paths = (int**)malloc(2 * sizeof(int*));
    layer->paths[0] = (int*)malloc(2 * sizeof(int));
    layer->paths[1] = NULL; //Needed? 
    layer->paths[0][0] = 0;
    layer->paths[0][1] = -1; //Needed? 
    layer->vertex = (int*)malloc(2 * sizeof(int));
    layer->vertex[0] = 0;
    layer->vertex[1] = -1;
    layer->max_depths = (int*)malloc(2 * sizeof(int));
    layer->max_depths[0] = 0;
    layer->max_depths[1] = -1;
    layer->depths = (int**)malloc(2 * sizeof(int*));
    layer->depths[0] = (int*)malloc(2 * sizeof(int));
    layer->depths[1] = NULL; //Needed? 
    layer->depths[0][0] = 1;
    layer->depths[0][1] = -1; //Needed? 
    layer->sol = 0;
    layer->sol_depth = 0;
}

void        initialize_new_layer(t_layer *new_layer, int *ngbs)
{
    int     i;
    int     s;
    int     v;

    i = -1;
    s = 0;
    while ((v = layer->vertex[++i]) != -1)
        s += ngbs[v];
    new_layer->nbr_paths = 0;
    new_layer->paths = (int**)malloc((s + 1) * sizeof(int*));
    new_layer->paths[s + 1] = NULL; //Needed? 
    new_layer->vertex = (int*)malloc((s + 1) * sizeof(int));
    new_layer->vertex[s + 1] = -1; //Needed? 
    new_layer->depths = (int*)malloc((s + 1) * sizeof(int));
    new_layer->depths[s + 1] = -1; //Needed? 
    new_layer->max_depths = (int**)malloc((s + 1) * sizeof(int*));
    new_layer->max_depths[s + 1] = NULL; //Needed? 
    new_layer->sol = layer->sol;
    new_layer->sol_depth = layer->sol_depth;

}

void        add_path(t_layer *new_layer, t_layer *layer, int *visited, int i, int w) //Add the path layer->paths[i] + w to the new_layer
{
    int n;
    int depth;
    int j;

    n = new_layer->nbr_paths;
    depth = layer->max_depths[i];
    new_layer->paths[n] = (int*)malloc((depth + 1) * sizeof(int));
    j = -1;
    while (++j < depth)
        new_layer->paths[n][j] = layer->paths[n][j];
    new_layer->paths[n][j] = w;
    new_layer->vertex[n] = w;
    new_layer->max_depths[n] = depth + 1;
    new_layer->nbr_paths += 1;
    if (w == size - 1)
    {
        new_layer->sol = 1;
        if (new_layer->sol_depth > depth + 1)
            new_layer->sol_depth = depth + 1;
    }
}

void        update(t_layer *new_layer, int *visited, int *updated, int size)
{
    int i;
    int j;
    int k;
    int n;
    int depth;

    i = -1;
    n = new_layer->nbr_paths;
    while (++i < size)
    {
        if (updated[i] != 0)
        {
            j = -1;
            while (++j < n)
            {
                depth = new_layer->max_depths[j]
                k = -1;
                while (++k < depth)
                {
                    if (new_layer->paths[j][k] == i && new_layer->depths[j][k] > visited[i])
                        {
                            new_layer->paths[j][depth - 1] = size - 1;
                            new_layer->vertex[j] = size - 1;
                            new_layer->max_depths[j] = 2 * size;
                        }
                }
            }
        }   
    }
}

t_layer     *next_layer(int **g, int size, int *ngbs, t_layer *layer, int *visited)
{
    int         i;
    int         j;
    int         w;
    int         *updated;
    t_layer     *new_layer;

    updated = (int*)ft_memalloc(size * sizeof(int));
    new_layer = (t_layer*)malloc(sizeof(t_layer));
    initialize_new_layer(new_layer, ngbs);
    i = -1;
    while (++i < layer->vertex[i] != -1)
    {
        if (updated[layer->vertex[i]] != 0)
            continue ;
        else if (layer->vertex[i] == size - 1)
            (layer->max_depths[i] == layer->sol_depth && new_layer->sol == 0) ? 
            add_path(new_layer, layer, visited, i, w) : continue ;
        j = -1;
        while ((w = g[i][++j]) != -1)
        {
            else if (visited[w] == 0))
                add_path(new_layer, layer, visited, i, w);
            else if (visited[w] > layer->max_depths[i] + CAPACITY(v, w))
                {
                    add_path(new_layer, layer, visited, layer->vertex[i], w);
                    visited[w] = layer->max_depths[i] + CAPACITY(v, w);
                    updated[w] = 1;
                }
        }
    }
    update(new_layer, visited, updated, size);
    return (new_layer);
}

int         main()
{
    t_layer layer;
    int     **g;
    int     *ngbs;
    int     size;
    
    initialize(&layer);
    mbfs(g, size, ngbs, l, &layer);
    return (0);
}