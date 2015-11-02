/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 02:23:03 by ymonfray          #+#    #+#             */
/*   Updated: 2015/07/11 02:23:03 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					check_doublons(void)
{
	int				stats[6];
	int				sum;
	int				count;
	t_pile			*t;

	//MIN-MAX
	printf("AFN: %d\n", AFN);
	stats[0] = AFN;
	stats[1] = ALN;
	//QUARTILES
	stats[2] = AFN;
	stats[3] = AFN;
	stats[4] = AFN;

	//ERROR
	stats[5] = 0;

	count = 0;
	sum = AFN;
	t = AF;
	while (t->n)
	{
		// printf("FUCK\n");
		count++;
		stats[0] = (*t->n < stats[0]) ? *t->n : stats[0];
		stats[1] = (*t->n > stats[1]) ? *t->n : stats[1];
		sum += *t->n;
		t = t->nt;
	}
	printf("Count: %d\tMin: %d\tMax: %d\tSum: %d\n", count, stats[0], stats[1], sum);
	printf("Avg Mean: %d\tAvg Mean Loc: %d%%\tAvg Step: %f\tAvg Spread: %f\n", sum / count, 100 * sum / (count * (stats[1] - stats[0])), sum / (float)(stats[1] - stats[0]), (stats[1] - stats[0]) / (float)count);
	
	char			*st;

	int range = (stats[1] - stats[0]);
	st = (char *)malloc(sizeof(char) * range);
	for (int i = 0; i < range; i++)
		st[i] = 0;
	t = AF;
	int median = 0;
	int maxcount = count >> 1;
	count = 0;
	while (t->n)
	{
		count++;
		if (count == maxcount)
			median = *t->n;
		st[*t->n] = 1;
		t = t->nt;
	}
	printf("Median: %d\n", median);
	count = 0;
	int k = 0;
	for (int j = 0; j < range; j++)
		if (st[j])
		{
			count++;
			printf("%d ", j);
			if (count % (maxcount / 2) == 0)
				stats[2 + k++] = j;
		}
	printf("\n");
	for (k=0;k<3;k++)
		printf("Median Value: %d\n", stats[2+k]);
	return (1);
}


int					**init_parse(char **nums, int len)
{
	static int		*ori;
	int				n;
	int				zero;

	zero = 1;
	if (!ori)
		ori = (int *)malloc(sizeof(int) * len);
	while (len--)
	{
		n = strtol(nums[len + 1], (char **)NULL, 10);
		if (n || zero)
			ori[len] = n;
		else
		{
			printf("Error!\n");
			exit(0);
		}
		if (!n & zero)
			zero = 0;
	}
	return (&ori);
}


t_pile				*init_pile_add(t_pile *last, int *n)
{
	t_pile			*num;

	num = NULL;
	if ((num = (t_pile *)malloc(sizeof(t_pile))))
	{		
		num->n = n;
		num->nt = NULL;
		num->pv = last;
		last->nt = num;
	}
	return (num);
}

t_pile				*init_pile(int *ori, int size)
{
	int				i;
	t_pile			*ab;
	t_pile			*o;
	t_pile			*loop;	

	ab = (t_pile *)malloc(sizeof(t_pile));
	loop = (t_pile *)malloc(sizeof(t_pile));
	o = ab;
	i = 0;
	ab->n = &ori[i];
	while (i++ < size)
		ab = init_pile_add(ab, &ori[i]);
	ab = init_pile_add(ab, NULL);
	loop->n = NULL;
	loop->nt = o;
	loop->pv = ab;
	o->pv = loop;
	ab->nt = loop;
	return (o->pv);
}

t_pile				**init_piles(char **av, int ac, int *ori)
{
	static t_pile	**ab;

	ab = (t_pile **)malloc(sizeof(t_pile *) * 2);
	ab[0] = init_pile(ori, ac - 2);
	ab[1] = ab[0]->pv;
	// check_doublons();
	return (ab);
}
// t_pile			*init_pile_empty(int size)
// {
// 	int			i;
// 	t_pile		*b;
// 	t_pile		*o;

// 	b = (t_pile *)malloc(sizeof(t_pile));
// 	o = b;
// 	i = 0;
// 	b->n = NULL;
// 	b->nt = NULL;
// 	b->pv = NULL;
// 	while (i++ < size)
// 		b = init_pile_add(b, NULL);
// 	return (o);
// }


