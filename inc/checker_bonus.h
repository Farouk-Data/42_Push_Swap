#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0
# define FOUND 0
# define NOT_FOUND 1
# define IN 1 
# define OUT 0
# define BUFFER_SIZE 100

typedef struct s_node
{
	int	val;
	int	pos;
}	t_node;


typedef struct s_stack
{
	t_node	*element;
	int 	size;
	int		len;
}	t_stack;

void	ft_bzero(t_stack *stack);
void	ft_print_error(void);
int		ft_strcmp(char *s1, char *s2);
int		execute_instruct(char *str, t_stack *stack_a, t_stack *stack_b);
void	ft_print_output(char *str);
void	check_stack(t_stack *stack_a, t_stack *stack_b);
size_t	ft_strlen(const char *s);
void	convert_args(char **args, t_stack *stack);
char	**read_args(int argc, char **argv, int *count);
long 	int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
int		check_dup(t_stack *stack);
int		check_empty(char *str);
void	ft_swap(int *a, int *b);
void	swap_stack(t_stack *st);
void	ss_op(t_stack *st_a, t_stack *st_b);
void	rotate_stack(t_stack *st);
void	rr_op(t_stack *st_a, t_stack *st_b);
void	reverse_rotate_stack(t_stack *st);
void	rrr_op(t_stack *st_a, t_stack *st_b);
void	push_to_b(t_stack *st_a, t_stack *st_b);
void	push_to_a(t_stack *st_a, t_stack *st_b);
int		A_is_sorted(t_stack *stack, int size);
char	*ft_read_all(char *str, int fd);
char	*ft_free(char *str1, char *str2);
char	*ft_getline(char *str, int *i);
char	*ft_getrest(char *reminder, int *i);
char	*get_next_line(int fd);
int		ft_strchr(char *str, int c);


#endif