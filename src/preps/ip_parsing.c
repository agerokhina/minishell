/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:37:50 by ipavlov           #+#    #+#             */
/*   Updated: 2025/06/30 13:02:21 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	list_word_check_station(t_main_env **main_env, char *str)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = replace_vars(main_env, str, 0, 0);
	skip_whitespace(tmp, &i);
	if (tmp[i] == '\0')
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

t_list_tokens	*parsing(t_main_env **main_env, t_list_words *list_words)
{
	t_list_tokens	*temp;

	temp = NULL;
	while (list_words != NULL)
	{
		if (list_word_check_station(main_env, list_words->word))
		{
			if (link_t_token(main_env, &temp, &list_words))
			{
				free_list_tokens(&(*main_env)->list_tokens);
				printf("error with parsing\n");
				return (NULL);
			}
		}
		if (list_words != NULL)
			list_words = list_words->next;
	}
	return (temp);
}
