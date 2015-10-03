/*
 * Copyright (c) 2004 Apple Computer, Inc. All Rights Reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */

/*
 * CommonDigest.h - common digest routines: MD2, MD4, MD5, SHA1.
 */

#ifndef	_SECURITY_COMMON_DIGEST_H_
#define _SECURITY_COMMON_DIGEST_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * For compatibility with legacy implementations, all of the functions
 * declared here *always* return a value of 1 (one). This corresponds
 * to "success" in the similar openssl implementations. There are no
 * errors of any kind which can be, or are, reported here, so you can
 * safely ignore the return values of all of these functions if you
 * are implementing new code.
 */

typedef uint32_t CC_LONG;		/* 32 bit unsigned integer */
typedef uint64_t CC_LONG64;		/* 64 bit unsigned integer */

// TWI deleted the stuff which I don't want to see.

/*** SHA256 ***/

#define CC_SHA256_DIGEST_LENGTH		32			/* digest length in bytes */
#define CC_SHA256_BLOCK_BYTES		64			/* block size in bytes */

typedef struct CC_SHA256state_st
{   CC_LONG count[2];
    CC_LONG hash[8];
    CC_LONG wbuf[16];
} CC_SHA256_CTX;

extern int CC_SHA256_Init(CC_SHA256_CTX *c);
extern int CC_SHA256_Update(CC_SHA256_CTX *c, const void *data, CC_LONG len);
extern int CC_SHA256_Final(unsigned char *md, CC_SHA256_CTX *c);

/*** SHA384 ***/

#define CC_SHA384_DIGEST_LENGTH		48			/* digest length in bytes */
#define CC_SHA384_BLOCK_BYTES      128			/* block size in bytes */

/* same context struct is used for SHA384 and SHA512 */
typedef struct CC_SHA512state_st
{   CC_LONG64 count[2];
    CC_LONG64 hash[8];
    CC_LONG64 wbuf[16];
} CC_SHA512_CTX;

extern int CC_SHA384_Init(CC_SHA512_CTX *c);
extern int CC_SHA384_Update(CC_SHA512_CTX *c, const void *data, CC_LONG len);
extern int CC_SHA384_Final(unsigned char *md, CC_SHA512_CTX *c);

/*** SHA512 ***/

#define CC_SHA512_DIGEST_LENGTH		64			/* digest length in bytes */
#define CC_SHA512_BLOCK_BYTES      128			/* block size in bytes */

extern int CC_SHA512_Init(CC_SHA512_CTX *c);
extern int CC_SHA512_Update(CC_SHA512_CTX *c, const void *data, CC_LONG len);
extern int CC_SHA512_Final(unsigned char *md, CC_SHA512_CTX *c);





#ifdef __cplusplus
}
#endif

#endif	/* _SECURITY_COMMON_DIGEST_H_ */
