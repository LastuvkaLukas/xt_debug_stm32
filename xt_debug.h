/*
 * Name: xt_debug.h
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

#include "main.h"
#include "stdio.h"
#include "stdarg.h"

#include "xt_debug_def.h"
#include "xt_debug_cdc.h"

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_LEVEL_INFO
#endif

#ifdef DEBUG_COLOR_ENABLE
#define DEBUG_PRINT(LEVEL, COLOR, TAG, ...) printf(COLOR "[" #LEVEL "] " DEBUG_RESET_COLOR DEBUG_BOLD(DEBUG_COLOR_WHITE) TAG ": " DEBUG_RESET_COLOR __VA_ARGS__)
#else
#define DEBUG_PRINT(LEVEL, COLOR, TAG, ...) printf("[" #LEVEL "] " TAG ": " __VA_ARGS__)
#endif

#ifdef DEBUG_ENABLE
#define XT_LOGE(TAG, ...) DEBUG_PRINT(E, DEBUG_BOLD(DEBUG_COLOR_RED), TAG, ##__VA_ARGS__)

#if DEBUG_LEVEL >= DEBUG_LEVEL_WARNING
#define XT_LOGW(TAG, ...) DEBUG_PRINT(W, DEBUG_BOLD(DEBUG_COLOR_YELLOW), TAG, ##__VA_ARGS__)
#else
#define XT_LOGW(TAG, ...)
#endif

#if DEBUG_LEVEL >= DEBUG_LEVEL_INFO
#define XT_LOGI(TAG, ...) DEBUG_PRINT(I, DEBUG_COLOR(DEBUG_COLOR_GREEN), TAG, ##__VA_ARGS__)
#else
#define XT_LOGI(TAG, ...)
#endif

#if DEBUG_LEVEL >= DEBUG_LEVEL_DEBUG
#define XT_LOGD(TAG, ...) DEBUG_PRINT(D, DEBUG_COLOR(DEBUG_COLOR_CYAN), TAG, ##__VA_ARGS__)
#else
#define XT_LOGD(TAG, ...)
#endif

#if DEBUG_LEVEL >= DEBUG_LEVEL_VERBOSE
#define XT_LOGV(TAG, ...) DEBUG_PRINT(V, DEBUG_COLOR(DEBUG_COLOR_GRAY), TAG, ##__VA_ARGS__)
#else
#define XT_LOGV(TAG, ...)
#endif
#else
#define XT_LOGE(TAG, ...)
#define XT_LOGW(TAG, ...)
#define XT_LOGI(TAG, ...)
#define XT_LOGD(TAG, ...)
#define XT_LOGV(TAG, ...)
#endif