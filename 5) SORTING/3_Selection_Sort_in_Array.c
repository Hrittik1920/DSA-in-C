#include<stdio.h>

void printSort(int * arr, int n) {
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);
    printf("\n");
}

//  34  2  56  48  1
//  2   34 56  48  1

void Selection_Sort(int * arr, int n) {
    int indexofmin, t;
    for(int i=0;i<n-1;i++) {
        indexofmin=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[indexofmin])
                indexofmin=j;
        }
        t=arr[i];
        arr[i]=arr[indexofmin];
        arr[indexofmin]=t;
    }
}

int main()
{
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int * arr=(int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    printSort(arr, n);
    Selection_Sort(arr, n);
    printSort(arr, n);
    return 0;
}