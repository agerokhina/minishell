/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_and_dispatch_packeging_helper_two.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:37:31 by ipavlov           #+#    #+#             */
/*   Updated: 2025/06/28 12:16:29 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	gather_name(char **tmp_name, char **name)
{
	if (*tmp_name)
		free(*tmp_name);
	if (*name)
		*tmp_name = ft_strdup(*name);
	else
		*tmp_name = ft_strdup("");
}

static void	gather_res(char **tmp_res, char **tmp, char **real)
{
	if (*tmp_res)
		free(*tmp_res);
	if (*real)
		*tmp_res = ft_strjoin(*tmp, *real);
	else
		*tmp_res = ft_strdup(*tmp);
	free(*tmp);
}

char	*gather_prev_and_next(char *name, char *opt, char *param)
{
	char	*tmp_name;
	char	*tmp_opt;
	char	*tmp_params;

	tmp_name = NULL;
	tmp_opt = NULL;
	tmp_params = NULL;
	gather_name(&tmp_name, &name);
	if (tmp_name == NULL)
		return (NULL);
	gather_res(&tmp_opt, &tmp_name, &opt);
	if (tmp_opt == NULL)
		return (NULL);
	gather_res(&tmp_params, &tmp_opt, &param);
	if (tmp_params == NULL)
		return (NULL);
	return (tmp_params);
}

t_command	*ft_command_dup(t_command *command)
{
	t_command	*new_command;

	new_command = init_ft_command();
	if (new_command == NULL)
		return (NULL);
	new_command->command = ft_strdup(command->command);
	if (new_command->command == NULL)
		return (free_command(&new_command), NULL);
	if (command->option != NULL)
	{
		new_command->option->opt_name = ft_strdup(command->option->opt_name);
		if (new_command->option->opt_name == NULL)
			return (free_command(&new_command), NULL);
	}
	else
		new_command->option = NULL;
	new_command->parameters = ft_strdup(command->parameters);
	if (new_command->parameters == NULL)
		return (free_command(&new_command), NULL);
	return (new_command);
}

t_program	*ft_program_dup(t_program *program)
{
	t_program	*new_program;

	new_program = init_ft_program();
	if (new_program == NULL)
		return (NULL);
	new_program->name = ft_strdup(program->name);
	if (new_program->name == NULL)
		return (free_program(&new_program), NULL);
	new_program->parameters = ft_strdup(program->parameters);
	if (new_program->parameters == NULL)
		return (free_program(&new_program), NULL);
	return (new_program);
}
