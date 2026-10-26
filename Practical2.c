#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert()
{
    int x;

    if ((rear + 1) % SIZE == front)
        printf("Queue is Full\n");
    else
    {
        printf("Enter value: ");
        scanf("%d", &x);

        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        queue[rear] = x;
    }
}

void delete()
{
    if (front == -1)
        printf("Queue is Empty\n");
    else
    {
        printf("Deleted: %d\n", queue[front]);

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display()
{
    int i;

    if (front == -1)
        printf("Queue is Empty\n");
    else
    {
        printf("Queue: ");
        i = front;

        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}