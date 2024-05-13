#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printArray(int * A, int n) {
    for(int i=0; i<n; i++)
        printf("%d  ",A[i]);
    printf("\n");
}

void Count_Sort(int * A, int n) {
    int max = INT_MIN;
    int i, j, isSort=0;
    for(int i=0; i<n; i++) {
        if(A[i]>max) {
            max = A[i];
            isSort++;
        }
    }
    if(isSort==n)
        return;
        
    printf("Not sorted\n");
    int * count=(int *)malloc((max+1)*sizeof(int));
    for(i=0; i<=max; i++)
        count[i]=0;
    for(int i=0; i<n; i++) {
        count[A[i]]++;
    }
    i=j=0;
    while(i<=max) {
        if(count[i]>0) {
            A[j]=i;
            count[i]--;
            j++;
        }
        else
            i++;
    }
}


int main()
{
    //int A[]= {1,4,7,2,1,8,32,15};
    int A[]= {1,2,3,4,5,8,23,51};
    int n=8;
    printArray(A, n);
    Count_Sort(A, n);
    printArray(A, n);
    return 0;
}