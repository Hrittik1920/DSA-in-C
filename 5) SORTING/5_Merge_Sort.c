#include<stdio.h>

void printArray(int * A, int n) {
    for(int i=0; i<n; i++)
        printf("%d  ",A[i]);
    printf("\n");
}

void Merge(int * A,int low,int mid, int high) {
    int i=low, j=mid + 1,k=low;
    int * B=(int *)malloc((high+1)*sizeof(int));
    while(i<=mid && j<=high) {
        if(A[i]<A[j]) {
            B[k]=A[i];
            i++;
            k++;
        }
        else {
            B[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid) {
        B[k]=A[i];
        i++;
        k++;
    }
    while(j<=high) {
        B[k]=A[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++)
    A[i]=B[i];
}

void Merge_Sort(int * A, int low, int high) {
    if(low<high) {
        int mid=(low + high)/2;
        Merge_Sort(A, low, mid);
        Merge_Sort(A, mid+1,high);
        Merge(A, low, mid, high);
    }
}


int main()
{
    int A[]= {1,4,7,2,4,8,9,15};
    int n=8;
    Merge_Sort(A, 0,7);
    printArray(A, n);
    return 0;
}