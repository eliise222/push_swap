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

char **get_list(char *str)
{
	char sep = ' ';
	char **resul;
	resul = ft_split(str, sep);
	return (resul);
}

void free_list(char **enter)
{
	int j = 0;
	while (enter[j])
    {
		free(enter[j]);
		j++;
    }
	free(enter);
}

int is_valid_enter(char **enter)
{
	int j = 0;
	while (enter[j])
    {
		
       if(is_valid(enter[j]) == 0)
	   {
			free_list(enter);
			return(0);
	   }
	   j++;
    }
	return(1);
}

int print_list(char **resul)
{
	// char sep = ' ';
	// char **resul;
	// resul = ft_split(str, sep);
	if(!is_valid_enter(resul))
	{
		error();
		return(0);
	}
	int i = 0;
    while (resul[i])
    {
		
        printf("%s\n", resul[i]);
        i++;
    }
    return (1);
}

int list_len(char **resul)
{
	if(!resul)
		return(0);
	int i = 0;
    while (resul[i])
    {
        i++;
    }
    return (i);
}

long long *num_list(char **char_list)
{
	long long *list;
	int i = 0;
	int len = list_len(char_list);
	list = (long long *)malloc(sizeof(long long) * (len ));
	if (!list)
		return (NULL);
	while(i<len)
	{
		list[i] = ft_atoill(char_list[i]);
		i++;
	}
	free_list(char_list);
	return(list);
}

t_list *a_list(long long *num, int len)
{
	long long *first_n = &num[0];
	t_list *final = ft_lstnew(first_n);
	t_list **final_pointer = &final;
	printf("\n---%lld ---\n", *(long long *)final->content);
	int i = 1;
	while(i < len)
	{
		long long *tmp_n = &num[i];
		t_list *tmp = ft_lstnew(tmp_n);
		ft_lstadd_back(final_pointer, tmp);
		i++;
	}
	return final;

}

void print_node_list(t_list *head)
{
	t_list *tmp = head;
	while(tmp != NULL)
	{
		printf("%lld -> ", *(long long *)tmp->content);
		tmp = tmp-> next;
	}
	printf("NULL\n");
}

int main()
{
	char *str = "45 78 9 -6 8";
	char **get_str = get_list(str);
	long long *get_num;
	int len = list_len(get_str);
	if(print_list(get_str))
	{
		get_num = num_list(get_str);
	}

	int i = 0;
	printf("\n------------------\n");
	while(i < len )
	{
		printf("%lld en long long\n", get_num[i]);
		i++;
	}
	t_list *num_list;
	num_list = a_list(get_num, len);
	
	printf("\n------------------\n");
	print_node_list(num_list);
	free(get_num);


    return (0);
}