/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdhaibi <rdhaibi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:46:15 by rdhaibi           #+#    #+#             */
/*   Updated: 2025/05/12 19:54:59 by rdhaibi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

int		checking_args(int argc, char **argv);
void	code(int server, char c);
int		iter_power(int nb, int power);
void	print_binary_letter(char *text);
void	decode(int signum);
void	code(int server, char c);
int		checking_args(int argc, char **argv);
int		usleep(useconds_t usec);

#endif