#include "ft_printf/main.h"
#define _POSIX_C_SOURCE 200809L
#include <signal.h>

handler_zero ()
{

}

handler_one ()
{

}

void	main(void)
{
	pid_t	pid_s;
	struct sigaction	action;
	
	pid_s = getpid();
	ft_printf("Server's PID is %d", pid_s);
	while(1)
	{

	}
}
