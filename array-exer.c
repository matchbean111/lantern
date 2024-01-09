#include <stdio.h>

#define MAX 100

int data[MAX];
int count = 0;

void addToEnd(int x)
{
    if (count >= MAX)
    {
        printf("Can't add a value");
    }
    data[count++] = x;
}

void addToFront(int x)
{
    for (int i = count; i >= 0; i--)
    {
        data[i + 1] = data[i];
    }
    data[0] = x;
    count++;
}

void showData(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    addToFront(1);
    addToFront(2);
    addToFront(1);
    addToFront(2);
    addToFront(3);

    showData(data,count);
}
