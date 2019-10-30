/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:39:54 by ftrujill          #+#    #+#             */
/*   Updated: 2019/10/30 19:32:09 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void        add_path(t_layer *new_layer, t_path *path, int *visited, int w, int used_edge) //Add the path (path + w) to the new_layer
{
    int n;
    int j;

    if (path->endpoint == new_layer->size - 1 && path->depths[path->depth - 1] >= new_layer->sol_depth)
        return ;
    else if (path->endpoint == new_layer->size - 1)
    {
        copy_solution(new_layer, path);
        return ;
    }
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
    new_layer->paths[n].depths[j] = path->depths[j - 1] + 1 - 3 * used_edge;
    new_layer->paths[n].depth = path->depth + 1;
    new_layer->paths[n].endpoint = w;
    new_layer->nbr_paths += 1;
    if (w == new_layer->size - 1)
        if (new_layer->sol_depth > path->depth + 1)
            new_layer->sol_depth = path->depth + 1;
    if (w != new_layer->size - 1)
        visited[w] = path->depth + 1;
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
                        new_layer->paths[j].endpoint = new_layer->size;
            }
        }
    }
}

void        min_depth(t_layer *layer)
{
    int i;

    i = -1;
    layer->min_depth = layer->size;
    while (++i < layer->nbr_paths)
    {
        if (layer->paths[i].endpoint != layer->size)
            layer->min_depth = ft_min(layer->min_depth, layer->paths[i].depths[layer->paths[i].depth - 1]);
    }
}

t_layer     *next_layer(int **g, int *ngbs, t_layer *layer, int *visited, t_solution *solution)
{
    int         i;
    int         j;
    int         w;
    int         *updated;
    t_path      *path;
    t_layer     *new_layer;

    updated = (int*)ft_memalloc(layer->size * sizeof(int));
    new_layer = (t_layer*)malloc(sizeof(t_layer));
    initialize_new_layer(new_layer, layer, ngbs);
    i = -1;
    while (++i < layer->nbr_paths)
    {
        path = &(layer->paths[i]);
        if (updated[path->endpoint] != 0 || path->endpoint == layer->size)
            continue ;
        if (path->endpoint == layer->size - 1 && path->depths[path->depth - 1] < new_layer->sol_depth)
            {
                add_path(new_layer, path, visited, layer->size - 1, 0);
                visited[layer->size - 1] = path->depth;
                updated[layer->size - 1] = 1;
                continue;
            }
        if (path->endpoint == layer->size - 1)
            continue ;
        if (path->depth > 1 && solution->used_vertices[path->endpoint][0] && !solution->used_vertices[path->path[path->depth - 2]][0])
            {
                add_path(new_layer, path, visited, solution->paths[solution->used_vertices[path->endpoint][1]].path[(solution->used_vertices[path->endpoint][2]) - 1], 1);
                continue ;
            }
        j = -1;
        while ((w = g[path->endpoint][++j]) != -1)
        {
            if (path->endpoint == 0 && solution->used_vertices[w][0])
                continue ;
            if (visited[w] == 0)
                add_path(new_layer, path, visited, w, 0);
            else if (visited[w] > path->depth + 1)
                {
                    add_path(new_layer, path, visited, w, 0);
                    updated[w] = 1;
                }
        }
    }
    update(new_layer, visited, updated);
    min_depth(new_layer);
    return (new_layer);
}

void        reset_path(t_path *path)
{
    path->endpoint = 0;
    path->depth = 0;
    free(path->path);
    free(path->depths);
}

void        merge_paths(t_solution *solution, int pos, int i, int p) //The position pos of new_path is equal to the position p of solution->paths[i] (new_path[pos] = solution->paths[i][p])
{
    int     j;
    t_path  *tmp;
    t_path  *tmp2;
    t_path  *old_path;
    t_path  *new_path;

    tmp = (t_path*)malloc(sizeof(t_path));
    tmp2 = (t_path*)malloc(sizeof(t_path));
    old_path = &solution->paths[i];
    new_path = &solution->paths[solution->nbr_paths];
    copy_path(old_path, tmp);
    j = -1;
    old_path->path = (int*)malloc(solution->size * sizeof(int));
    old_path->depths = (int*)malloc(solution->size * sizeof(int));
    while (++j <= pos)
    {
        old_path->path[j] = new_path->path[j];
        old_path->depths[j] = new_path->depths[j];
    }
    j = 0;
    while (p + j < tmp->depth)
    {
        old_path->path[pos + j] = tmp->path[p + j];
        old_path->depths[pos + j] = tmp->depths[p + j];
        j++;
    }
    old_path->depth = pos + j;
    old_path->endpoint = solution->size - 1;
    j = -1;
    copy_path(new_path, tmp2);
    while (++j < p)
    {
        new_path->path[j] = tmp->path[j];
        new_path->depths[j] = tmp->depths[j];
        solution->used_vertices[new_path->path[j]][0] = 1;
        solution->used_vertices[new_path->path[j]][1] = solution->nbr_paths;
        solution->used_vertices[new_path->path[j]][2] = j;
    }
    j = 0;
    while (pos + j + 2 < tmp2->depth)
    {
        new_path->path[p + j] = tmp2->path[pos + j + 2];
        new_path->depths[p + j] = tmp2->depths[pos + j + 2];
        j++;
    }
    new_path->depth = p + j;
    new_path->endpoint = solution->size - 1;
    reset_path(tmp);
    reset_path(tmp2);
    j = -1;
    while (++j < old_path->depth)
    {
        solution->used_vertices[old_path->path[j]][0] = 1;
        solution->used_vertices[old_path->path[j]][1] = i;
        solution->used_vertices[old_path->path[j]][2] = j;
    }
}

void        update_solution(t_path *path, t_solution *solution, t_path **possible)
{
    int i;
    int j;
    t_path *new_path;

    new_path = &solution->paths[solution->nbr_paths];
    copy_path(path, new_path);
    i = 1;
    while (i < new_path->depth - 1)
    {
        if (solution->used_vertices[new_path->path[i]][0] != 0
            && solution->used_vertices[new_path->path[i]][1] != solution->nbr_paths)
        {
            merge_paths(solution, i, solution->used_vertices[new_path->path[i]][1], solution->used_vertices[new_path->path[i]][2]);
            i = 1;
        }
        else
            i++;
    }
    i = -1;
    while (++i < new_path->depth)
    {
        solution->used_vertices[new_path->path[i]][0] = 1;
        solution->used_vertices[new_path->path[i]][1] = solution->nbr_paths;
        solution->used_vertices[new_path->path[i]][2] = i;
    }
    solution->nbr_paths += 1;
    i = 0;
    while (possible[i])
        i++;
    possible[i] = (t_path*)malloc( (solution->nbr_paths + 1) * sizeof(t_path));
    j = -1;
    while (++j < solution->nbr_paths)
        copy_path(&solution->paths[j], &possible[i][j]);
    possible[i + 1] = NULL;
}

int        mbfs(int **g, int *ngbs, t_solution *solution, t_layer *layer, t_path **possible) //Modified Breadth First Search
{
    int     *visited;

    visited = (int*)ft_memalloc(layer->size * sizeof(int));
    visited[0] = 1;
    while((layer->sol_depth == layer->size + 1 || layer->min_depth < layer->sol_depth + solution->max_length|| layer->nbr_paths > 1))
    {
        if (layer->nbr_paths == 0)
            return (0);
        layer = next_layer(g, ngbs, layer, visited, solution);
    }
    update_solution(layer->paths, solution, possible);
    return (1);
}   

void         find_solution(t_path **possible, int n, int *nbr_steps, int *sol)
{
    int     i;
    int     j;
    int     sum_lengths;
    int     max_length;
    int     aux;

    i = 1;
    *sol = 0;
    *nbr_steps = n + possible[0][0].depth - 2;
    while (possible[i])
    {
        j = 0;
        sum_lengths = 0;
        max_length = possible[0][0].depth;
        while (j <= i)
        {
            sum_lengths += possible[i][j].depth;
            max_length = ft_max_int(max_length, possible[i][j++].depth);
        }
        if ((i + 1) * max_length < n + sum_lengths)
        {
            aux = ((n + sum_lengths) % (i + 1) == 0) ? (n + sum_lengths) / (i + 1) - 2 : (n + sum_lengths) / (i + 1) - 1;
            if (aux < *nbr_steps)
            {
                *nbr_steps = aux;
                *sol = i;
            }
        }
        i++;
    }
}

void        prt_just_path(t_path *path)
{
    int i;
    
    i = 0;
    while (i < path->depth)
        ft_printf("%d ", path->path[i++]);
    ft_printf("\n");
}      

int         *path_numbers(t_path **possible, int nbr_ants, int nbr_steps, int sol)
{
    int     *tab;
    int     i;
    int     j;
    int     ant;
    int     available_paths;

    tab = (int*)malloc(sizeof(int) * nbr_ants);
    i = -1;
    ant = 0;
    available_paths = sol + 1;
    while (++i < nbr_steps - possible[sol][0].depth + 2)
    {
       // ft_printf("available paths %d\n", available_paths);
        j = -1;
        while (++j < available_paths)
        {
            tab[ant] = j % (available_paths);
            ant++;
            if (ant >= nbr_ants)
                break;
        }
        if (ant >= nbr_ants)
            break;
        j = available_paths;
        while (--j >= 0)
        {
            if (nbr_steps - i < possible[sol][j].depth)
                available_paths--;
        }
    }
    return (tab);
}

int         *ant_first_app(t_path **possible, int nbr_ants, int nbr_steps, int sol)
{
    int     *tab;
    int     i;
    int     j;
    int     ant;
    int     available_paths;

    tab = (int*)malloc(sizeof(int) * nbr_ants);
    i = -1;
    ant = 0;
    available_paths = sol + 1;
    while (++i < nbr_steps - possible[sol][0].depth + 2)
    {
               // ft_printf("available paths %d\n", available_paths);
        j = -1;
        while (++j < available_paths)
        {
            tab[ant] = i;
            ant++;
            if (ant >= nbr_ants)
                break;
        }
        if (ant >= nbr_ants)
            break;
        j = available_paths;
        while (--j >= 0)
        {
            if (nbr_steps - i < possible[sol][j].depth)
                available_paths--;
        }
    }
    return (tab);
}

void        prt_steps(t_path **possible, int nbr_ants, int nbr_steps, int sol)
{
    int i;
    int j;
    int f;
    int *path_nbrs;
    int *ant_first;

    i = 0;
    f = sol + 1;
    path_nbrs = path_numbers(possible, nbr_ants, nbr_steps, sol);
    ant_first = ant_first_app(possible, nbr_ants, nbr_steps, sol);
    j = -1;
    while (++j < nbr_ants)
       // ft_printf("Ant number %d Path Number %d, First app %d\n", j, path_nbrs[j], ant_first[j]);
    while (i < nbr_steps)
    {
        j = -1;
        while(++j < f)
        {
            if (j >= nbr_ants || i - ant_first[j] > possible[sol][path_nbrs[j]].depth - 2)
                continue;
            else
                ft_printf("L%d-%d ", j, possible[sol][path_nbrs[j]].path[i - ant_first[j] + 1]);
        }
        ft_printf("\n");
        j = -1;
        while (++j <= sol)
            f = (nbr_steps - i < possible[sol][j].depth) ? f : f + 1;
        i++;
    }
}

int         main(int argc, char **argv)
{
    t_layer     *layer;
    int         g[][6] = {{1, 2, 5, 7, 10, -1}, {0, 10, -1}, {0, 3, -1}, {2, 4, -1}, {3, 10, -1}, {0, 6, -1}, {5, 10, -1}, {0, 8, -1}, {7, 9, -1}, {8, 10, -1}, {0, 1, 4, 6, 9, -1}};
    int         ngbs[] = {5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5};
    int         ants_nbr;
    int         sol;
    int         nbr_steps;

    int         size = 11;
    int         l;
    int         **graph;
    t_solution  *solution;
    t_path         **possible;

    if (argc != 2)
        return (0);
    ants_nbr = ft_atoi(argv[1]);
    layer = (t_layer*)malloc(sizeof(t_layer));
    solution = (t_solution*)malloc(sizeof(t_solution));


    int i = 0;
    int j = 0;
    solution->nbr_paths = 0;
    solution->size = size;
    solution->used_vertices = (int**)malloc(size * sizeof(int*));
    while (i < size)
        solution->used_vertices[i++] = (int*)malloc(3 * sizeof(int));
    i = 0;
    while (i < size)
        solution->used_vertices[i++][0] = 0;
    i = 0;
    solution->paths = (t_path*)malloc(size * sizeof(t_path));
    solution->max_length = 0;
    
    graph = (int**)malloc(size * sizeof(int*));
    i = 0;
    while (i < size)
    {
        graph[i] = (int*)malloc(size * sizeof(int));
        j = 0;
        while (g[i][j] != -1)
            {
                graph[i][j] = g[i][j];
                j++;
            } 
        graph[i][j] = g[i][j];
        i++;
    }
    prt_g(graph, size);
    possible = (t_path**)malloc(size * sizeof(t_path*));
    possible[0] = NULL;
    initialize(layer, size);
    while (mbfs(graph, ngbs, solution, layer, possible))
    {
    }
    prt_possible(possible);
    find_solution(possible, ants_nbr, &nbr_steps, &sol);
    ft_printf("\nAnd the right solution with %d ants is the one with %d path(s) and it takes %d step(s)\n\n", ants_nbr, sol + 1, nbr_steps);
    prt_steps(possible, ants_nbr, nbr_steps, sol);
    return (0);
}