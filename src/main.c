/*
 * main.c
 *
 *  Created on: 20-Sep-2015
 *      Author: thorsten
 */

#include "board.h"
#include "rsa.h"
#include "CommonDigest.h"

#define TICKRATE_HZ1 (6)       /* 10 ticks per second */

void SysTick_Handler(void)
{

	//Board_LED_Toggle(3);
	//Board_LED_Toggle(0);
	Board_LED_Toggle(2);
}

const uint32_t N_len=512;
const uint8_t N[512]={0xae, 0x04, 0xfc, 0x15, 0xfb, 0x93, 0x86, 0x55, 0xf1, 0x06, 0x2e, 0x08, 0x95, 0x6f, 0x03, 0xcd, 0x9f, 0x1b, 0xfd, 0x1a, 0xde, 0x41, 0x3e, 0xe8, 0x14, 0xa2, 0x5f, 0x03, 0xcc, 0xe6, 0x26, 0x54, 0x15, 0x6c, 0xce, 0x17, 0xa3, 0xcf, 0xef, 0x63, 0x91, 0x92, 0xb4, 0x3c, 0x20, 0x38, 0x7d, 0xf9, 0x0f, 0x71, 0xac, 0xdd, 0xb2, 0x62, 0xb2, 0x60, 0x3d, 0x4a, 0x98, 0x4c, 0x69, 0xb2, 0x12, 0x7b, 0xb6, 0x9d, 0x01, 0x5d, 0xe3, 0xde, 0x66, 0x7b, 0x17, 0x55, 0xb3, 0x48, 0x2e, 0x63, 0xec, 0xc3, 0x83, 0xc2, 0x96, 0x16, 0x76, 0x15, 0x1d, 0x16, 0x62, 0x31, 0x9c, 0xad, 0x6f, 0xc5, 0xc6, 0x71, 0x81, 0x04, 0xee, 0x93, 0x9a, 0x92, 0x2e, 0xe7, 0xa0, 0x35, 0xbc, 0x5c, 0x43, 0xf1, 0x1e, 0x79, 0x34, 0x03, 0xa6, 0xe9, 0xcf, 0xc8, 0x3f, 0x7f, 0xe7, 0xf2, 0xfd, 0x3c, 0x58, 0xf0, 0x51, 0x29, 0x4e, 0x79, 0xbd, 0x7c, 0x12, 0x51, 0xc8, 0x13, 0xb1, 0x44, 0x67, 0x28, 0x3e, 0x3a, 0xb2, 0x0b, 0x1d, 0x44, 0x14, 0xbb, 0xca, 0x49, 0xca, 0x6a, 0x40, 0xc1, 0xa8, 0xc9, 0xca, 0x86, 0x24, 0x57, 0x9e, 0x0f, 0xa9, 0x37, 0x3f, 0x0f, 0x1e, 0xc9, 0x35, 0xc0, 0x97, 0x7d, 0x4a, 0xc3, 0xf4, 0x3c, 0x51, 0xb9, 0xaa, 0xc7, 0x3e, 0xde, 0xfd, 0x0d, 0x6e, 0x6d, 0xf2, 0x64, 0x0d, 0x32, 0x2b, 0xbe, 0xbf, 0xca, 0x1c, 0xf1, 0xe4, 0x15, 0xb8, 0xcb, 0xac, 0xd0, 0x36, 0xee, 0x00, 0x33, 0xfe, 0x4d, 0xa2, 0xc7, 0xa4, 0x44, 0x6e, 0x3d, 0xc3, 0xfe, 0x0c, 0xc5, 0x11, 0x02, 0x66, 0x7e, 0x79, 0xd9, 0x44, 0x98, 0x08, 0x88, 0x6f, 0x2a, 0x7c, 0xdb, 0xc8, 0x21, 0x02, 0x14, 0xc2, 0x21, 0x91, 0x61, 0x24, 0x90, 0x50, 0x3a, 0x7a, 0xb7, 0x8d, 0x2e, 0xb6, 0xee, 0x1a, 0x9b, 0x11, 0x09, 0xb5, 0xf0, 0x5d, 0xb2, 0xa8, 0x48, 0x8a, 0x0d, 0x90, 0xa4, 0xb6, 0x7d, 0xf3, 0x52, 0x59, 0x2c, 0x96, 0x17, 0x3c, 0x97, 0x6d, 0x3a, 0xae, 0x25, 0x10, 0x06, 0x00, 0xe0, 0xcf, 0x86, 0x90, 0xd4, 0x6f, 0x98, 0x89, 0xe4, 0xed, 0xd6, 0x53, 0x94, 0x92, 0x1e, 0x89, 0xc4, 0xc3, 0x7c, 0x2a, 0xf9, 0xbe, 0x60, 0x04, 0xa4, 0x47, 0x75, 0x38, 0x9c, 0x9e, 0xc1, 0x1d, 0x22, 0x93, 0x95, 0x13, 0xab, 0x8f, 0x0a, 0xcf, 0xca, 0xbd, 0x49, 0x0d, 0xab, 0xa1, 0x63, 0xcc, 0x4f, 0x43, 0x50, 0xa1, 0xba, 0x31, 0x50, 0x89, 0xbc, 0xe3, 0xb9, 0x55, 0x42, 0xac, 0xb7, 0xaf, 0x13, 0x05, 0x96, 0x80, 0x41, 0x80, 0x51, 0x17, 0xac, 0xc7, 0xe6, 0x25, 0x33, 0xb6, 0x1a, 0x36, 0x41, 0x77, 0x4b, 0x5f, 0xb6, 0xdb, 0x0b, 0xf0, 0xe5, 0xbc, 0xe3, 0x12, 0x48, 0xc7, 0xc9, 0x3b, 0x89, 0xc7, 0xa3, 0x5b, 0xe8, 0xda, 0x8e, 0x0d, 0xd7, 0x29, 0x81, 0x03, 0xf6, 0x15, 0x2b, 0x50, 0x02, 0xee, 0xfd, 0x16, 0xe9, 0x8f, 0x5c, 0xce, 0x89, 0x07, 0x44, 0x6c, 0xc9, 0x57, 0x4c, 0x6d, 0x7d, 0x72, 0xc6, 0xa5, 0x23, 0x4e, 0x57, 0xd2, 0x5b, 0x88, 0x51, 0x36, 0xb8, 0xc2, 0xc0, 0xe5, 0x54, 0x57, 0x21, 0x64, 0xf9, 0xcc, 0x86, 0xca, 0xe6, 0xe0, 0xb5, 0x1e, 0x34, 0xb7, 0xba, 0xfe, 0x0f, 0x56, 0x31, 0x71, 0x27, 0x93, 0x5f, 0xa4, 0x49, 0x08, 0x62, 0xa7, 0xb1, 0x2c, 0xe7, 0xf2, 0xe2, 0xdd, 0xbb, 0xb5, 0x6f, 0x79, 0xb7, 0xcd, 0x7d, 0x38, 0x9e, 0xe9, 0x6f, 0x31, 0x99, 0xfd, 0xca, 0x64, 0xdf, 0x30, 0x21, 0x88, 0x4f, 0xb4, 0x0c, 0x71, 0xfe, 0x80, 0x0c, 0xc8, 0x55, 0x0b, 0xcf, 0xf1, 0xd0, 0x0b, 0xd8, 0xd2, 0xca, 0x1e, 0x75, 0xc4, 0x40, 0x34, 0x86, 0x87, 0xbf, 0xec, 0x2e, 0x05, 0x40, 0x0d, 0xf3, 0xe9, 0xd3, };

