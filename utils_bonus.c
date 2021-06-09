#include "minitalk_bonus.h"

bool	g_message_received;

void	sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		system("stty -echoctl");
		write(1, "\033[36m  ------- END OF TRANSMISSION -------\033[0m\n", 48);
		exit (0);
	}
}
