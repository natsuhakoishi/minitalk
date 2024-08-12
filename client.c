/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:03:55 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/08/05 12:20:54 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_acknowledge(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Signal Received!\n", 1);
	else
		ft_printf("Signal Received!\n", 1);
}

void	ft_message(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	len;

	len = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][len] != '\0')
		{
			signal(SIGUSR1, ft_acknowledge);
			signal(SIGUSR2, ft_acknowledge);
			ft_message(pid, argv[2][len]);
			len++;
		}
		ft_message(pid, '\n');
	}
	else
	{
		ft_printf("Error. Wrong Format, please try again.");
		return (1);
	}
	return (0);
}
