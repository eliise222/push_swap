#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

// t_list	*newlst(int	*c)
// {
// 	int	i;
// 	i = 0;

// 	newlst = (t_list *)malloc(sizeof*(t_list));

// 	while (c[i] != "\0" || c[i] == 32)
// 	{
		
// 	}
// }

int print_list(char *str)
{
	char sep = ' ';
	char **resul;
	resul = ft_split(str, sep);
		 int i = 0;
    while (resul[i])
    {
        printf("%s - %d\n", resul[i], is_valid(resul[i]));
        free(resul[i]);
        i++;
    }
    free(resul);
    return (1);
}

int main()
{
	char *str = "45y 78 9 -6 0i";
	print_list(str);
    return (0);
}