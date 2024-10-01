/* Program:  sjf_sched.c
 * Purpose:  using linked list queues for Round-Robin Scheduling
 *=========================================================*/

#include <stdlib.h>
#include <stdio.h>

struct process
{
  char data;
  int burst;
  struct process *next;
};

typedef struct process node;

node *head = NULL; /* ready queue's head */
node *tail = NULL; /* ready queue's tail */

node *fhead = NULL; /* SJF scheduling queue's head */
node *ftail = NULL; /* SJF scheduling queue's tail */

void print_list(node *);

int sjf(node *p); /* the shortest job first scheduling algorithm */

/*insert function for the ready queue */
void insert_to_ready_queue(node *new)
{
  if (tail == NULL) /* empty list */
    head = new;
  else
    tail->next = new;
  tail = new;
}

void insert_to_schedule_queue(node *new) // ready_queue in activity 1
{
  if (ftail == NULL) /* empty list */
    fhead = new;
  else
    ftail->next = new;
  ftail = new;
}

int main()
{
  node *p;
  int i;

  /* initializing the ready queue for SJF */
  for (i = 1; i <= 6; i++)
  {
    p = (node *)malloc(sizeof(node));
    p->data = 64 + i;
    p->burst = (int)((double)(99) * rand() / (999999999 + 1.0));
    p->next = NULL;
    insert_to_ready_queue(p);
  }

  printf("The ready queue for the SJF scheduling is: \n\n");
  print_list(head);
  printf("\n\n");

  /* FJF scheduling */
  sjf(head);
  printf("The resulting SJF schedule is: \n\n");
  print_list(fhead);
  printf("\n\n");

  return 0;
}

int sjf(node *p)
{
  // For each sjf function call, we will find the shortest job in the waiting queue.
  // use recursive call to find the next shortest job in the waiting queue until the waiting queue is empty.

  if (p == NULL) /* just return if the waiting queue is empty*/
    return 0;

  if (p->next == NULL) /* only one node in the waiting queue*/
  {
    insert_to_schedule_queue(p);
    return 0;
  }

  // if there're more than 1 node in the waiting queue, we will find the shortest job in the waiting queue,
  // remove it from the waiting queue and add it to the scheduling queue.
  node *shortest_node = p;
  node *current_node = p;

  while (current_node != NULL)
  {
    if (current_node->burst < shortest_node->burst)
    {
      shortest_node = current_node;
    }
    current_node = current_node->next;
  }

  // delete the shortest job in the waiting queue (google: delete a node from the linked list)
  if (shortest_node == p) // meaning the shortest node is the head
  {
    // remove the head
    head = shortest_node->next;
    shortest_node->next = NULL; // clearing the next pointer
  }
  else
  {
    node *node_before_the_shortest_node = p;
    while (node_before_the_shortest_node->next != shortest_node)
    {
      node_before_the_shortest_node = node_before_the_shortest_node->next;
    }
    node_before_the_shortest_node->next = shortest_node->next;
    shortest_node->next = NULL;
  }

  // add the shortest job to the scheduling queue
  insert_to_schedule_queue(shortest_node);

  sjf(head); /* Recursive call */

  return 0;
}

void print_list(node *p)
{
  if (p == NULL)
    printf("^\n");
  else
  {
    while (p->next)
    {
      printf("(%c, %d) --> ", p->data, p->burst);
      p = p->next;
    }
    printf("(%c, %d) ^\n ", p->data, p->burst);
  }
}
