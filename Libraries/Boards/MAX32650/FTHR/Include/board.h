/**
 * @file 	board.h
 * @brief   Board support package API.
 */

/* *****************************************************************************
 * Copyright (C) 2017 Maxim Integrated Products, Inc., All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of Maxim Integrated
 * Products, Inc. shall not be used except as stated in the Maxim Integrated
 * Products, Inc. Branding Policy.
 *
 * The mere transfer of this software does not imply any licenses
 * of trade secrets, proprietary technology, copyrights, patents,
 * trademarks, maskwork rights, or any other form of intellectual
 * property whatsoever. Maxim Integrated Products, Inc. retains all
 * ownership rights.
 *
 * $Date: 2017-07-17 18:10:38 -0500 (Mon, 17 Jul 2017) $
 * $Revision: 28913 $
 *
 **************************************************************************** */

#include <stdio.h>
#include "spixf.h"

#ifndef _BOARD_H
#define _BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#define BOARD_FTHR 1 /// Used in examples to control program flow.

#ifndef CONSOLE_UART
#define CONSOLE_UART 0 /// UART instance to use for console
#endif

#ifndef CONSOLE_BAUD
#define CONSOLE_BAUD 115200 /// Console baud rate
#endif

#define LED_OFF 1 /// Inactive state of LEDs
#define LED_ON  0 /// Active state of LEDs

#ifndef EXT_FLASH_BAUD
#define EXT_FLASH_BAUD 1000000
#endif

/**
 * @brief   Initialize the BSP and board interfaces.
 * @return  #E_NO_ERROR if everything is successful
 */
int Board_Init(void);

/**
 * @brief   Initialize or reinitialize the console. This may be necessary if the
 *          system clock rate is changed.
 * @return  #E_NO_ERROR if everything is successful
 */
int Console_Init(void);

/**
 * @brief   Attempt to prepare the console for sleep.
 * @return  #E_NO_ERROR if ready to sleep, #E_BUSY if not ready for sleep.
 */
int Console_PrepForSleep(void);

/**
 * @brief   Initialize the PMIC to output correct voltages  only needed for rev 1,2, and 3 boards/
 * @return  #E_NO_ERROR if everything is successful
 */
int MAX77650_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* _BOARD_H */