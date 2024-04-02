#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int data;
	struct s_list *next;
} t_list;
char *ft_join_argv(int ac, char **av);
void ft_argv_to_stack(char *str, t_list **stack);
void ft_check_stack(t_list **stack);
void ft_print_stack(t_list *stack_a, t_list *stack_b);
void ft_clear_stack(t_list **stack);
char *ft_strdup(const char *s1);
char *ft_strjoin(char const *s1, char const *s2);
char **ft_split(char const *s, char c);
int	ft_atoi(const char *nptr);
t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char **ft_split(char const *s, char c);
char *ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void ft_sort_stack(t_list **stack_a, t_list **stack_b);
void ft_push(t_list **from, t_list **to);
void ft_swap(t_list **stack);
void ft_rotate(t_list **stack);
void ft_reverse_rotate(t_list **stack);


//void ft_free_split(char **str);
#endif