/*
 * Name: xt_debug_def.h
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

#define DEBUG_LEVEL_ERROR 0U
#define DEBUG_LEVEL_WARNING 1U
#define DEBUG_LEVEL_INFO 2U
#define DEBUG_LEVEL_DEBUG 3U
#define DEBUG_LEVEL_VERBOSE 4U

#define DEBUG_COLOR_BLACK "30"
#define DEBUG_COLOR_RED "31"    // ERROR
#define DEBUG_COLOR_GREEN "32"  // INFO
#define DEBUG_COLOR_YELLOW "33" // WARNING
#define DEBUG_COLOR_BLUE "34"
#define DEBUG_COLOR_MAGENTA "35"
#define DEBUG_COLOR_CYAN "36" // DEBUG
#define DEBUG_COLOR_GRAY "37" // VERBOSE
#define DEBUG_COLOR_WHITE "38"

#define DEBUG_COLOR(COLOR) "\033[0;" COLOR "m"
#define DEBUG_BOLD(COLOR) "\033[1;" COLOR "m"
#define DEBUG_RESET_COLOR "\033[0m"