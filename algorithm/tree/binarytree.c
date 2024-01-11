#include <stdio.h>
#include <stdlib.h>

#define N 7

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct
{
    Node *root;
} Tree;

void insert(Tree *tree, int x)
{
    Node *node = malloc(sizeof(Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;

    if (tree->root == NULL)
    {
        tree->root = node;
    }

    else
    {
        Node *temp = tree->root;

        while (temp)
        {
            if (x < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = node;
                    return;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = node;
                    return;
                }
                temp = temp->right;
            }
        }
    }
}

int getHeight(Node* node){
    if (node == NULL) {
        return 0;
    }
    int l = getHeight(node->left);
    int r = getHeight(node->right);
    return (l>r?l:l) + 1;
}

int getMax(Node* node){
    if (node == NULL){
        return -1;
    }
    int l = getMax(node->left);
    int r = getMax(node->right);
    int max = l>r?l:r;
    max = max>node->data?max:node->data;
    return max;
}

void inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d -> ", node->data);
        inorder(node->right);
    }
}

void preorder(Node *node)
{
    if (node != NULL)
    {
        printf("%d -> ", node->data);
        preorder(node->left);

        preorder(node->right);
    }
}

int main()
{

    int arr[N] = {6, 3, 8, 2, 5, 1, 7};

    Tree t;
    t.root = NULL;
    for (int i = 0; i < N; i++)
    {
        insert(&t, arr[i]);
    }
    preorder(t.root);

    int r = getHeight(t.root);
    printf("%d\n",r);

    r = getMax(t.root);
    printf("%d\n",r);
}
