/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <lucmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:53:21 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/09 13:21:42 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define MIN_INT	-2147483648
# define MAX_INT	2147483647
# define MIN_LONG	-9223372036854775808U
# define MAX_LONG	9223372036854775807U

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_vector2
{
	int				x;
	int				y;
}					t_vector2;

typedef struct		s_dvector2
{
	long double		x;
	long double		y;
}					t_dvector2;

typedef struct		s_vector3
{
	int				x;
	int				y;
	int				z;
}					t_vector3;

typedef struct		s_matrix
{
	int				**mat;
	t_vector2		*dim;
}					t_matrix;

long long			ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_tolower(int c);
int					ft_toupper(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(long long n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_islower(int c);
int					ft_isupper(int c);
void				ft_lstadd_back(t_list **alst, t_list *new);
int					ft_isblank(int c);
char				*ft_strcapitalize(char *str);
void				ft_lstfree_all(t_list **alst);
void				ft_lstfree_at(t_list **alst, size_t index);
size_t				ft_lstsize(t_list **alst);
int					ft_lstreplace(t_list **alst, t_list *todel, t_list *nelem);

t_dvector2			*new_dvector2(double x, double y);
t_dvector2			*add_dvector2(t_dvector2 *u, t_dvector2 *v, int free);
t_dvector2			*sub_dvector2(t_dvector2 *u, t_dvector2 *v, int free);
t_dvector2			*mul_dvector2(t_dvector2 *u, t_dvector2 *v, int free);
int					scal_dvector2(t_dvector2 *u, t_dvector2 *v, int free);

t_vector2			*new_vector2(int x, int y);
t_vector2			*add_vector2(t_vector2 *u, t_vector2 *v, int free);
t_vector2			*sub_vector2(t_vector2 *u, t_vector2 *v, int free);
t_vector2			*mul_vector2(t_vector2 *u, t_vector2 *v, int free);
int					scal_vector2(t_vector2 *u, t_vector2 *v, int free);

t_vector3			*new_vector3(int x, int y, int z);
t_vector3			*add_vector3(t_vector3 *u, t_vector3 *v, int free);
t_vector3			*sub_vector3(t_vector3 *u, t_vector3 *v, int free);
t_vector3			*mul_vector3(t_vector3 *u, t_vector3 *v, int free);
int					scal_vector3(t_vector3 *u, t_vector3 *v, int free);

t_vector2			*vector2_copy(t_vector2 *src);
t_vector3			*vector3_copy(t_vector3 *src);

long double			ft_abs(long double x);
int					ft_max(int a, int b);
int					ft_atoi_base(char *nb, int base);
unsigned long long	ft_power(unsigned long long x, unsigned long long n);

t_matrix			*mat_create(size_t lx, size_t ly);
void				mat_display(t_matrix *mat);
void				mat_free(t_matrix *mat);
t_matrix			*mat_add(t_matrix *m1, t_matrix *m2, int del);
t_matrix			*mat_sub(t_matrix *m1, t_matrix *m2, int del);
t_matrix			*mat_mscal(t_matrix *m1, int scal, int del);
t_matrix			*mat_transpose(t_matrix *m1, int del);
t_matrix			*mat_mul(t_matrix *m1, t_matrix *m2, int del);

int					ft_iscinstr(char *str, char c);
char				*ft_strfchr(char *str, int c);
#endif
