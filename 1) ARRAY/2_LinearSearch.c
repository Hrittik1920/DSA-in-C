#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Array {
    int size;
    int * ptr;
};

int linearSearch(struct Array * arr,int data) {
    for(int i=0;i<arr->size;i++) {
        if((arr->ptr[i]) == data) {
            return i;
        }
    }
    return -1;
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
    int n = linearSearch(arr,element);
    if(n == -1) {
        printf("Element is not present in the array!\n");
    } else {
        printf("Element is present on index %d.",n);
    }
    return 0;
}