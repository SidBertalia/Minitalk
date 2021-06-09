#include "minitalk_bonus.h"

void	receive_signal(int bit, pid_t client_pid)
{
	static int	current_char;
	static int	current_bit;
	static char	buffer[1000];
	static int	len;

	current_char = (current_char << 1) | bit;
	current_bit++;
	if (current_bit == 8)
	{
		buffer[len++] = current_char;
		if (current_char == '\0' || len >= 1000)
		{
			write(1, "✅  ", 6);
			write(1, buffer, len - (current_char == '\0'));
			write(1, "\n----------------------------------------------\n", 49);
			len = 0;
			if (current_char == '\0')
				kill(client_pid, SIGUSR1);
		}
		current_char = 0;
		current_bit = 0;
	}
}

void	sigusr_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)signum;
	(void)ucontext;
	receive_signal(signum == SIGUSR2, info->si_pid);
}

void	put_pid(pid_t	pid)
{
	char	c;

	if (!pid)
		return ;
	put_pid(pid / 10);
	c = (pid % 10) + '0';
	write(1, &c, 1);
}

/*
** – sigemptyset = initialize and empty a signal set.
** – SIGUSR1 = user defined signal 1.
** – SIGUSR2 = user defined signal 2.
** – sigaction = used to change the action taken by a process
** 		on receipt of a specific signal.
** – signum specifies the signal and can be any valid signal except
** 		SIGKILL and SIGSTOP
*/
int	setup_handlers(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sigusr_handler;
	if (sigemptyset(&act.sa_mask) < 0
		|| sigaction(SIGUSR1, &act, NULL) < 0
		|| sigaction(SIGUSR2, &act, NULL) < 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				pid;

	if (argc != 1)
	{
		write(1, "\033[31mError: No arguments needed.\033[0m\n", 38);
		write(1, "\033[33mTry: ./server\033[0m\n", 24);
		return (1);
	}
	if (setup_handlers() == -1)
		return (1);
	pid = getpid();
	write(1, "\033[33mUse this PID to send message: \033[0m", 40);
	put_pid(pid);
	write(1, "\n\n", 3);
	signal(SIGINT, sigint_handler);
	while (1)
		pause();
	(void)argv;
	return (0);
}
