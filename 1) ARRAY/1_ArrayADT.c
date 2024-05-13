#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct myarray{
    int total_size;
    int used_size;
    int *ptr;
};

void createarray(struct myarray *a,int tsize,int usize){
    // (*a).total_size = tsize; 
    // (*a).used_size = usize; 
    // (*a).ptr=(int*)malloc(tsize*sizeof(int));

    a->total_size = tsize; 
    a->used_size = usize; 
    a->ptr=(int*)malloc(tsize*sizeof(int));
}

void putVal(struct myarray *a){
    for(int i=0;i<a->used_size;i++){
        printf("Enter element %d:",i);
        scanf("%d",&(a->ptr)[i]);
    }
}

void getarray(struct myarray *a){
    for(int i=0;i<a->used_size;i++)
    printf("%d  ",(a->ptr)[i]);
}
int main()
{
    int n,m;
    printf("Enter the total size of array:");
    scanf("%d",&n);
    printf("Enter the space you want to use:");
    scanf("%d",&m);
    struct myarray marks;
    createarray(&marks,n,m);
    putVal(&marks);
    getarray(&marks);
    return 0;
}