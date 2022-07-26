/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:32:24 by kyhan             #+#    #+#             */
/*   Updated: 2022/06/06 14:39:20 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_info
{
	char	type;
	int		precision;
	int		is_zero;
	int		minus;
	int		plus;
	int		hash;
	int		space;
	int		period;
	int		width;

}			t_info;

int		ft_printf(const char *format, ...);
int		parse_format(va_list ap, char *format);
int		behind_percent(char *format, int *index, va_list ap);
int		print_parsed(t_info *info, va_list ap);

int		print_char(t_info *info, va_list ap);
int		print_percent(t_info *info);
int		print_zero(t_info *info);
int		print_space(t_info *info);

int		setting_info(t_info *info, char *format, int index);
int		setting_info_zero(t_info *info, int index);
char	*ftt_strchr(char *s, int c);
size_t	ft_strlen(char *str);
void	init_info(t_info *info);

int		nbrlen(long n);
void	ft_putnbr(long n);
int		print_int(t_info *info, va_list ap);
int		print_unsigned(t_info *info, va_list ap);

int		putminus(long n);
int		put_plus_space(t_info *info, long n);
int		put_space(t_info *info, long n);
int		put_zero(t_info *info, long n);
int		put_final(t_info *info, long n);

int		pr_strlen(t_info *info, char *str);
int		str_zero(t_info *info, char *str);
int		str_space(t_info *info, char *str);
int		ft_putstr(char *str, int len);
int		print_str(t_info *info, va_list ap);

int		ptr_print(t_info *info, unsigned long long ptr);
int		ptr_zero(t_info *info, unsigned long long ptr);
int		ptr_space(t_info *info, unsigned long long ptr);
int		ptr_hash(t_info *info, unsigned long long ptr);
int		print_ptr(t_info *info, va_list ap);

int		ptr_len(t_info *info, unsigned long long ptr);
void	ft_puthex(unsigned long long ptr, char type);

#endif