#include <stdio.h>

static char msg[100];
static const size_t msgsize = sizeof(msg);

void report_error(const char *str)
{
  char msg[80];
  snprintf(msg, msgsize, "Error: %s\n", str);
  /* ... */
  /* The snprintf function takes multiple arguments. The first argument is the buffer where the formatted string will be stored. This buffer should have enough space to accommodate the formatted string, including the null terminator. The second argument is the maximum number of characters to be written to the buffer, including the null terminator. The remaining arguments are similar to the printf function, where you can specify the format string and any additional values to be formatted and inserted into the string. */
}

int main(void)
{
  /* ... */
  report_error("some error");
  return 0;
}

////////////////////////////////////////////////////
#include <stdio.h>

static char message[100];
static const size_t message_size = sizeof(message);

void report_error(const char *str)
{
  char msg[80];
  snprintf(msg, sizeof(msg), "Error: %s\n", str);
  /* ... */
}

int main(void)
{
  /* ... */
  report_error("some error");
  return 0;
}