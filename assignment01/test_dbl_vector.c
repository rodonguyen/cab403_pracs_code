#include <stdio.h>
#include <stdlib.h>
#include "dbl_vector.h"

/**
 * Generate a random floating point value in [0,100).
 *
 * \return the generated value.
 */
double next_rand()
{
  return 100.0 * rand() / RAND_MAX;
}

/**
 * Writes the contents of a vector to the standard output stream as comma-
 * separated values.
 *
 * \param vec A vector to be written.
 * \param title If not null, a title which is writen before the data.
 */
void print_vector(dbl_vector_t *vec, const char *title)
{
  if (title)
  {
    fprintf(stdout, "%s\n", title);
  }

  for (int i = 0; i < vec->size; i++)
  {
    fprintf(stdout, "%s%0.2f", (i > 0 ? "," : ""), vec->data[i]);
  }

  fprintf(stdout, "\n");
}

/**
 * Push a value at the back of a vector, and display the results with a
 * descriptive title.
 *
 * \param vec The address of a vector which will receive the new item.
 * \param new_item A value to append to the vector.
 */
void push_print(dbl_vector_t *vec, double new_item)
{
  char buff[128];
  snprintf(buff, sizeof(buff), "Push %.2f:", new_item);
  dv_push(vec, new_item);
  print_vector(vec, buff);
}

// /**
//  * Insert a new item at the designated position within a vector.
//  *
//  * \param vec The address of a vector which is to be updated.
//  * \param new_item The item to insert into the vector.
//  * \param pos The position at which the new item is to be inserted.
//  */
// void insert_print(dbl_vector_t *vec, size_t pos, double new_item)
// {
//   char buff[128];
//   snprintf(buff, sizeof(buff), "Insert %.2f at %zu:", new_item, pos);
//   dv_insert_at(vec, pos, new_item);
//   print_vector(vec, buff);
// }

// /**
//  * Delete the item at the designated position within a vector.
//  *
//  * \param vec The address of a vector which is to be updated.
//  * \param pos The position at which the new item is to be inserted.
//  */
// void delete_print(dbl_vector_t *vec, size_t pos)
// {
//   char buff[128];
//   snprintf(buff, sizeof(buff), "Remove element at %zu:", pos);
//   dv_remove_at(vec, pos);
//   print_vector(vec, buff);
// }

/**
 * Advances the output cursor to a new line.
 */
void ln()
{
  printf("\n");
}

// /** A struct used to demonstrate */
// typedef struct
// {
//   double a, b;
// } linear_params_t;

// /**
//  * Prints a linear function of the supplied floating point value, ax+b.
//  *
//  * \param x The input value.
//  * \param p Pointer to a linear_params_t object which contains the coefficients
//  *             a and b.
//  */
// void print_linear_func(double x, void *info)
// {
//   linear_params_t *p = info;
//   double y = p->a * x + p->b;
//   printf("%0.2f * %0.2f + %0.2f = %0.2f\n", p->a, x, p->b, y);
// }

/**
 * The entry point.
 *
 * \return 0 iff program ran successfully.
 */
int main(void)
{
  srand(42);
  dbl_vector_t vec1;

  // Initialise vector, add some data.
  dv_init(&vec1);

  for (int i = 0; i < 10; i++)
  {
    push_print(&vec1, next_rand());
    ln();
  }

  // // Copy vec1 to vec2
  // dbl_vector_t vec2;
  // dv_init(&vec2);
  // dv_copy(&vec1, &vec2);
  // print_vector(&vec2, "Copy vec1 to vec2:");
  // ln();

  // dv_pop(&vec1);
  // print_vector(&vec1, "Pop from vec1:");
  // ln();
  // dv_pop(&vec1);
  // print_vector(&vec1, "Pop from vec1:");
  // ln();
  // dv_pop(&vec1);
  // print_vector(&vec1, "Pop from vec1:");
  // ln();

  // print_vector(&vec2, "vec2 should be unchanged:");
  // ln();

  // printf("Last element of vec1: %.2f\n", dv_last(&vec1));
  // printf("Last element of vec2: %.2f\n", dv_last(&vec2));
  // ln();

  // insert_print(&vec1, 0, next_rand());
  // ln();
  // insert_print(&vec1, 5, next_rand());
  // ln();
  // insert_print(&vec1, 500, next_rand());
  // ln();

  // delete_print(&vec1, 0);
  // ln();
  // delete_print(&vec1, 5);
  // ln();
  // delete_print(&vec1, 500);
  // ln();

  // printf("Evaluate a linear function at each point in vec1:\n");
  // linear_params_t info = {5.5, 3.0};
  // dv_foreach(&vec1, print_linear_func, &info);

  return 0;
}

/*
Push 3.35:
3.35

Push 33.00:
3.35,33.00

Push 69.06:
3.35,33.00,69.06

Push 42.25:
3.35,33.00,69.06,42.25

Push 20.63:
3.35,33.00,69.06,42.25,20.63

Push 25.01:
3.35,33.00,69.06,42.25,20.63,25.01

Push 63.66:
3.35,33.00,69.06,42.25,20.63,25.01,63.66

Push 86.36:
3.35,33.00,69.06,42.25,20.63,25.01,63.66,86.36

Push 30.17:
3.35,33.00,69.06,42.25,20.63,25.01,63.66,86.36,30.17

Push 2.49:
3.35,33.00,69.06,42.25,20.63,25.01,63.66,86.36,30.17,2.49

Copy vec1 to vec2:
3.35,33.00,69.06,42.25,20.63,25.01,63.66,86.36,30.17,2.49

Pop from vec1:
3.35,33.00,69.06,42.25,20.63,25.01,63.66,86.36,30.17

Pop from vec1:
3.35,33.00,69.06,42.25,20.63,25.01,63.66,86.36

Pop from vec1:
3.35,33.00,69.06,42.25,20.63,25.01,63.66

vec2 should be unchanged:
3.35,33.00,69.06,42.25,20.63,25.01,63.66,86.36,30.17,2.49

Last element of vec1: 63.66
Last element of vec2: 2.49

Insert 36.50 at 0:
36.50,3.35,33.00,69.06,42.25,20.63,25.01,63.66

Insert 76.54 at 5:
36.50,3.35,33.00,69.06,42.25,76.54,20.63,25.01,63.66

Insert 31.79 at 500:
36.50,3.35,33.00,69.06,42.25,76.54,20.63,25.01,63.66,31.79

Remove element at 0:
3.35,33.00,69.06,42.25,76.54,20.63,25.01,63.66,31.79

Remove element at 5:
3.35,33.00,69.06,42.25,76.54,25.01,63.66,31.79

Remove element at 500:
3.35,33.00,69.06,42.25,76.54,25.01,63.66,31.79

Evaluate a linear function at each point in vec1:
5.50 * 3.35 + 3.00 = 21.41
5.50 * 33.00 + 3.00 = 184.48
5.50 * 69.06 + 3.00 = 382.85
5.50 * 42.25 + 3.00 = 235.37
5.50 * 76.54 + 3.00 = 423.96
5.50 * 25.01 + 3.00 = 140.57
5.50 * 63.66 + 3.00 = 353.11
5.50 * 31.79 + 3.00 = 177.82
*/