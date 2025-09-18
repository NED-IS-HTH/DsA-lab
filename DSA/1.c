#include <stdio.h>
#include <stdlib.h>

void max_heapify(int arr[],int n,int i);
void heap_sort(int arr[],int n);
void swap(int c,int d);
void printArr(int arr[],int n);

int main()
{
    printf("Heap sort using array; \n");
    int a[]= {12, 11, 13, 5, 6, 7};
    int n =sizeof(a) / sizeof(a[0]);
    printf("Original array: ");
    printArr(a, n);
    heap_sort(a, n);
    printf("Sorted array : ");
    printArr(a, n);
    return 0;
}

void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
}

void max_heapify(int arr[],int n,int i)
{
    int largest = i;
    int l = 2*i;
    int r =2*i+1;

    if(l<=n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if(l<=n && arr[r] > arr[largest])
    {
        largest = r;
    }
    
    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        max_heapify(arr, n, largest);
    }
}

void heap_sort(int arr[],int n)
{
    for(int i=n/2; i>=1; i--)                             //heapify
    {
        max_heapify(arr,n,i);
    }
    for(int i=n; i>=1; i--)
    {
        swap(arr[1],arr[i]);
        max_heapify(arr,i-1,1);
    }
}

void swap(int c, int d)
{
    int temp = d;
    d = c;
    c = temp;
}