#include <tommath.h>
#include <assert.h>
#include <stdio.h>
#ifdef BN_MP_GROW_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis
 *
 * LibTomMath is a library that provides multiple-precision
 * integer arithmetic as well as number theoretic functionality.
 *
 * The library was designed directly after the MPI library by
 * Michael Fromberger but has been written from scratch with
 * additional optimizations in place.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 *
 * Tom St Denis, tomstdenis@gmail.com, http://libtom.org
 */

/* grow as required */

int mp_grow (mp_int * a, int size)
{


	a->alloc=size;


	static int max=0;
	if(max<size)
	{
		max=size;

	}


	return MP_OKAY;
}
#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_grow.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
