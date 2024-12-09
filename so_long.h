/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:45:17 by enoshahi          #+#    #+#             */
/*   Updated: 2024/12/09 19:45:39 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <mlx.h>

int	ft_concoct(va_list args, const char format);
int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned long num, char base);
int	ft_putnbr(int n);
int	ft_putptr(unsigned long ptr);
int	ft_putstr(char *s);
int	ft_putusd(unsigned int n);

#endif