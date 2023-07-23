#ifndef __CCD_H_
#define __CCD_H_
#include "stm32f4xx.h"


#define CCD_CLK PAout(3)// PA3
#define CCD_SI  PAout(4)// PA4

void CCD_reader(u8 *p);
void CCD_init(void);
void CCD_startbg(void);
void CCD_send(u8 *p);

#endif
