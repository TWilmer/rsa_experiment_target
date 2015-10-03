/*
 * rsa.h
 *
 *  Created on: 02-Oct-2015
 *      Author: Thorsten Wilmer
 */
#include "rsa.h"

#include <stdlib.h>
#include <stdint.h>

static int createRandom(unsigned char *p, int len, void *dat)
{
	FILE *i=fopen("/dev/urandom","r");
	int ret=fread(p, 1, len,i);
	fclose(i);
	return ret;

}

static int createRandom2(unsigned char *p, int len, void *dat)
{

	for(uint32_t i=0;i<len;i++)
	{
		char rc;
		unsigned int val;
		__asm__ volatile(
				"rdrand %0 ; setc %1"
				: "=r" (val), "=qm" (rc)
		);

		p[i]=val& 0xFF;

	}
	return len;
}


void GenerateKeys(mp_int *d, mp_int *e, mp_int *n)
{


	while (1)
	{
	mp_int p;
	mp_init(&p);

	mp_prime_random_ex(&p,8,2048, LTM_PRIME_2MSB_ON, &createRandom,NULL);

	mp_print("P",&p);

	mp_int q;
	mp_init(&q);

	mp_prime_random_ex(&q,8,2048, LTM_PRIME_2MSB_ON, &createRandom,NULL);
	mp_print("Q",&q);
	mp_int pp;
	mp_init(&pp);
	mp_sub_d(&p,1,&pp);

	mp_int qq;
	mp_init(&qq);
	mp_sub_d(&q,1,&qq);



	mp_int pq;
	mp_init(&pq);
	mp_mul(&pp,&qq,&pq);

	mp_mul(&p,&q,n);
	mp_set(d, 5);


	mp_int temp;
	mp_init(&temp);
	mp_int g;
	mp_init(&g);


		mp_int t;
		mp_init(&t);
		mp_exteuclid(d,&pq,e, &temp,&g);
		if (mp_cmp_d(&g,1) == 0)
			return ;

		// now we would have to add 1, but we prefer to get some new numbers
		/* printf("Havve to add 1\n");
		mp_add_d(d, 1, &t);
		printf("Exchange 1\n");
		mp_copy(&t,d);*/

	}
}
void EncryptDecrypt(mp_int *result, const mp_int *source,
		  const mp_int *e, const mp_int *n)
{
	//mp_result mp_int_exptmod(mp_int a, mp_int b, mp_int m,
	//			 mp_int c);                    /* c = a^b (mod m) */

	int res=mp_exptmod(source, e, n,result);

}



