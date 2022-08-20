#include "logger.h"
#include <stdio.h>
#include <stdarg.h>

enum LogLevel {
    NONE,
    CRITICAL,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE,
    ALL
};

#ifndef _LOG_LEVEL_
  #define _LOG_LEVEL_ INFO 
#endif

#define _LOG_LEVEL_CHECK_(level) \
    do { \
        if (_LOG_LEVEL_ == NONE || _LOG_LEVEL_ < level) return; \
    } while (0);

#define _LOG_LEVEL_PRINT_(stream, format) \
    do { \
        va_list args; \
        va_start(args, format); \
        vfprintf(stream, format, args); \
        va_end(args); \
    } while (0);

void print_log(enum LogLevel level, FILE *stream, const char *format, ...);

void log_critical(const char *format, ...)
{
    _LOG_LEVEL_CHECK_(CRITICAL);
    _LOG_LEVEL_PRINT_(stderr, format);
}

void log_error(const char *format, ...)
{
    _LOG_LEVEL_CHECK_(ERROR);
    _LOG_LEVEL_PRINT_(stderr, format);
}

void log_warn(const char *format, ...)
{
    _LOG_LEVEL_CHECK_(WARN);
    _LOG_LEVEL_PRINT_(stdout, format);
}

void log_info(const char *format, ...)
{
    _LOG_LEVEL_CHECK_(INFO);
    _LOG_LEVEL_PRINT_(stdout, format);
}

void log_debug(const char *format, ...)
{
    _LOG_LEVEL_CHECK_(DEBUG);
    _LOG_LEVEL_PRINT_(stdout, format);
}

void log_trace(const char *format, ...)
{
    _LOG_LEVEL_CHECK_(TRACE);
    _LOG_LEVEL_PRINT_(stdout, format);    
}
