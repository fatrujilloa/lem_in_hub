/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:25:23 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/12 14:59:25 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

ssize_t		check_rest(char **line, t_list **rem, t_list *prev)
{
	t_list	*curr;
	size_t	line_size;
	char	*str;
	ssize_t	check;

	if (!rem)
		return (0);
	curr = !prev ? *rem : prev->next;
	if (!curr)
		return (0);
	str = (char*)curr->content;
	line_size = ft_memindex('\n', str + 4, curr->content_size - 4);
	ft_memmove(*line, str + 4, line_size);
	(*line)[line_size] = 0;
	check = line_size + 4 == curr->content_size ? line_size : -1;
	if (line_size + 5 >= curr->content_size)
		ft_lstdelnext(rem, &prev);
	else
	{
		curr->content_size -= (line_size + 1);
		ft_memmove(str + 4, str + line_size + 5, curr->content_size - 4);
	}
	return (check);
}

int			add_to_rem(const int fd, char *str, ssize_t cont_size, t_list **rem)
{
	int		*ptr;
	t_list	*new;

	ptr = (int*)str;
	*ptr = fd;
	if (!(new = ft_lstnew(str, cont_size)))
		return (-1);
	ft_lstadd(rem, new);
	free(str);
	return (1);
}

int			free_stuff(char *str, char **line, size_t size)
{
	free(str);
	if (size == 0)
	{
		free(*line);
		if (!(*line = (char*)malloc(0)))
			return (-1);
	}
	return (size ? 1 : 0);
}

int			find_line(const int fd, char **line, size_t size, t_list **rem)
{
	char		*str;
	char		*str1;
	size_t		nlindex;
	ssize_t		bytsrd;

	nlindex = BUFF_SIZE + 1;
	while (nlindex >= BUFF_SIZE)
	{
		if (!(str = (char*)malloc(BUFF_SIZE + 4))
			|| (bytsrd = read(fd, str, BUFF_SIZE)) == -1)
			return (-1);
		if (bytsrd == 0 && nlindex == BUFF_SIZE + 1)
			return (free_stuff(str, line, size));
		nlindex = ft_memindex('\n', str, bytsrd);
		if ((1 < bytsrd - nlindex && !(str1 = ft_realloc(str, BUFF_SIZE + 4)))
		|| !(*line = (char*)ft_memjoin_allocf(*line, str, size, nlindex + 1)))
			return (-1);
		size += nlindex;
	}
	(*line)[size] = 0;
	if (1 < bytsrd - nlindex)
		ft_memmove(str1 + 4, str1 + nlindex + 1, bytsrd - nlindex - 1);
	return (1 < bytsrd - nlindex ? add_to_rem(fd, str1,
			bytsrd - nlindex + 3, rem) : 1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*rem = NULL;
	ssize_t			size;
	t_list			*prev;
	t_list			*curr;
	int				*ptr;

	if (fd < 0 || !line || !(*line = (char*)malloc(BUFF_SIZE + 4)))
		return (-1);
	*(*line) = 0;
	prev = NULL;
	curr = rem ? rem : NULL;
	while (curr && *(ptr = (int*)curr->content) != fd)
	{
		prev = curr;
		curr = curr->next;
	}
	if ((size = check_rest(line, &rem, prev)) == -1)
		return (1);
	return (find_line(fd, line, size, &rem));
}
