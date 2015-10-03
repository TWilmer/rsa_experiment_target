/*
 * rsa.h
 *
 *  Created on: 02-Oct-2015
 *      Author: thorsten
 */

#ifndef RSA_H_
#define RSA_H_

#include "tommath.h"

void GenerateKeys(mp_int *d, mp_int *e, mp_int *n);

void EncryptDecrypt(mp_int *result, const mp_int *source,
  const mp_int *e, const mp_int *n);

#endif /* RSA_H_ */