const uint32_t result_len=512;
const uint8_t result[512]={0x74, 0x3a, 0x76, 0xa2, 0x02, 0xac, 0x86, 0xd5, 0x22, 0x61, 0xad, 0x35, 0x11, 0x13, 0x3b, 0x91, 0x61, 0xd4, 0x7f, 0xdc, 0x4c, 0xa6, 0xef, 0xd8, 0x51, 0xe0, 0x69, 0x84, 0xe1, 0xe6, 0xc7, 0xcb, 0xfc, 0xf1, 0xce, 0x56, 0xcc, 0xcc, 0xc3, 0x6e, 0x97, 0x3f, 0x23, 0x49, 0x7d, 0x75, 0x5e, 0xa6, 0xb8, 0xa4, 0xd3, 0xf8, 0xfa, 0xfd, 0x44, 0x23, 0xbb, 0x0e, 0x9a, 0x6b, 0xb0, 0xae, 0x9f, 0x66, 0x09, 0xea, 0xa7, 0xfd, 0x45, 0x2b, 0x7b, 0x16, 0x66, 0xae, 0xd8, 0x92, 0x39, 0x41, 0xe1, 0x87, 0x7f, 0xdf, 0x3e, 0x07, 0x58, 0x2f, 0xf3, 0xad, 0x78, 0x32, 0xf0, 0xee, 0xe0, 0x04, 0x35, 0xa1, 0xea, 0x24, 0x7c, 0x83, 0x6e, 0x61, 0x32, 0x65, 0x13, 0xe1, 0xb1, 0xb3, 0xb2, 0xf4, 0x60, 0x37, 0xd7, 0xa4, 0x30, 0x1e, 0xc5, 0xa5, 0xaa, 0xd7, 0x3c, 0xd3, 0x23, 0x23, 0x22, 0x9a, 0xfd, 0x82, 0xa7, 0xd8, 0xea, 0x50, 0xed, 0x27, 0x6f, 0xf6, 0xfd, 0xbd, 0x47, 0x76, 0x8d, 0x65, 0x06, 0xf2, 0x37, 0xde, 0xde, 0x84, 0x8a, 0xdc, 0xb4, 0x5a, 0x30, 0xe6, 0x17, 0x5c, 0xea, 0xf8, 0x09, 0xc6, 0xad, 0x07, 0x7f, 0xff, 0xf1, 0x0f, 0xfd, 0xba, 0x32, 0x77, 0x43, 0xc9, 0x1a, 0x8a, 0xa3, 0x3e, 0x43, 0x91, 0xe1, 0xe5, 0xcd, 0x66, 0x5c, 0xc1, 0x32, 0x6e, 0x65, 0x5d, 0x7e, 0x89, 0x49, 0xa6, 0x5b, 0x5b, 0xef, 0xdb, 0x45, 0x2d, 0x6f, 0xe4, 0x66, 0xa5, 0xf8, 0xf3, 0x45, 0xdf, 0x25, 0xc4, 0xae, 0xc3, 0xf7, 0x06, 0x18, 0xcf, 0x73, 0x71, 0xa8, 0x03, 0x50, 0xb8, 0x7b, 0x12, 0x53, 0x2e, 0x95, 0xf3, 0x47, 0x2d, 0xbc, 0x4a, 0x9c, 0x34, 0x91, 0x07, 0x3e, 0x5b, 0x6b, 0x7a, 0xe0, 0x8f, 0x30, 0x98, 0x49, 0xf0, 0xc1, 0x23, 0xa1, 0xfd, 0xbb, 0x03, 0xb8, 0xbd, 0xfb, 0xb4, 0xed, 0xd0, 0x33, 0x34, 0x70, 0x8d, 0xdb, 0x18, 0xd6, 0xb3, 0x6f, 0xf4, 0x70, 0x9c, 0x14, 0xf7, 0x03, 0x68, 0x56, 0x1a, 0x26, 0x48, 0xee, 0x86, 0x5c, 0x09, 0x1e, 0x59, 0xb1, 0x6b, 0xce, 0x50, 0xec, 0x28, 0xd9, 0xe0, 0xa5, 0xfa, 0x29, 0xee, 0x35, 0x67, 0x8b, 0x6a, 0x72, 0x16, 0xfe, 0x1d, 0xba, 0x2a, 0xaf, 0x13, 0x8a, 0xd4, 0xe2, 0x87, 0x6d, 0x96, 0x88, 0x8f, 0x75, 0xf9, 0x79, 0x3c, 0x25, 0xed, 0x9a, 0x80, 0x3e, 0x34, 0x48, 0xcf, 0xa4, 0x9a, 0xc2, 0x62, 0xbe, 0x99, 0xcc, 0xf0, 0x5c, 0xbe, 0x87, 0xe0, 0x29, 0x41, 0xb6, 0xb7, 0x4a, 0xeb, 0x5a, 0x51, 0xa9, 0xfd, 0x78, 0xbb, 0xbc, 0x0a, 0xc3, 0xd8, 0xa1, 0x5c, 0x32, 0xde, 0xa1, 0x7f, 0xb3, 0x62, 0x85, 0xf5, 0x23, 0xcd, 0x00, 0x55, 0xe9, 0xe0, 0x88, 0xda, 0x72, 0xd8, 0x30, 0xb1, 0x60, 0x12, 0x02, 0xa4, 0x8b, 0x29, 0x08, 0x15, 0xfe, 0x41, 0xdd, 0x6b, 0xc8, 0xa8, 0xb3, 0x78, 0xc1, 0x89, 0x32, 0x1d, 0xa1, 0xbb, 0xc1, 0x57, 0x90, 0x5e, 0x9d, 0xf1, 0x72, 0xce, 0x4f, 0x6a, 0xbf, 0xa9, 0x52, 0x17, 0x79, 0x9b, 0xcd, 0x88, 0xab, 0x9c, 0xd0, 0x07, 0x1d, 0xa4, 0x63, 0x98, 0xe8, 0xd3, 0x3c, 0xa6, 0x09, 0xba, 0xce, 0xe3, 0xb9, 0x56, 0x15, 0x25, 0x77, 0xfa, 0x2c, 0xaf, 0xe4, 0x16, 0xc0, 0x31, 0x1e, 0xd7, 0x1e, 0x84, 0xb8, 0xbc, 0xad, 0x30, 0x16, 0x2f, 0x8c, 0x71, 0x41, 0xe0, 0xa2, 0x37, 0x46, 0x6e, 0x2a, 0xbe, 0xb0, 0xc0, 0x04, 0xa9, 0x7b, 0x69, 0xb1, 0x5c, 0x17, 0x02, 0x8d, 0x3d, 0xf5, 0xcd, 0x34, 0x1b, 0xb2, 0x09, 0xf0, 0xd9, 0x76, 0xa3, 0xff, 0x2e, 0x27, 0xca, 0x47, 0x86, 0x8b, 0x77, 0x80, 0x74, 0xc5, 0x7b, 0xe9, 0xbd, 0x88, 0x89, 0xaa, 0x8f, 0xf0, 0x28, 0x72, 0xa2, 0x00, 0xd7, 0xd5, 0x40, };

