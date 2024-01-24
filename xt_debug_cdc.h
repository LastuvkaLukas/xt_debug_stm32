/*
 * Name: xt_debug_cdc.h
 * Description:
 *
 * Created Date: January 2024
 * Author:
 * 		Lukáš Laštůvka
 * 		https://github.com/LastuvkaLukas
 *
 * License: Apache License 2.0 (https://www.apache.org/licenses/LICENSE-2.0)
 * Copyright (c) 2024 Lukáš Laštůvka
 *
 */

#pragma once

#ifndef DEBUG_STM32_CDC_ENABLE
__weak void CDC_Connection_Callback(uint8_t status) {}
#endif
#ifdef DEBUG_STM32_CDC_ENABLE
#define DEBUG_ENABLE 1U

#include "usbd_conf.h"
#include "usbd_cdc.h"
#include "usbd_cdc_if.h"

void CDC_Connection_Callback(uint8_t status);

/**
 * Transmits data over USB CDC (Communication Device Class).
 *
 * @param ptr Pointer to the data to be transmitted.
 * @param len Length of the data to be transmitted.
 *
 * @returns The number of bytes transmitted.
 *          Returns 0 if transmission fails.
 */
__weak int _write(int file, char *ptr, int len);
#endif