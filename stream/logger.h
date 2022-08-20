#ifndef _STREAM_LOGGER_H_INCLUDED_
#define _STREAM_LOGGER_H_INCLUDED_

void log_critical(const char *format, ...);
void log_error(const char *format, ...);
void log_warn(const char *format, ...);
void log_info(const char *format, ...);
void log_debug(const char *format, ...);
void log_trace(const char *format, ...);

#endif // _STREAM_LOGGER_H_INCLUDED_
