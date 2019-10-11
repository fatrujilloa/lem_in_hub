/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:39:54 by ftrujill          #+#    #+#             */
/*   Updated: 2019/10/11 17:23:08 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void        initialize(t_layer *layer, int size)
{
    t_path  *path;

    layer->size = size;
    layer->nbr_paths = 1;
    layer->sol_depth = 0;
    layer->sol = 0;
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
    new_layer->sol = layer->sol;
    new_layer->sol_depth = layer->sol_depth;

}

void    prt_g(int **g)
{
    int i;
    int j;

    i = 0;
    while (i < 8)
    {
        j = 0;
        while (g[i][j] != -1)
            ft_printf("%d ", g[i][j++]);
        i++;
        ft_printf("\n");
    }
}

void        prt_path(t_path *path)
{
    int i = 0;

    ft_printf("Endpoint %d, depth %d, path ", path->endpoint, path->depth);
    while (i < path->depth)
        ft_printf("%d ", path->path[i++]);
    ft_printf(", depths ");
    i = 0;
    while (i < path->depth)
        ft_printf("%d ", path->depths[i++]);
    ft_printf("\n");
}

void        prt_layer(t_layer *layer)
{
    int     i = 0;
    t_path  *path;
    ft_printf("\nSize %d, nbr of paths %d, sol_depth %d, sol %d\n", layer->size, layer->nbr_paths, layer->sol_depth, layer->sol);
    while (i < layer->nbr_paths)
        prt_path(&(layer->paths[i++]));    
}

void        add_path(t_layer *new_layer, t_path *path, int *visited, int w) //Add the path (path + w) to the new_layer
{
    int n;
    int j;

    n = new_layer->nbr_paths;
    new_layer->paths[n].path = (int*)malloc((path->depth + 1) * sizeof(int));
    new_layer->paths[n].depths = (int*)malloc((path->depth + 1) * sizeof(int));
    j = -1;
    while (++j < path->depth)
    {
        new_layer->paths[n].path[j] = path->path[j];
        new_layer->paths[n].depths[j] = path->depths[j];
    }
    new_layer->paths[n].path[j] = w;
    new_layer->paths[n].depths[j] = path->depth + 1;
    new_layer->paths[n].depth = path->depth + 1;
    new_layer->paths[n].endpoint = w;
    new_layer->nbr_paths += 1;
    if (w == new_layer->size - 1)
    {
        ft_printf("\nThis is the solution \n");
        prt_path(&new_layer->paths[n]);
        ft_printf("\n");
        new_layer->sol = 1;
        if (new_layer->sol_depth > path->depth + 1)
            new_layer->sol_depth = path->depth + 1;
    }
}

void        update(t_layer *new_layer, int *visited, int *updated)
{
    int i;
    int j;
    int k;
    int n;
    int depth;

    i = -1;
    n = new_layer->nbr_paths;
    while (++i < new_layer->size)
    {
        if (updated[i] == 0)
            continue ;
        j = -1;
        while (++j < n)
        {
            depth = new_layer->paths[j].depth;
            k = -1;
            while (++k < depth)
            {
                if (new_layer->paths[j].path[k] == i && new_layer->paths[j].depths[k] > visited[i])
                    {
                        new_layer->paths[j].path[depth - 1] = new_layer->size - 1;
                        new_layer->paths[j].endpoint = new_layer->size - 1;
                        new_layer->paths[j].depth = 2 * new_layer->size;
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
    t_path      *path;
    t_layer     *new_layer;

    updated = (int*)ft_memalloc(size * sizeof(int));
    new_layer = (t_layer*)malloc(sizeof(t_layer));
    initialize_new_layer(new_layer, layer, ngbs);
    i = -1;
    while (++i < layer->nbr_paths)
    {
        path = &(layer->paths[i]);
        if (updated[path->endpoint] != 0)
            continue ;
        else if (path->endpoint == size - 1 && path->depth == layer->sol_depth && new_layer->sol == 0)
            {
                add_path(new_layer, path, visited, w);
                continue;
            }
        else if (path->endpoint == size - 1)
            continue ;
        j = -1;
        while ((w = g[path->endpoint][++j]) != -1)
        {
            if (visited[w] == 0)
                add_path(new_layer, path, visited, w);
            else if (visited[w] > path->depth) // + CAPACITY
                {
                    add_path(new_layer, path, visited, w);
                    visited[w] = path->depth; // + CAPACITY
                    updated[w] = 1;
                }
        }
    }
    update(new_layer, visited, updated);
    return (new_layer);
}

void        mbfs(int **g, int size, int *ngbs, int l, t_layer *layer) //Modified Breadth First Search
{
    int     *visited;

    visited = (int*)ft_memalloc(size * sizeof(int));
    while(!layer->sol)
    {
        layer = next_layer(g, size, ngbs, layer, visited);
       // prt_layer(layer);
    }
}

int         main()
{
    t_layer     *layer;
    int         g[][4] = {{1, 2, -1}, {0, 4, -1}, {0, 3, 5, -1}, {2, 6, -1}, {1, 5, -1}, {4, 3, -1}, {3, 7, -1}, {5, 6, -1}};
    int         ngbs[] = {2, 2, 3, 2, 2, 2, 2, 2};
    int         size = 8;
    int         l;
    int         **graph;
    t_solution  solution;
    
    layer = (t_layer*)malloc(sizeof(t_layer));
        int i;
    int j;

    i = 0;
    graph = (int**)malloc(8 * sizeof(int*));
    while (i < 8)
    {
        graph[i] = (int*)malloc(4 * sizeof(int));
        j = 0;
        while (g[i][j] != -1)
            {
                graph[i][j] = g[i][j];
                j++;
            } 
        graph[i][j] = g[i][j];
        i++;
    }
    prt_g(graph);
    initialize(layer, size);
    prt_layer(layer);
    mbfs(graph, size, ngbs, 0, layer);
    return (0);
}