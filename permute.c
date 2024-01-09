#include <stdio.h>

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n"); 
    
}

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void perm(int a[],int start, int end){
    if (start==end) {
        printArray(a,end+1);
    }else {
        for (int i=start; i<=end; i++){
            swap(a, start,i);
            perm(a,start+1,end);
            swap(a,start,i);
        }
    }
}

int main() {
    int arr[] = {1,2,3,4,5};
    perm(arr,0,4);
}