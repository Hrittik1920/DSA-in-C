#include<stdio.h>
#include<stdlib.h>

int linearSearch(int * arr, int n,int element) {
    for(int i=0;i<n;i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int * arr,int low,int high,int element) {
    if(low >= high) {
        return -1;
    }
    if(arr[low] == element) {
        return low;
    }
    if(arr[high] == element) {
        return high;
    }
    int mid = (low + high)/2;
    if(arr[mid] == element) {
        return mid;
    }
    if(element < arr[mid]) {
        return binarySearch(arr,low,mid,element);
    } else {
        return binarySearch(arr,mid+1,high,element);
    }
}

int main() 
{
    int arr[] = {5,7,10,11,12,14,17,23,26,31,46,102};
    printf("%d",binarySearch(arr,0,12,23));
    return 0;
}