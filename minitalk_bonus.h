#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>

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

/*******************************************************************************
** UTILS
******************************************************************************/

void	sigint_handler(int sig);

#endif