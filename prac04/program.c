#include <stdio.h>
#include <stdarg.h>
#define DEBUG_ON
void debug(const char *fmt, ...)
{
#ifdef DEBUG_ON
  va_list args;
  va_start(args, fmt);
  fprintf(stderr, "DEBUG: ");
  vfprintf(stderr, fmt, args);
  va_end(args);
#endif /* DEBUG_ON */
}
int main()
{
  debug("Started program");
}