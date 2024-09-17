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

node *sjf_head = NULL; /* SJF scheduling queue's head */
node *sjf_tail = NULL; /* SJF scheduling queue's tail */

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

void insert_to_sjf_queue(node *new)
{
  if (sjf_tail == NULL) /* empty list */
    sjf_head = new;
  else
    sjf_tail->next = new;
  sjf_tail = new;
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
  print_list(sjf_head);
  printf("\n\n");

  return 0;
}

int sjf(node *p)
{
  // return 0 if queue is empty
  if (p == NULL)
    return 0;

  // only 1 node in queue
  if (p->next == NULL)
  {
    insert_to_sjf_queue(p);
    return 0;
  }

  // iterate throught the whole linked list to find the shortest job
  node *current_node = p;
  node *shortest_node = p;

  while (current_node != NULL)
  {
    if (current_node->burst < shortest_node->burst)
    {
      shortest_node = current_node;
    }
    current_node = current_node->next;
  }

  // delete the shortest job in the ready queue
  if (shortest_node == p) // meaning the shortest node is the head
  {
    // remove the head
    head = shortest_node->next;
    shortest_node->next = NULL; // clearing the next pointer
  }
  else
  {
    // do another search to look for the node before the shortest node,
    // allowing us to remove the shortest node in the linked list
    node *node_before_the_shortest_node = p;
    while (node_before_the_shortest_node->next != shortest_node)
    {
      node_before_the_shortest_node = node_before_the_shortest_node->next;
    }
    node_before_the_shortest_node->next = shortest_node->next;
    shortest_node->next = NULL;
  }

  // don't forget to insert the shortest node to the SJF queue
  insert_to_sjf_queue(shortest_node);

  // move to the next node
  sjf(head);

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
      printf("(%c, %d) -> ", p->data, p->burst);
      p = p->next;
    }
    printf("(%c, %d) \n ", p->data, p->burst);
  }
}
