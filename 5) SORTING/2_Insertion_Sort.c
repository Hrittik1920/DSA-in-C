#include<stdio.h>

void printSort(int * arr, int n) {
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
    printf("\n");
}

void Insertion_Sort(int * arr, int n) {
    int key, j;
    for(int i=1;i<=n-1;i++) {
        key=arr[i];
        j=i-1;
        while(j>=0  &&  arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    Insertion_Sort(arr, n);
    printSort(arr, n);
    return 0;
}