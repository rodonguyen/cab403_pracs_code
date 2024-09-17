/* Program:  roundRobinScheduling_Skeleton.c
 * Purpose:  Both the Ready Queue and the Job Queue are implemented as Linked Lists.
 * Initial Job Queue: (A, 178)-->(B, 83)-->(C, 166)-->(D, 169)-->(E, 193)
 * Process is taken from the head of the Job queue (A, 178) and
 * assigned a time slice on the CPU equal to the time quantum (20ms).
 * Process A is added to the tail of the Ready queue (A,20). As
 * process A burst time is greater than allocated time quantum (20ms)
 * the process is added back to the tail of the job queue.
 * Job queue now (B, 83)-->(C, 166)-->(D, 169)-->(E, 193)-->(A, 158)
 * Ready Queue now (A,20)
 * Process B taken from Job queue assigned time slice and then returned
 * to tail of Job Queue as process not completed. State of both linked lists now:
 * Job Queue: (C, 166)-->(D, 169)-->(E, 193)-->(A, 158)-->(B, 63)
 * Ready Queue: (A, 20)-->(B,20)
 *================================================================================*/

#include <stdlib.h>
#include <stdio.h>

typedef struct process
{
  char processID;
  int burstTime;
  struct process *nextNode;
} node;

node *jobQueueHead = NULL; /* Job queue head */
node *jobQueueTail = NULL; /* Job queue tail */

node *readyQueueHead = NULL; /* Ready Queue head, scheduling linked list */
node *readyQueueTail = NULL; /* Ready queue's tail */

void printLinkedList(node *headOfLinkedList);

/*Function to insert Node (Process) back to the tail
 * of the Job Queue - Job Queue is a circular queue
 * \param jobQueueNode - node to be added to tail of
 *        Job Queue
 */
void insertNodeToJobQueue(node *jobQueueNode)
{
  if (jobQueueTail == NULL)
  { /* empty list */
    jobQueueHead = jobQueueNode;
  }
  else
  {
    jobQueueTail->nextNode = jobQueueNode;
  }
  jobQueueTail = jobQueueNode;
}

/* Function returns the next node to be taken from the
 * head of the Job Queue
 */
node *removeJobQueueHeadNode()
{
  node *headOfJobQueue;
  if (jobQueueHead == NULL)
  { /* list empty */
    return (NULL);
  }

  headOfJobQueue = jobQueueHead;
  if (jobQueueHead == jobQueueTail)
  {                                     /* only one element in the list */
    jobQueueHead = jobQueueTail = NULL; // make both head and tail NULL
  }
  else
  {
    jobQueueHead = jobQueueHead->nextNode;
  }
  return (headOfJobQueue);
}

/* Function inserts a new node to the tail
 * of the Ready Queue representing a process
 * allocated a time slice on the CPU
 * \param newReadyQueueNode: node to add to tail of Ready Queue
 */
void insertNodeToReadyQueue(node *newReadyQueueNode)
{
  if (readyQueueTail == NULL)
  { /* empty list */
    readyQueueHead = newReadyQueueNode;
  }
  else
  {
    readyQueueTail->nextNode = newReadyQueueNode;
  }

  // make the new node the tail of the ready queue
  readyQueueTail = newReadyQueueNode;
}

int main()
{
  int i;
  int quantum = 20; // time quantum

  /* initializing the ready queue for RR */
  node *processingNode;
  for (i = 1; i <= 5; i++)
  {
    processingNode = malloc(sizeof(node));
    processingNode->processID = 64 + i;
    processingNode->burstTime = (int)((double)(99) * rand() / (999999999 + 1.0));
    processingNode->nextNode = NULL;
    insertNodeToJobQueue(processingNode);
  }

  printf("The Job Queue Processes to be executed using a Round Robin Scheduling Algorithm: \n\n");
  printLinkedList(jobQueueHead);
  printf("\n\n");

  /* Create a loop until the Job queue is empty */
  while (jobQueueHead != NULL)
  {
    /* the RR scheduling algorithm, insert your solution here for task1 */
    // get the first node in the job queue
    processingNode = removeJobQueueHeadNode();
    
    // if the burst time of the first node is less than or equal to the quantum, 
    // then add the node to the ready queue.
    if (processingNode->burstTime <= quantum)
    {
      insertNodeToReadyQueue(processingNode);
      continue;
    }

    // if the burst time of the first node is greater than the quantum,
    // then subtract the quantum from the burst time of the first node.
    // add the node to the ready queue.
    node *nextJobToPutInJobQueue = malloc(sizeof(node));
    nextJobToPutInJobQueue->burstTime = processingNode->burstTime - quantum;
    nextJobToPutInJobQueue->processID = processingNode->processID;
    nextJobToPutInJobQueue->nextNode = NULL;
    insertNodeToJobQueue(nextJobToPutInJobQueue);

    node *jobToPutInReadyQueue = malloc(sizeof(node));
    jobToPutInReadyQueue->burstTime = quantum;
    jobToPutInReadyQueue->processID = processingNode->processID;
    jobToPutInReadyQueue->nextNode = NULL;
    insertNodeToReadyQueue(jobToPutInReadyQueue);
  }

  printf("The resulting RR schedule is: \n\n");
  printLinkedList(readyQueueHead);
  printf("\n\n");

  return 0;
}

/* Helper function to print out a linked list
 * \param headNode: the head of the linked list to be printed
 */
void printLinkedList(node *headOfLinkedList)
{
  if (headOfLinkedList == NULL)
  {
    printf("^\n");
  }
  else
  {
    while (headOfLinkedList->nextNode)
    {
      printf("(%c, %d) -> ", headOfLinkedList->processID, headOfLinkedList->burstTime);
      headOfLinkedList = headOfLinkedList->nextNode;
    }
    printf("(%c, %d) \n ", headOfLinkedList->processID, headOfLinkedList->burstTime);
  }
}
