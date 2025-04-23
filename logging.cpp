#include <Arduino.h>
extern "C" {
  #include "logging.h"
}

void log_serial(const char *msg) {
  Serial.println(msg);
}