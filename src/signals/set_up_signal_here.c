/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_signal_here.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:39:16 by ipavlov           #+#    #+#             */
/*   Updated: 2025/06/28 14:45:29 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_up_signals_here(t_main_env **main_env, char *str)
{
	struct sigaction	action;
	struct sigaction	quit_action;

	ft_memset(&action, 0, sizeof(struct sigaction));
	action.sa_handler = &sig_in_handler_here;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &action, NULL))
	{
		free(str);
		free_main_env(main_env);
	}
	ft_memset(&quit_action, 0, sizeof(struct sigaction));
	quit_action.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &quit_action, NULL))
	{
		free(str);
		free_main_env(main_env);
		exit(6);
	}
}
