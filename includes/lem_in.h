/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:39:26 by ftrujill          #+#    #+#             */
/*   Updated: 2019/10/11 11:54:05 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

/*typedef struct      s_path
{
    int     end_vertex;
    int     max_depth;
    int     *path;
    int     *depth;
}                   t_path;
*/

typedef struct      s_layer
{
    int     nbr_paths;
    int     sol;
    int     sol_depth;
    int     *vertex;
    int     *max_depths;
    int     **paths;
    int     **depths;
}                   t_layer;


#endif