#include <Arduino.h>
extern "C" {
  #include "logging.h"
}

void log_serial_char(const char *msg) {
  Serial.print(msg);
}

void log_serial_float(const float msg) {
  Serial.print(msg);
  Serial.println();
}