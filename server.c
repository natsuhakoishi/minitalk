/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:03:58 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/08/05 12:29:14 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sgn_handle(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	c;

	(void)info;
	(void)s;
	if (signal == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sigact;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error, Wrong Format\n");
		return (0);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	sigact.sa_sigaction = sgn_handle;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sigact, NULL);
		sigaction(SIGUSR2, &sigact, NULL);
		pause();
	}
	return (0);
}
