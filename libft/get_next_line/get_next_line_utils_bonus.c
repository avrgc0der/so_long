/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:45:58 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/16 16:22:06 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
USED FUNCTS:
- strjoin
- strdup
- strlen
- strchr
*/

char	*ft_joinstr(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!tmp)
		return (free(s1), NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != '\0' && s2[j] != '\n')
	{
		tmp[j + i] = s2[j];
		j++;
	}
	if (s2 != NULL && s2[j] == '\n')
		tmp[j++ + i] = '\n';
	tmp[j + i] = '\0';
	if (s1 != NULL)
		free(s1);
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	curr;

	i = 0;
	curr = c;
	while (s != NULL && s[i] != '\0')
	{
		if (s[i] == curr)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s != NULL && s[i] == curr)
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	t_usc	*tmp;
// 	size_t	i;

// 	i = 0;
// 	tmp = malloc(count * size);
// 	if (!tmp)
// 		return (NULL);
// 	while (i < count * size)
// 	{
// 		tmp[i] = 0;
// 		i++;
// 	}
// 	return (tmp);
// }
