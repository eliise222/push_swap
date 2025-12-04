#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}

int SB(int *b);
int SA(int *a);

#endif