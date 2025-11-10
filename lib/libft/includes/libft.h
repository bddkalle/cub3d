/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:16:23 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/07 13:57:24 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef unsigned long	t_size;

void	*ft_memset(void *s, int c, t_size n);
void	ft_bzero(void *s, t_size n);
void	*ft_memcpy(void *dest, const void *src, t_size n);
void	*ft_memmove(void *dest, const void *src, t_size n);
void	*ft_memchr(const void *s, int c, t_size n);
void	*ft_calloc(t_size count, t_size size);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
t_size	ft_strlcat(char *dst, const char *src, t_size dstsize);
t_size	ft_strlcpy(char *dst, const char *src, t_size dstsize);
t_size	ft_strlen(const char *s);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, t_size n);
int		ft_memcmp(const void *s1, const void *s2, t_size n);
char	*ft_strnstr(const char *big, const char *little, t_size len);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, t_size len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_c_isin_str(char c, char *str);
int		ft_str_isin_strs(char *needle, char **needle_box);
int		ft_int_len(long nbr);
int		ft_putptr_fd(void *ptr, int fd);
long	ft_atol(const char *str);
t_size	ft_linelen(const char *s);
char	*get_next_line(int fd);

#endif
