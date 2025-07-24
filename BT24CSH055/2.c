//creating ll in descending order
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int n, int data[])
{
    struct node **head = NULL;
    *head = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;
    for (int i = 0; i < n; i++)
    {
        temp->data = data[i];
        temp->next = (struct node *)malloc(sizeof(struct node));
        temp = temp->next;
    }
    temp->next = NULL;
    return *head;
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int data[n];
    printf("data = ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &data[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[i] > data[j])
            {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    struct node *head = create(n, data);
    print(head);
    return 0;
}