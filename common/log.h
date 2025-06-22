#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LOG_INFO 0
#define LOG_ERROR 1

#ifdef LOGGING
//
#define LOG(lvl, fmt, ...) {\
    FILE* stream = ((lvl) == LOG_ERROR) ? stderr : stdout;\
    fprintf(stream, "%s [%s:%d]: ", ((lvl) == LOG_ERROR) ? "ERROR" : "INFO", __FILE__, __LINE__);\
    fprintf(stream, fmt, __VA_ARGS__);\
    fprintf(stream, "\n");\
}
//
#define ASSERT(cond) for(; !(cond); assert(cond), cond = cond)
#define ASSERT_LOG(cond, fmt, ...) ASSERT(cond) LOG(LOG_ERROR, fmt, __VA_ARGS__);
//
#else
//
#define LOG(lvl, fmt, ...)
//
#define ASSERT(cond)
#define ASSERT_LOG(cond, fmt, ...)
//
#endif /* LOGGING */

#endif /* __LOG_H__ */