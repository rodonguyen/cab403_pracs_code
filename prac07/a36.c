#include <stdio.h>
static char msg[100];
static const size_t msgsize = sizeof(msg);

void report_error(const char *str)
{
  char msg[80];
  snprintf(msg, msgsize, "Error: %s\n", str);
  /* ... */
}

int main(void)
{
  /* ... */
  report_error("some error");
  return 0;
}

///////////////////////////////////
// #include <stdio.h>

// static char msg[100];
// static const size_t msgsize = sizeof(msg);

// void report_error(const char *str)
// {
//   char msg[80];
//   snprintf(msg, msgsize, "Error: %s\n", str);
//   /* ... */
// }

// int main(void)
// {
//   /* ... */
//   report_error("some error");
//   return 0;
// }

// ////////////
// #include <stdio.h>

// static char message[100];
// static const size_t message_size = sizeof(message);

// void report_error(const char *str)
// {
//   char msg[80];
//   snprintf(msg, sizeof(msg), "Error: %s\n", str);
//   /* ... */
// }

// int main(void)
// {
//   /* ... */
//   report_error("some error");
//   return 0;
// }