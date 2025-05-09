/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:46:25 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/05/09 18:36:54 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	checking_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 3)
	{
		ft_printf("Error: Few arguments. Try \"./client <PID> <message>\"\n");
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (!ft_isdigit(argv[1][i]))
			return (0);
		i++;
	}
	return (1);
}

void	signal_ack(int signum)
{
	(void)signum;
}

void	code(int server, char c)
{
	int					i;
	struct sigaction	sa;

	sa.sa_handler = signal_ack;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error registering acknowledgment handler\n");
		exit(EXIT_FAILURE);
	}
	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(server, SIGUSR1) == -1)
			{
				ft_printf("Error: Failed to send SIGUSR1\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(server, SIGUSR2) == -1)
			{
				ft_printf("Error: Failed to send SIGUSR2\n");
				exit(EXIT_FAILURE);
			}
		}
		pause(); // Wait for acknowledgment from the server
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		server;
	char	c;

	i = 0;
	server = ft_atoi(argv[1]);
	if (!checking_args(argc, argv) || server <= 0)
		return (1);
	while(1)
	{
		c = argv[2][i];
		code(server, c);
		if (c == '\0')
			break;
		i++;
	}
	return (0);
}