/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:57:30 by xinwang           #+#    #+#             */
/*   Updated: 2020/12/15 12:43:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 20000
# define SINGLE 39
# define DOUBLE 34

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_quo
{
	int	have_quote;
	int	double_quote;
	int	single_quote;
}				t_quo;

int				ft_max(int a, int b);
int				ft_min(int a, int b);
size_t			ft_tablen(char **arr);
long long		ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
char			*ft_itoa(int n);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **list, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *ls, void *(*f)(void *), void (*del)(void *));
t_list			*ft_lstnew(void *data);
int				ft_lstsize(t_list *lst);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *s);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_split(char const *s, char c);
char			**ft_split_w_quotes(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, int n);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int a, size_t l);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strrchr(const char *str, int c);
int				is_space(char c);
char			**get_buffer(void);
void			ft_print_buffer(void);
int				get_next_line(int fd, char **line);
int				nigun_static(char **str, int return_value);
char			*ft_strnew(int size);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
int				ft_putchar(char c);
void			ft_putendl(char *str);
void			ft_putstr_w_new_line(char *s);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strnew(int n);
char			*ft_strcat(char *s1, const char *s2);
int				is_space(char c);
int				ft_printf(const char *format, ...);
void			free_str(char *s);
void			free_p_str(char **s);
char			*ft_strrmv(char *s, char *sep);
void			ft_putstr_w_new_line_fd(char *s, int fd);
void			delete_quotes_from_arr(char **arr, int d);
void			delete_quotes_from_s(char **s);
t_quo			init_quotes_struct(void);
void			manage_struct_quotes(t_quo *quo, const char *s, int i);
int				is_escapted(t_quo *q, const char *s, int i);
int				is_unescapted_c(t_quo *q, const char *s, int i, const char c);
void			delete_slash_from_arr(char **arr);
void			delete_slash_from_str(char **s);
void			ft_tabfree(char **tab);
int				ft_get_directory(char *execname, char *dir);
void			show_arr_value(char **arr);
char			*ft_malloc_and_copy(char *src);
int				get_nb_size(int n);
char			**empty_arr(void);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
void			ft_putstr_echo(char *s);
int				get_next_line(int fd, char **line);
int				nigun_static(char	**str, int return_value);
int				get_nb_words_in_arr(char *str, char c);
int				no_newline_in_str(char *str);

#endif
