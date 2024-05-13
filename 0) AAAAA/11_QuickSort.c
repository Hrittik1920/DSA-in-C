#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int partition(int * arr,int low,int high) {
    int pivot = low,temp;
    int i = low + 1;
    int j = high;
    do {
        while(arr[i] < arr[pivot])
            i++;
        while(arr[j] > arr[pivot])
            j--;
        if(i<j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int * arr,int low,int high) {
    int pos;
    if(low<high) {
        int pos = partition(arr,low,high);
        quickSort(arr,low,pos-1);
        quickSort(arr,pos+1,high);
    }
}

void printArray(int * arr, int n) {
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {6,9,1,4,13,2,8,5,3,9,10};
    printArray(arr,11);
    quickSort(arr,0,10);
    printArray(arr,11);
    return 0;
}