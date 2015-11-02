/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 02:22:46 by ymonfray          #+#    #+#             */
/*   Updated: 2015/07/11 02:22:46 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// extern t_pile			**ab;

void				print_pile_inline(t_pile *a)
{
	// int				count;
	t_pile			*t;

	// count = 0;
	// t = a;
	// while (t->n)
	// {
	// 	printf("| %d ", count);
	// 	count++;
	// 	t = t->nt;
	// }
	// printf("\n");
	t = a;
	while (a->n)
	{
		printf(" %d ", *a->n);
		a = a->nt;
		if (a->n)
			(*a->n > *a->pv->n) ? printf("<") : printf(">");
	}
	printf("\n\t     ");
	a = t;
	while (a->n)
	{
		a = a->nt;
		if (a->n && a->nt->n)
		{
			(*a->nt->n > *a->pv->n) ? printf("| < |") : printf("| > |");
		}
	}

	printf("\n");
}

void				print_pile(t_pile *a)
{
	int				count;

	count = 0;
	while (a->n)
	{
		printf("Count: %d\tN= %d\n", count, *a->n);
		count++;
		a = a->nt;
	}
}

void				print_piles()
{
	// printf("==========================\n");
	printf("{PILE A} ");
	print_pile_inline(g_ab[0]->nt);
	printf("{PILE B} ");
	print_pile_inline(g_ab[1]->nt);
	// printf("__________________________\n");
	printf("\n");
}

void				ps_op(int op)
{
	op -= 48;
	if (op == 1)
		ps_sa();
	else if (op == 2)
		ps_sb();
	else if (op == 3)
		ps_ss();
	else if (op == 4)
		ps_ra();
	else if (op == 5)
		ps_rb();
	else if (op == 6)
		ps_rr();
	else if (op == 7)
		ps_rra();
	else if (op == 8)
		ps_rrb();
	else if (op == 9)
		ps_rrr();
	else if (op == 0)
		ps_pa();
	else if (op == -2)
		ps_pb();
}



int					main(int ac, char **av)
{
	// static int		*ori;
	int				**nl;
	int				count;
	int				size;
	t_pile			*a;
	t_pile			*b;
	// t_pile			**ab;

	count = 0;
	if (ac > 1)
	{
		nl = init_parse(av, ac - 1);
		g_ab = init_piles(av, ac, *nl);
		check_doublons();
		size = ac - 1;
		while (count < size)
		{
			printf("N: %d\n", nl[0][count]);
			count++;
		}
		print_piles();
		printf("Start Playing...\n");
		printf("Commands: (1) sa (2) sb (3) ss (4) ra (5) rb (6) rr (7)rra (8) rrb (9) rrr (0) pa (.) pb\n");
		char	order;
		while (order != 'q')
		{
			printf("Operation? :");
			// scanf("%s",&order);
			// scanf("Operation?: %s", &order);
			scanf("%s", &order);
			if (order == 'h')
				printf("Commands: (1) sa (2) sb (3) ss (4) ra (5) rb (6) rr (7)rra (8) rrb (9) rrr (10) pa (11) pb\n");
			// printf("OPERTION: %s\n", &order);
			fflush(stdin);
			ps_op(order);
			// fflush(stdout);
			print_piles();
			// printf("Press Any Number...\n");
		}
		// printf("&ORDER INPUT: %c\n", order);
	}
	// print_piles();
	return (0);
}
		// // printf("A1: %d\tA2: %d\n", *(g_ab[0]->nt->n), *(g_ab[0]->nt->nt->n));
		// // printf("B1: %d\tB2: %d\n", *(g_ab[1]->nt->n), *(g_ab[1]->nt->nt->n));
		// // ps_sa();
		// // print_piles();
		// // ps_pb();
		// // print_piles();
		// // ps_pb();
		// // ps_pb();
		// int max = 0;
		// int min = 1000;
		// for (int i = 0;i < atoi(av[ac -1]);i++)
		// {
		// 	min = (AFN < min) ? AFN : min;
		// 	max = (ALN > max) ? ALN : max;
		// 	if (ALN > AFN)
		// 	{
		// 		if (AFN > ASN)
		// 			ps_ra();
		// 		else
		// 		{
		// 			ps_sa();
		// 			ps_ra();
		// 		}
		// 	}
		// 	else
		// 	{
		// 		if (ALN > ASN)
		// 		{
		// 			ps_rra();
		// 			ps_sa();
		// 			ps_ra();
		// 			ps_ra();
		// 		}
		// 		else
		// 		{
		// 			ps_sa();
		// 			ps_rra();
		// 			ps_sa();
		// 			ps_ra();
		// 			ps_ra();
		// 		}
		// 	}
		// 	printf("Iter: %d\tMin: %d\tMax: %d\n", i, min, max);
		// 	if (count > 5 && AFN == min && ALN == max)
		// 	{
		// 		printf("Bingo!\n");
		// 		print_piles();
		// 		ps_rra();
		// 		ps_pb();
		// 		ps_pb();
		// 		ps_sb();
		// 		min ^= max;
		// 		max ^= min;
		// 		min ^= max;
		// 		// while (AF->n)
		// 		// {
		// 		// 	if (AFN > ASN)
		// 		// 		ps_sa();
		// 		// 	ps_pb();
		// 		// }



		// 	}


		// 	// if (ALN > AFN)
		// 	// {
		// 	// 	ps_rra();
		// 	// 	ps_sa();
		// 	// 	ps_ra();
		// 	// 	ps_ra();
		// 	// }
		// 	// printf("BFN: %d\n", BFN);
		// 	// printf("BLN: %d\n", BLN);
		// 	// printf("BSN: %d\n", BSN);
		// 	// printf("AFN: %d\n", AFN);
		// 	// printf("ALN: %d\n", ALN);
		// 	// printf("ASN: %d\n", ASN);
		// 	// if (AFN > BFN)
		// 	// 	ps_pb();
		// 	// if (AFN > ASN)
		// 	// 	ps_sa();
		// 	// ps_ra();

		// 	// ps_rra();
		// 	// ps_rra();
		// 	// else
		// 	// {
		// 	// 	if (BFN < BSN)
		// 	// 	{
		// 	// 		ps_sb();
		// 	// 		ps_pa();
		// 	// 		ps_pa();
		// 	// 	}
		// 	// }
		// 	// ps_ra();
		// 	// ps_ra();
		// 	// ps_ra();
		// 	// ps_ra();
		// 	// print_piles();
		// }

		// 	// if (AFN < ASN)
		// 	// {
		// 	// 	ps_sa();
		// 	// }
		// 	// if (ASN > ALN)
		// 	// 	ps_pb();
		// 	// else
		// 	// 	ps_ra();

		// 	// ps_rra();
		// 	// ps_rra();



		// 	// if (AFN < ASN)
		// 	// {
		// 	// 	ps_sa();
		// 	// 	print_piles();
		// 	// 	ps_pb();
		// 	// }
		// 	// else
		// 	// {
		// 	// 	ps_pb();
		// 	// }
		// 	// if (BFN > BLN)
		// 	// 	ps_rb();














		// // for (int i = 0;i < 2;i++)
		// // {
		// // 	printf("ROUND %d\n", i);
		// // 	ps_pb();
		// // 	ps_pb();
		// // 	print_piles();
		// // 	// ps_pa();
		// // 	ps_rr();
		// // 	// ps_rrr();
		// // 	print_piles();
		// // 	// ps_sa();
		// // 	// print_piles();
		// // 	// ps_sb();
		// // 	// print_piles();
		// // 	// ps_ss();
		// // 	// print_piles();
		// // 	// ps_pb();
		// // 	// print_piles();
		// // }