#include "push_swap.h"
#include <stdio.h>

int get_sup_num(t_list **a, t_list *node)
{
	int count;
	t_list *tmp;

	count = 0;
	tmp = *a;

	while (tmp != NULL)
	{
		if (tmp != node)
		{
			if (tmp->content > node->content)
				count++;
		}
		tmp = tmp->next;
	}
	return (count);
}

void    assign_index(t_list **a)
{
    int	index;
	t_list	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		tmp->index = ft_lstsize(*a) - get_sup_num(a, tmp);
		tmp = tmp->next;
	}
}

int	count_nb(int a)
{
	int	i;

	i = 1;
	while (a / 2)
	{
		i++;
		a /= 2;
	}
	return(i);
}

// int	finbinary(int *a)
// {
// 	int	*b;
// 	int	i;
// 	int	nb;

// 	nb = count_nb(*a);
// 	b = (int *)malloc(sizeof(int)*(nb + 1));
// 	while  (i != (nb + 1))
// 	{
// 		b[i] = a[i];
// 		a = (int *)(a * 10);
// 		i++;
// 	}
// 	return(*b);
// }

// int	tobinary(int a)
// {
// 	int	*binary;
// 	int	nb;

// 	nb = count_nb(a);
// 	binary = (int *)malloc(sizeof(int)*(nb + 1));
// 	while (a != 0)
// 	{
// 		printf("nb = %d \n", nb);
// 		binary[nb] = a % 2;
// 		printf("a = %d \n", a);
// 		nb--;
// 		a /= 2;
// 	}
// 	return(finbinary(binary));
// }

void	radix(t_list a, t_list b)
{
	int	mult;
	int	result;

	mult = 1;
	while ()
}

int	main()
{
	int	a;
	int	b;

	a = 5;
	printf("a decimal = %d \n", a);
	b = tobinary(a);
	printf("binaire = %d \n", b);

}