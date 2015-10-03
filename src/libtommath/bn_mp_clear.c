#include <tommath.h>
#ifdef BN_MP_CLEAR_C
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

/* clear one (frees)  */
void
mp_clear (mp_int * a)
{
  int i;


    for (i = 0; i < a->used; i++) {
        a->digi[i] = 0;
    }


    /* reset members to make debugging easier */

    a->alloc = 512;
    a->used = 0;
    a->sign  = MP_ZPOS;

}
#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_clear.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
