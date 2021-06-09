#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>

bool	g_message_received;

/*******************************************************************************
** SERVER
******************************************************************************/

void	receive_signal(int bit, pid_t client_pid);
void	sigusr_handler(int signum, siginfo_t *info, void *ucontext);
void	put_pid(pid_t	pid);
int		setup_handlers(void);

/*******************************************************************************
** CLIENT
******************************************************************************/

pid_t	parse_pid(char *str);
void	check_receivement(int signum);
int		send_signal(char *str, pid_t pid_num);

#endif