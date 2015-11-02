/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_def.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 02:21:56 by ymonfray          #+#    #+#             */
/*   Updated: 2015/07/11 02:21:57 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOA_DEF_H
# define LOA_DEF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <inttypes.h>

# define A				g_ab[0]
# define AF				A->nt
# define AS				AF->nt
# define AL				B->pv
# define AFN			*(AF->n)
# define ASN			*(AS->n)
# define ALN			*(AL->n)

# define B				g_ab[1]
# define BF				B->nt
# define BS				BF->nt
# define BL				A->pv
# define BFN			*(BF->n)
# define BSN			*(BS->n)
# define BLN			*(BL->n)


typedef	struct s_pile t_pile;

struct 			s_pile
{
	int			*n;
	t_pile		*nt;
	t_pile		*pv;
};

#endif