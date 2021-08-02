/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:48:36 by wlo               #+#    #+#             */
/*   Updated: 2021/08/02 17:48:50 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_message(char *message, int id)
{
	int	i;

	while (*message)
	{
		i = 0;
		while (i < 8)
		{
			if ((*message) & (0x80))
				kill(id, SIGUSR1);
			else
				kill(id, SIGUSR2);
			*message = *message << 1;
			usleep(15);
			++i;
		}
		++message;
	}
}

void	handler_new(int signum, siginfo_t *siginfo, void *context)
{
	static int	i = 0;
	static char	ch[9];
	char		word;

	(void)context;
	(void)siginfo;
	ch[8] = '\0';
	if (signum == SIGUSR1)
	{
		ch[i] = '1';
		++i;
	}
	if (signum == SIGUSR2)
	{
		ch[i] = '0';
		++i;
	}
	if (i == 8)
	{
		word = convertToDecimal(ch);
		write(1, &word, 1);
		i = 0;
	}
}

struct sigaction	settingSigation(struct sigaction action)
{
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	return (action);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;	

	pid = getpid();
	ft_putstr("PID :");
	ft_putnbr((int)pid);
	ft_putstr("\n");
	action.sa_sigaction = handler_new;
	action = settingSigation(action);
	if (sigaction(SIGUSR1, &action, 0) < 0)
	{
		ft_putstr("sigaction1 error!");
		return (1);
	}
	if (sigaction(SIGUSR2, &action, 0) < 0)
	{
		ft_putstr("sigaction2 error!");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
