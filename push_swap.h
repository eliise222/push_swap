#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int	is_valid(const char	*s);
char	**ft_split(char const *s, char c);

int SB(int *b);
int SA(int *a);

#endif