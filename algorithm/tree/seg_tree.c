#include <stdio.h>

#define MAX_LEN 1000

void build_tree(int arr[], int tree[], int node, int start, int end){
    if (start == end) {
        tree[node] = arr[start];
    }else {
        int mid = start + (end - start) / 2; 
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        build_tree(arr,tree,left_node, start, mid);
        build_tree(arr,tree,right_node, mid+1,end);

        tree[node] = tree[left_node]+ tree[right_node];
    } 
}

void update_tree(int arr[], int tree[], int node, int start, int end, int index, int value){
    if (start == end) {
        arr[index] = value;
        tree[node] = value;
    }else{
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        if (index >= start && index <= mid) {
            update_tree(arr, tree,left_node, start, mid,index,value);
        }else {
            update_tree(arr, tree,right_node, mid+1, end,index,value);
        }
        tree[node] = tree[left_node]+ tree[right_node];
    }
   
}

int query_tree(int arr[], int tree[], int node, int start, int end, int L, int R){
    printf("start = %d\n", start);
    printf("end = %d\n", end);
    printf("\n");
    if (R < start || L > end) {
        return 0;
    } else if (start == end) {
        return tree[node];
    } else if (L <= start && end <= R){
        return tree[node];
    }else {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        int sum_Left = query_tree(arr,tree,left_node, start, mid, L,R);
        int sum_right = query_tree(arr,tree,right_node,mid+1,end,L,R);

        return sum_Left + sum_right;
    }
}


void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[] = {1,3,5,7,9,11};
    int size = 6;
    int tree[MAX_LEN] = {0};

    build_tree(arr, tree, 0, 0, size-1);

    for (int i=0; i<15; i++) {
        printf("tree[%d] = %d\n", i,tree[i]);
    }
    printf("\n");

    update_tree(arr,tree,0,0,size-1,4,6);
    for (int i=0; i<15; i++) {
        printf("tree[%d] = %d\n", i,tree[i]);
    }

    printf("\n");
    int s = query_tree(arr,tree,0,0,size-1,2,5);
    printf("%d\n",s);
    return 0;
}