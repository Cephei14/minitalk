/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:46:25 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/04/29 13:03:49 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	main(int argc, char **argv)
{
	if (argc < 3)
	{
		ft_printf("few arguments run : \"./client <PID> <message>\"\n");
	}
	if (ft_atoi(argv[1]))
	
}