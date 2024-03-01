#include <stdio.h>

#include "s21_string.h"

#define MAX_MESSAGE 200
char message[MAX_MESSAGE];
const char *errors[ERRMAX + 2] = ERRORS;

char *s21_strerror(int errnum) {
  if ((errnum >= -1) && (errnum < ERRMAX)) {
    s21_strcpy(message, errors[errnum + 1]);
  } else {
#if (defined(UBUNTU) || defined(__APPLE__) || defined(__MACH__))
    sprintf(message, "%s %d", errors[ERRMAX + 1], errnum);
#else  // other linux
    s21_strcpy(message, errors[ERRMAX + 1]);
#endif
  }
  return message;
}