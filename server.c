/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:46:19 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/05/12 19:52:08 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	iter_power(int nb, int power)
{
	int	i;
	int	n;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	n = 1;
	i = 0;
	while (i < power)
	{
		n = nb * n;
		i++;
	}
	return (n);
}

void	print_binary_letter(char *text)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i <= 7)
	{
		if (text[i] == '1')
			c = c + iter_power(2, 7 - i);
		i++;
	}
	if (c == '\0')
		ft_printf("\n");
	else
		ft_printf("%c", c);
}

void	decode(int signum)
{
	static char	*binary_text = NULL;
	static int	i = 0;

	if (binary_text == NULL)
	{
		binary_text = malloc(sizeof(char) * 8);
		if (!binary_text)
			exit(EXIT_FAILURE);
		ft_memset(binary_text, 0, 8);
	}
	if (signum == SIGUSR1)
		binary_text[i] = '1';
	else if (signum == SIGUSR2)
		binary_text[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		print_binary_letter(binary_text);
		free(binary_text);
		binary_text = NULL;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server's PID is : %d\n", getpid());
	sa.sa_handler = decode;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error registering sa1's handler function\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error registering sa2's handler function\n");
	while (1)
		pause();
	return (0);
}
