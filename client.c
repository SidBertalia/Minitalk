#include "minitalk.h"

pid_t	parse_pid(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			num = num * 10 + *str - '0';
		else
			return (-1);
		str++;
	}
	return (num);
}

void	check_receivement(int signum)
{
	(void)signum;
	g_message_received = true;
}

int	send_signal(char *str, pid_t pid_num)
{
	int		i;
	int		bit_pos;

	i = 0;
	while (1)
	{
		bit_pos = 7;
		while (bit_pos >= 0)
		{
			if (kill(pid_num, (int []){SIGUSR1, SIGUSR2}
				[(str[i] & (1 << bit_pos)) > 0]) < 0)
				return (1);
			if (usleep(100) == -1)
				return (1);
			bit_pos--;
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid_num;

	if (argc != 3)
	{
		write(2, "\033[31mWrong Arguments.\033[0m\n", 27);
		write(2, "\033[33mUsage: ./client PID \"Your Message\"\033[00m\n", 46);
		return (1);
	}
	pid_num = parse_pid(argv[1]);
	if (pid_num <= 1)
	{
		write(2, "\033[31mInvalid PID number.\033[0m\n", 30);
		return (1);
	}
	g_message_received = false;
	if (signal(SIGUSR1, check_receivement) == SIG_ERR
		|| send_signal(argv[2], pid_num) != 0)
		return (1);
	if (!g_message_received)
		sleep(5);
	if (g_message_received)
		return (0);
	write(2, "\033[31mNo answer from server.\033[0m\n", 33);
	return (1);
}
