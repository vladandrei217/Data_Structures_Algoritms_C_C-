#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define inaltime 100

//ex1a
int cmp(int *a,int* b);
void swap(int *a, int *b);
void selectionSort(int nodes[], int first, int last,  int (*cmp)(int * a, int* b));
void printNodes(int nodes[], int last);

//ex1b
struct node_btree
{
    int info;
    struct node_btree* left;
    struct node_btree* right;
};
struct node_btree *newNode(int n);
void afisare(struct node_btree* root, int lvl);
int lvl(struct node_btree* n);
void tl_tree(struct node_btree* r);

//ex2
struct HuffMannTree {
    char data;
    int freq;
    struct HuffMannTree *left, *right;
};
void printArr(int arr[], int size);
struct HuffMannTree *new_n(char data, int freq);
int isLeaf(struct HuffMannTree *root);
int binarySearch(struct HuffMannTree *arr[], int low, int high, int key);
int deleteElement(struct HuffMannTree * arr[], int n, int key,char* data);
int insertSorted(struct HuffMannTree* arr[], int n, struct HuffMannTree* node, char* data);
struct HuffMannTree *buildHuffmanTree(char data[], int freq[], int size);
void printCodes(struct HuffMannTree *root, int arr[],int top);
void HuffmanCodes(char data[], int freq[], int size);

int main()
{

    return 0;
}

int cmp(int *a,int* b)
{
    if(*a<*b)
        return a;
    else
        return b;
}
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void selectionSort(int nodes[], int first, int last,  int (*cmp)(int * a, int* b))
{
    int i, j;
    int min;
    int size = 0;

    i=0;
    while(nodes[i]!=last)
    {
        if(nodes[i]==first)
        {
            ;
        }
        else
        {
            size++;
            i++;
        }
    }
    for (i = 1; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            min=cmp(nodes[j], nodes[min]);
        }
        swap(nodes[i],nodes[min]);
    }
}
void printNodes(int nodes[], int last)
{
    int i=0;
    while(nodes[i]!=last)
    {
        printf("%d",nodes[i]);
        i++;
    }
    printf("%d",nodes[i]);
}

struct node_btree *newNode(int n)
{

    struct node_btree* nod;
    nod = (struct node_btree *)malloc(sizeof(struct node_btree));
    nod->info = n;
    nod->left = NULL;
    nod->right = NULL;
    return nod;
}
void afisare(struct node_btree* root, int lvl)
{
    if (root == NULL)
        return;
    if (lvl == 1)
        printf("%d ", root->info);
    else if (lvl > 1)
    {
        afisare(root->left, lvl-1);
        afisare(root->right, lvl-1);
    }
}
int lvl(struct node_btree* n)
{
    if (n==NULL)
        return 0;
    else
    {
        int left = lvl(n->left);
        int right = lvl(n->right);
        if (left > right)
            return(left+1);
        else return(right+1);
    }
}
void tl_tree(struct node_btree* r)
{
    int h = lvl(r);
    int i;
    for (i=1; i<=h; i++)
        afisare(r, i);
}


void printArr(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
struct HuffMannTree *new_n(char data, int freq)
{
    struct HuffMannTree *temp = (struct HuffMannTree *) malloc(sizeof(struct HuffMannTree));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
int isLeaf(struct HuffMannTree *root)
{
    return !(root->left) && !(root->right);
}
int binarySearch(struct HuffMannTree *arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2;
    if (key == arr[mid]->freq)
        return mid;
    if (key > arr[mid]->freq)
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid - 1), key);
}
int deleteElement(struct HuffMannTree * arr[], int n, int key,char* data)
{
    int pos = binarySearch(arr, 0, n - 1, key);
    if (pos == -1)
    {
        printf("Element not found");
        return n;
    }
    int i;
    for (i = pos; i < n - 1; i++)
    {
        data[i]=data[i+1];
        arr[i] = arr[i + 1];
    }
    return n - 1;
}
int insertSorted(struct HuffMannTree* arr[], int n, struct HuffMannTree* node, char* data)
{
    int i;
    for (i = n - 1; (i >= 0 && arr[i]->freq > node->freq); i--)
        arr[i + 1] = arr[i];
    arr[i + 1] = node;
    data[i+1]=node->data;
    return (n + 1);
}
struct HuffMannTree *buildHuffmanTree(char data[], int freq[], int size)
{
    struct HuffMannTree *top;
    struct HuffMannTree *nodes[size];
    selectionSort(freq, freq[0], freq[size - 1], cmp);
    int i;
    for(i=0;i<size;i++)
        nodes[i]=new_n(data[i],freq[i]);
    while (size>1) {
        top = newNode( nodes[0]->freq + nodes[1]->freq);
        top->left = nodes[0];
        top->right = nodes[1];

        size = deleteElement(nodes, size, nodes[0]->freq, data);

        size = deleteElement(nodes, size, nodes[0]->freq, data);

        size=insertSorted(nodes, size, top, data);
        printf("%d\n",top->freq);
    }
    return new_n(data, freq[0]);
}
void printCodes(struct HuffMannTree *root, int arr[],int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}
void HuffmanCodes(char data[], int freq[], int size) {
    struct HuffMannTree *root = buildHuffmanTree(data, freq, size);
    printf("%d",root->left->freq);
    int arr[inaltime], top = 0;
    printCodes(root, arr, top);
}