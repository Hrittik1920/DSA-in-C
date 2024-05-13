#include<stdio.h>
#include<stdlib.h>

void printSort(int * arr, int n) {
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
    printf("\n");
}

void BubbleSort(int * arr, int n) {
    int t,isSort=0;
    for(int i=n;i>0;i--) {
        isSort=1;
        for(int j=0;j<i;j++) {
            if(j!=n-1  &&  arr[j]>arr[j+1]) {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                isSort=0;
            }
        }
        if(isSort)
            return;
    }
}

int main()
{
    int t, n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int * arr=(int *)malloc(n*sizeof(int));
    int isSort=0;
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    printSort(arr, n);
    BubbleSort(arr, n);
    printSort(arr, n);
    return 0;
}