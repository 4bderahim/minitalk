#ifndef MINI_TALK_H
# define MINI_TALK_H
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*catch_size_and_alloc(int sig, int *i, int *msg_allocated);
void	reset_i_and_c(int *i, unsigned char *c);
void	print_msg_and_free(char *msg, siginfo_t *info, int action);
void	add_char(char c, char **s);
#endif