#include "../includes/ft_select.h"

void	unsetup_term(int signum)
{
	t_env	*env;
	char	copy[2];
	
	(void)signum;
	env = save_env(NULL);
	wash_screen(env);
	env->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &env->term) < 0)
	{
		ft_putstr_fd("Error.", 2);
		exit (1);
	}
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	if (signum == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		copy[0] = env->term.c_cc[VSUSP];
		copy[1] = 0;
		ioctl(0, TIOCSTI, copy);
	}
}

void	exit_term(int signum)
{
	unsetup_term(signum);
	exit (0);
}
