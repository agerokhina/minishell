/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gather_packages.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:55:05 by ipavlov           #+#    #+#             */
/*   Updated: 2025/06/28 12:17:46 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_command	*init_ft_command(void)
{
	t_command	*new_command;

	new_command = (t_command *)malloc(sizeof(t_command));
	if (new_command == NULL)
		return (NULL);
	new_command->command = NULL;
	new_command->option = (t_opt *)malloc(sizeof(t_opt));
	if (new_command->option == NULL)
		return (free(new_command), NULL);
	new_command->option->opt_name = NULL;
	new_command->parameters = NULL;
	return (new_command);
}

t_program	*init_ft_program(void)
{
	t_program	*new_program;

	new_program = (t_program *)malloc(sizeof(t_program));
	if (new_program == NULL)
		return (NULL);
	new_program->name = NULL;
	new_program->parameters = NULL;
	return (new_program);
}
