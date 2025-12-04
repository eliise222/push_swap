#include <stdio.h>
#include "push_swap.h"

// t_list	*newlst(int	*c)
// {
// 	int	i;
// 	i = 0;

// 	newlst = (t_list *)malloc(sizeof*(t_list));

// 	while (c[i] != "\0" || c[i] == 32)
// 	{
		
// 	}
// }


int main()
{
	char *str = "45y 78 9 -6 0i";
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
    return (0);
}