#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printArray(int * arr, int n) {
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
    printf("\n");
}

// void BubbleSort(int * arr, int n) {
//     int t,isSort=0;
//     for(int i=n;i>0;i--) {
//         isSort=1;
//         for(int j=0;j<i;j++) {
//             if(j!=n-1  &&  arr[j]>arr[j+1]) {
//                 t=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=t;
//                 isSort=0;
//             }
//         }
//         if(isSort)
//             return;
//     }
// }

// void selectionSort(int * arr,int n) {
//     int indexofmin,t;
//     for(int i=0;i<n;i++) {
//         indexofmin = i;
//         for(int j=i;j<n;j++) {
//             if(arr[j] < arr[indexofmin]) {
//                 indexofmin = j;
//             }
//         }
//         t = arr[i];
//         arr[i] = arr[indexofmin];
//         arr[indexofmin] = t;
//     }
// }

// void InsertionSort(int * arr,int n) {
//     int key,j;
//     for(int i=1;i<n;i++) {
//         key = arr[i];
//         j=i-1;
//         while(j>=0  && arr[j]>key) {
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = key;
//     }
// }

int main()
{
    int arr[] = {6,9,1,4,13,2,8,5,3,9,10};
    printArray(arr,11);
    InsertionSort(arr,11);
    printArray(arr,11);
    return 0;
}