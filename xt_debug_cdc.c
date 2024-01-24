/*
 * Name: xt_debug_cdc.c
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

#include "xt_debug_cdc.h"

static uint8_t _cdc_connected = 0;
void CDC_Connection_Callback(uint8_t status)
{
    _cdc_connected = status;
}

int _write(int file, char *ptr, int len)
{
    if (!_cdc_connected)
        return len;

    static uint8_t rc = USBD_OK;
    do
    {
        rc = CDC_Transmit_FS((uint8_t *)ptr, len);
    } while (USBD_BUSY == rc && _cdc_connected);

    if (USBD_FAIL == rc)
    {
        Error_Handler();
        return 0;
    }
    return len;
}