/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:35:31 by younhwan          #+#    #+#             */
/*   Updated: 2022/07/06 10:41:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

// Part 1 - Libc functions
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *str);
void	*ft_memset(void *dest, int c, size_t n);
void	ft_bzero(void *b, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t sz_);
size_t	ft_strlcat(char *dest, const char *src, size_t sz_);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);

// Part 2 - Additional functions
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif