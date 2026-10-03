#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
} *front, *rear, *temp, *front1;

int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();

int count = 0;

int main()
{
    int no, ch, e;

    printf("\n 1- Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Front element");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    printf("\n 7 - Queue size");

    create();

    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d", &no);
                enq(no);
                break;

            case 2:
                deq();
                break;

            case 3:
                e = frontelement();
                if (e != 0)
                    printf("Front element : %d", e);
                else
                    printf("\n No front element in Queue as queue is empty");
                break;

            case 4:
                empty();
                break;

            case 5:
                exit(0);

            case 6:
                display();
                break;

            case 7:
                queuesize();
                break;

            default:
                printf("Wrong choice, Please enter correct choice ");
        }
    }

    return 0;
}

/* Create an empty queue */
void create()
{
    front = rear = NULL;
}

/* Returns queue size */
void queuesize()
{
    printf("\n Queue size : %d", count);
}

/* Enqueuing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
        rear = temp;
    }

    count++;
}

/* Displaying the queue elements */
void display()
{
    front1 = front;

    if (front1 == NULL && rear == NULL)
    {
        printf("Queue is empty");
        return;
    }

    while (front1 != NULL)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
}

/* Dequeuing the queue */
void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\n Error: Trying to delete from empty queue");
        return;
    }

    printf("\n Dequed value : %d", front->info);

    front = front->ptr;
    free(front1);

    count--;

    if (front == NULL)
        rear = NULL;
}

/* Returns the front element of queue */
int frontelement()
{
    if (front != NULL)
        return front->info;
    else
        return 0;
}

/* Display if queue is empty or not */
void empty()
{
    if (front == NULL && rear == NULL)
        printf("\n Queue empty");
    else
        printf("\n Queue not empty");
}

 Output:

 1- Enque
 2 - Deque
 3 - Front element
 4 - Empty
 5 - Exit
 6 - Display
 7 - Queue size

 Enter choice : 1
Enter data : 14

 Enter choice : 1
Enter data : 85

 Enter choice : 1
Enter data : 38

 Enter choice : 3
Front element : 14

 Enter choice : 6
14 85 38

 Enter choice : 7
 Queue size : 3

 Enter choice : 2
 Dequed value : 14

 Enter choice : 6
85 38

 Enter choice : 7
 Queue size : 2

 Enter choice : 4
 Queue not empty

 Enter choice : 5
