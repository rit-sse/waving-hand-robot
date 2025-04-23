#ifndef _logging
#define _logging

#ifdef __cplusplus
extern "C" {
#endif

void log_serial_char(const char *msg);

void log_serial_float(const float msg);

#ifdef __cplusplus
}  // extern "C"
#endif
#endif