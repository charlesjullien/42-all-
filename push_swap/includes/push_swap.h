/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:06:36 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/02 13:21:57 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/errno.h>

typedef struct s_data	t_data;
struct			s_data
{
	long	min;
	long	max;
	long	chunks;
	long	*med;
	long	*med_len;
	long	index_min;
	long	index_max;
	long	moves_min;
	long	moves_max;
	long	dir_min;
	long	dir_max;
	long	index_selected;
	long	moves_selected;
	long	dir_selected;
	long	len;
	long	to_fill;
	long	*sorted;
	long	len_a;
	long	len_b;
	long	*a;
	long	*b;
	long	*a_copy;
	long	*b_copy;
};

int		check_argvs(int ac, char **av);
void	get_len(t_data *d, int ac, char **av, int i);
void	parser(t_data *d, int ac, char **av);
void	check_no_doublon(t_data *d);
void	get_min_max(t_data *d);
int		is_invalid(char *str);
void	ft_swap(long *a, long *b);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int n);
int		ft_is_space(char c);
void	sorted_push_min_first(t_data *d);
void	copy_stacks(t_data *d);
void	sort_two(t_data *d);
void	sort_three(t_data *d);
void	sort_four(t_data *d);
void	sort_five2(t_data *d);
void	sort_five(t_data *d);
void	sort_6_or_more(t_data *d);
void	get_a_sorted(t_data *d);
void	op_sa(t_data *d);
void	op_sb(t_data *d);
void	op_pa(t_data *d);
void	op_pb(t_data *d);
void	op_rrb(t_data *d);
void	op_rra(t_data *d);
void	op_rb(t_data *d);
void	op_ra(t_data *d);
void	ft_quit(t_data *d);
void	get_chunks(t_data *d);
void	move_chunk_into_b(t_data *d, long n, long i);
void	move_chunk_into_a_2(t_data *d);
void	get_index_min_max_2(t_data *d, long *min, long *max, long i);
void	get_nb_moves(t_data *d);
void	i_want_to_be_free(t_data *d);

#endif
