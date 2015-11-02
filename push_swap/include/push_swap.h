/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 02:22:04 by ymonfray          #+#    #+#             */
/*   Updated: 2015/07/11 02:22:04 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "push_swap_def.h"

t_pile			**g_ab;

void			ps_pa(void);
void			ps_pb(void);

void			ps_sa(void);
void			ps_sb(void);
void			ps_ss(void);

void			ps_ra(void);
void			ps_rb(void);
void			ps_rr(void);

void			ps_rra(void);
void			ps_rrb(void);
void			ps_rrr(void);

void			ps_init(t_pile **c);

int				**init_parse(char **nums, int len);
t_pile			*init_pile(int *ori, int size);
t_pile			**init_piles(char **av, int ac, int *ori);

int				check_doublons(void);

#endif