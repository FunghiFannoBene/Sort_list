typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

t_list *addfrontnum(t_list **lista, int val);
t_list	*sort_list(t_list* lst, int (*cmp)(int, int));