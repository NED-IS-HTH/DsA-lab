//create and display singly ll

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* cr_ll(int n)
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;
    struct node *new_node;
    printf("Data = ");
    for (int i = 0; i < n; i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        scanf("%d ", &new_node ->data);
        temp->next = new_node;
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

void display(struct node *head)
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
    printf("Enter the number of elements n= ");
    scanf("%d", &n);
    struct node *head = cr_ll(n);
    printf("Singly Linked List: ");
    display(head);
    return 0;
}