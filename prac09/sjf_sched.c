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
    //TO DO - Implement SJF Solution
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
