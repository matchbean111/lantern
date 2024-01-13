#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void heapify(int tree[], int n, int i){
    if (i >= n) {return;}
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    int max = i;

    if (c1 < n && tree[c1] > tree[max]){
        max = c1;
    }
    if (c2 < n && tree[c2] > tree[max]){
        max = c2;
    }

    if (max != i) {
        swap(tree, max, i);
        heapify(tree,n, max);
    }

}

void printArr(int arr[], int n){
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void build_heap(int tree[], int n){
    int last_node = n-1;
    int parent = (last_node - 1) / 2;
    int i;
    for (i = parent; i >=0; i--) {
        heapify(tree,n,i);
    }
}

void heap_sort(int tree[], int n){
    build_heap(tree,n);
    for (int i=n-1; i>=0; i--) {
        swap(tree,i, 0);
        heapify(tree, i, 0);
    }
}

int main(){
    int tree[] = {4,3,5,1,10,2};
    int n = 6;
    // heapify(tree,n,0); 
    // build_heap(tree, n);
    
    heap_sort(tree, n);
    printArr(tree, n);


    return 0;
}