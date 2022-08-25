/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:11:58 by younhwan          #+#    #+#             */
/*   Updated: 2022/08/25 16:28:41 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>

// ft_printf.c
int	ft_printf(const char *str, ...);
// ft_print_char.c
int	ft_print_char(int c);
// ft_print_str.c
int	ft_print_str(const char *str);
// ft_print_ptr.c
int	ft_print_ptr(unsigned long long ptr);
// ft_print_nbr.c
int	ft_print_nbr(const int nbr);
// ft_print_unsigned_int.c
int	ft_print_unsigned_int(unsigned int nbr);
// ft_print_hex.c
int	ft_print_hex(unsigned int nbr, const char format);

#endif