int test1()
{

	/*

	  this takes on LPC1768 with 97 MHz 465 ms
	 wrote 20480 bytes from file /tmp/targetboard.bin with this function
	 wrote 4096 bytes from file /tmp/targetboard.bin
	- so the RSA related stuff takes 16384 bytes - including any padding
*/
		mp_int d;
	mp_int n;
	mp_int res;
	mp_int output;
	mp_init(&d);
	mp_init(&n);
	mp_init(&output);
	mp_init(&res);
	mp_set(&d, 5);
	if(0!=mp_read_unsigned_bin(&res,result, result_len))
	{

	}


	mp_read_unsigned_bin(&n,N, N_len);

	EncryptDecrypt(&output,&res, &d, &n);


	return 0;
}


#define TICKRATE1_HZ 1000
volatile int tickCounter;
void TIMER1_IRQHandler(void)
{
	if (Chip_TIMER_MatchPending(LPC_TIMER1, 1)) {
		Chip_TIMER_ClearMatch(LPC_TIMER1, 1);
		Board_LED_Toggle(0);
		tickCounter++;
	}

}
static int start=0;
static int done=0;
CC_SHA256_CTX sha2;

unsigned char md[512];
int main(void)
{

	Board_Init();
	Board_SetupClocking();

	SystemCoreClockUpdate();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);
	tickCounter=0;
	uint32_t timerFreq;
	Chip_TIMER_Init(LPC_TIMER1);
	timerFreq = Chip_Clock_GetPeripheralClockRate(SYSCTL_PCLK_TIMER1);
	Chip_TIMER_Reset(LPC_TIMER1);
	Chip_TIMER_MatchEnableInt(LPC_TIMER1, 1);
	Chip_TIMER_SetMatch(LPC_TIMER1, 1, (timerFreq / TICKRATE1_HZ));
	Chip_TIMER_ResetOnMatchEnable(LPC_TIMER1, 1);
	Chip_TIMER_Enable(LPC_TIMER1);
	NVIC_EnableIRQ(TIMER1_IRQn);
	NVIC_ClearPendingIRQ(TIMER1_IRQn);
	Board_LED_Set(1, 1);
	Board_LED_Toggle(0);

	start=tickCounter;
//	test1();

/*
	CC_SHA384_Init(&sha2);
	// doing a 512k Flash sheck takes 1263ms
	CC_SHA384_Update(&sha2, 0,512*1024); // just for benchmark purpose - take 512k of flash

	CC_SHA384_Final(md, &sha2);
	*/
/*
	CC_SHA256_Init(&sha2);
		// doing a 512k Flash sheck takes 365ms
		CC_SHA256_Update(&sha2, 0,512*1024); // just for benchmark purpose - take 512k of flash

		CC_SHA256_Final(md, &sha2);

		// plain copy takes 39ms ~ factor 10, is this general?
	*/
	volatile int i=0;
	int k;
	unsigned char *in=0;
	for(k=0;k<512*1024;k++)
	{
	i=in[k];
	}
	done=tickCounter;
	Board_LED_Toggle(0);
	while (start<done) {
		int r =Buttons_GetStatus();
		if(r==BUTTONS_BUTTON2)
		{
			Board_LED_Set(1, 1);
		}else{
			Board_LED_Set(1, 0);
		}
	}
}