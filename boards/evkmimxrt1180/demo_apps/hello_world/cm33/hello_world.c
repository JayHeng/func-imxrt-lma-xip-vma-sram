/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

extern volatile uint32_t g_systickCounter;

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/

void SysTick_DelayTicks(uint32_t n)
{
    uint32_t systickCounter = g_systickCounter + n;
    while (g_systickCounter < systickCounter)
    {
    }
}
/*!
 * @brief Main function
 */
extern void * __vector_RAM_table [];
#pragma required=__vector_RAM_table
int main(void)
{
    /* Init board hardware. */
    BOARD_InitHardware();

    PRINTF("hello world.\r\n");

    while (1)
    {
        /* Delay 1000 ms */
        SysTick_DelayTicks(1000U);
        RGPIO_TogglePinsOutput(EXAMPLE_LED_GPIO, 1UL << EXAMPLE_LED_GPIO_PIN);
    }
}
