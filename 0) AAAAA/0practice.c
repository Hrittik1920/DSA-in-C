#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Our Graph
//      0 --- 1
//      | \   |
//      |  \  |
//      |   \ |
//      3 --- 2
//       \   /
//        \ /
//         4
//        / \
//       /   \  
//      5     6
    
        
int visited[7] = {0,0,0,0,0,0,0};
int a[7][7] = {
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

void DFS(int i) {
    printf("%d ",i);
    visited[i] = 1;
    for(int j=0;j<7;j++) {
        if(a[i][j] == 1  &&  !visited[j]) {
            DFS(j);
        }
    }
}

int main()
{
    DFS(0);
    return 0;
}