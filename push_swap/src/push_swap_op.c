/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 02:23:12 by ymonfray          #+#    #+#             */
/*   Updated: 2015/07/11 02:23:12 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

////////////////////////////////////////////////////////////////
//PUSH GENERIC
//Pop & Insert Link
void	ps_push(t_pile *one, t_pile *two)
{
	two->pv->nt = two->nt;
	two->nt->pv = two->pv;

	one->nt->pv = two;
	two->nt = one->nt;

	two->pv = one;
	one->nt = two;
}

////////////////////////////////////////////////////////////////
//SWAP GENERIC
//Xor swaps Link Content
void	ps_swap(t_pile *cu, t_pile *nt)
{
	cu->n = (int *)((uintptr_t)cu->n ^ (uintptr_t)nt->n);
	nt->n = (int *)((uintptr_t)cu->n ^ (uintptr_t)nt->n);
	cu->n = (int *)((uintptr_t)cu->n ^ (uintptr_t)nt->n);
}

////////////////////////////////////////////////////////////////
//PUSH
//
void	ps_pa(void)
{
	if (B->nt->n)
		ps_push(A, B->nt);
}

void	ps_pb(void)
{
	if (A->nt->n)
		ps_push(B, A->nt);
}

////////////////////////////////////////////////////////////////
//SWAP
//
void	ps_sa(void)
{
	if (AF->n && AS->n)
		ps_swap(AF, AS);
}

void	ps_sb(void)
{
	if (BF->n && BS->n)
		ps_swap(BF, BS);
}

void	ps_ss(void)
{
	ps_sa();
	ps_sb();
}

////////////////////////////////////////////////////////////////
//ROT
//
void	ps_ra(void)
{
	if (A->nt->n && A->nt->nt->n)
		ps_push(B->pv, A->nt);
}

void	ps_rb(void)
{
	if (B->nt->n && B->nt->nt->n)
		ps_push(A->pv, B->nt);
}

void	ps_rr(void)
{
	ps_ra();
	ps_rb();
}

////////////////////////////////////////////////////////////////
//RROT
//
void	ps_rra(void)
{
	if (A->nt->n && A->nt->nt->n)
		ps_push(A, B->pv);
}

void	ps_rrb(void)
{
	if (B->nt->n && B->nt->nt->n)
		ps_push(B, A->pv);
}

void	ps_rrr(void)
{
	ps_rra();
	ps_rrb();
}








// void			ps_push(t_pile *one, t_pile *two, int ba)
// {
// 	if (two->n)
// 	{
// 		one->n = two->n;
// 		two->n = NULL;
// 		g_ab[ba] = one;
// 		g_ab[!ba] = two->nt;
// 	}
// }

// void			ps_pa(void)
// {
// 	ps_push(g_ab[0]->pv, B, 0);
// }

// void			ps_pb(void)
// {
// 	ps_push(B->pv, g_ab[0], 1);
// }

// void			ps_ra(t_pile *a, t_pile *b);
// void			ps_rb(t_pile *a, t_pile *b);
// void			ps_rr(t_pile *a, t_pile *b);

// void			ps_rra(t_pile *a, t_pile *b);
// void			ps_rrb(t_pile *a, t_pile *b);
// void			ps_rrr(t_pile *a, t_pile *b);