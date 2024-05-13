#include<stdio.h>

void Merge(int * A,int * B,int * C,int n,int m) {
    int i, j, k;
    i=j=k=0;
    while(i<n && j<m) {
        if(A[i]<B[j]) {
            C[k]=A[i];
            i++;k++;
        }
        else {
            C[k]=B[j];
            j++;k++;
        }
    }
    while(i<n) {
        C[k]=A[i];
        i++;k++;
    }
    while(j<m) {
        C[k]=B[j];
        j++;k++;
    } 
}

int main()
{
    int A[]={1,4,7,9,15};
    int B[]={2,5,8,12,23,45,67};
    int n=5, m=7;
    int * C=(int *)malloc((m+n)*sizeof(int));
    Merge(A, B, C, n, m);
    for(int i=0;i<m+n;i++)
    printf("%d  ",C[i]);
    return 0;
}