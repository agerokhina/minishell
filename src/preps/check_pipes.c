/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:25:24 by ipavlov           #+#    #+#             */
/*   Updated: 2025/06/27 15:24:29 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	pipe_pipe(char *str)
{
	size_t		i;
	char		c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			c = str[i++];
			while (str[i] && str[i] != c)
				i++;
			if (!str[i++])
				break ;
		}
		if (str[i] == '|')
		{
			i++;
			skip_whitespace(str, &i);
			if (str[i] == '|')
				return (1);
		}
		i += (i < ft_strlen(str));
	}
	return (0);
}

int	is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}
