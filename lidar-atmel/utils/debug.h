/*
 * debug.h
 *
 * Created: 21/09/2021 13:33:43
 *  Author: Lari
 */

/*!
 * Debug macros and the debug level configuration.
 */


#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdio.h>

#define _DEBUG_OFF 0            // Disable logging
#define _DEBUG_LEVEL_CRITICAL 1 // Log *critical* errors only
#define _DEBUG_LEVEL_ERROR 2    // Log errors
#define _DEBUG_LEVEL_WARNING 3  // Log everything unusual
#define _DEBUG_LEVEL_INFO 4     // Log everything

#define _DEBUG_LEVEL _DEBUG_OFF

#define printfln(...) (printf(__VA_ARGS__);fputc('\n', stdout))

#if _DEBUG_LEVEL >= _DEBUG_LEVEL_INFO
#define _DEBUG_INFO(...) (printf(__VA_ARGS__))
#else
#define _DEBUG_INFO(...) ((void)0)
#endif

#if _DEBUG_LEVEL >= _DEBUG_LEVEL_WARNING
#define _DEBUG_WARNING(...) (printf(__VA_ARGS__))
#else
#define _DEBUG_WARNING(...) ((void)0)
#endif

#if _DEBUG_LEVEL >= _DEBUG_LEVEL_ERROR
#define _DEBUG_ERROR(...) (printf(__VA_ARGS__))
#else
#define _DEBUG_ERROR(...) ((void)0)
#endif

#if _DEBUG_LEVEL >= _DEBUG_LEVEL_CRITICAL
#define _DEBUG_CRITICAL(...) (printf(__VA_ARGS__))
#else
#define _DEBUG_CRITICAL(...) ((void)0)
#endif

#endif /* DEBUG_H_ */