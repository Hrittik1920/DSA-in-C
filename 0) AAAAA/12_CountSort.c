#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

void printArray(int * arr, int n) {
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
    printf("\n");
}

void countSort(int * arr,int n) {
    int max = INT_MIN;
    int i,j;
    for(int i=0;i<n;i++) {
        if(arr[i] > max) 
            max = arr[i];
    }
    int * count = (int *)malloc((max+1)*sizeof(int));
    for(int i=0;i<=max;i++) 
        count[i] = 0;
    for(int i=0;i<n;i++) {
        count[arr[i]]++;
    }
    i=j=0;
    while(i<=max) {
        if(count[i]>0) {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
            i++;
    }
}

int main()
{
    int arr[] = {6,9,1,4,13,2,8,5,3,9,10};
    printArray(arr,11);
    countSort(arr,11);
    printArray(arr,11);
    return 0;
}