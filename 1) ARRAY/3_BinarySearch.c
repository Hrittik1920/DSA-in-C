#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Array {
    int size;
    int * ptr;
};

int binarySearch(struct Array * arr,int low,int high,int data) {
    if(low <= high) {
        int mid = (low + high)/2;
        if(arr->ptr[mid] == data) {
            return mid;
        }
        else if (data < (arr->ptr[mid])) {
            return binarySearch(arr,low,mid-1,data);
        }
        else if (data > (arr->ptr[mid])) {
            return binarySearch(arr,mid+1,high,data);
        }
        else {
            return -1;
        }
    }
}

int main()
{
    int element;
    struct Array * arr = (struct Array *)malloc(sizeof(struct Array));
    printf("Enter the size of array:");
    scanf("%d",&(arr->size));
    getchar();

    arr->ptr = (int *)malloc((arr->size) * sizeof(int));
    for(int i=0;i<arr->size;i++) {
        printf("Enter element %d : ",i);
        scanf("%d",&(arr->ptr[i]));
    }
    printf("Enter the element you want to find in the array:");
    scanf("%d",&element);
    int n = binarySearch(arr,0,(arr->size)-1,element);
    if(n == -1) {
        printf("Element is not present in the array!\n");
    } else {
        printf("Element is present on index %d.",n);
    }
    return 0;
}