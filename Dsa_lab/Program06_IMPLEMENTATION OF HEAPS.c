#include <stdio.h>

int heap[100];
int size = 0;

void insert(int value)
{
    int i = size;
    heap[size] = value;
    size++;

    while (i > 0 && heap[(i - 1) / 2] < heap[i])
    {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

void display()
{
    int i;

    printf("Heap: ");

    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    int n, i, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(value);
    }

    display();

    return 0;
}

Output:

Enter number of elements: 8
Enter elements:
25
40
15
60
35
50
10
45

Heap: 60 45 50 40 35 15 10 25
