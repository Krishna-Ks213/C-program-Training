// wap using array involving enqueue and dequeue opeariton

#include <stdio.h>

#define MAX 5

int queue[MAX];

// Initially queue is empty

int front = -1;
int rear = -1;

// ---------------------- ENQUEUE ----------------------

void enqueue(int value)
{
    // Queue is full
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    // First element inserted
    if (front == -1)
        front = 0;

    // Move rear forward
    rear++;

    // Insert element
    queue[rear] = value;

    printf("%d inserted into queue.\n", value);
    printf("Front = %d, Rear = %d\n", front, rear);
}

// ---------------------- DEQUEUE ----------------------
int dequeue()
{
    // Queue is empty
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = queue[front];

    // Move front forward
    front++;

    // If queue becomes empty after deletion
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }

    printf("Front = %d, Rear = %d\n", front, rear);

    return value;
}

// ---------------------- DISPLAY ----------------------
void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements:\n");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

// ---------------------- MAIN ----------------------
int main()
{
    int choice, value;

    do
    {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);

            /*
            Initially:
            front = -1
            rear = -1

            enqueue(10)

            front = 0
            rear = 0

            Queue:
            10
            */

            enqueue(value);
            break;

        case 2:

            /*
            Queue:
            10 20 30

            front = 0
            rear = 2

            dequeue()

            Remove 10

            front becomes 1
            rear remains 2

            Queue:
            20 30
            */

            value = dequeue();

            if (value != -1)
                printf("Deleted Element = %d\n", value);

            break;

        case 3:
            display();
            break;

        case 4:
            printf("Program Ended.\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 4);

    return 0;
}