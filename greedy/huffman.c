#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node
{
    int data;
    int frequency;
    int flag;
    struct node *left;
    struct node *right;
} node;

char str[100];

void insert(node *p[], int n)
{

    for (int i = 1; i < n + 1; i++)
    {
        node *t = (node *)malloc(sizeof(node));
        t->flag = 1;
         t->left = t->right = NULL;
        printf("\nEnter the data and the frequency : ");
        int x, y;
        scanf("%d%d", &x, &y);
        t->data = x;
        t->frequency = y;
        p[i] = t;
    }
}

void min_heap(node *p[], int i, int n)
{
    int smaller = i;
    if (2 * i <= n && p[smaller]->frequency > p[2 * i]->frequency)
    {
        smaller = 2 * i;
    }
    if ((2 * i + 1) <= n  && p[smaller]->frequency > p[(2 * i) + 1]->frequency)
    {
        smaller = 2 * i + 1;
    }

    if (smaller != i)
    {
        node *t = p[i];
        p[i] = p[smaller];
        p[smaller] = t;
        min_heap(p, smaller, n);
    }
}

void build_heap(node *arr[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
    {
        min_heap(arr, i, n);
    }
}

node *Extract_min(node *p[], int *size)
{
    node *temp = p[1];
    p[1] = p[*size];
    min_heap(p, 1, *size - 1);
    *size = *size - 1;
    return temp;
}

void decrease_key(node *p[], int index)
{
    while (index != 1)
    {
        if (p[index]->frequency < p[index / 2]->frequency)
        {
            node *t = p[index];
            p[index] = p[index / 2];
            p[index / 2] = t;
            index = index / 2;
        }
        else
        {
            break;
        }
    }
}


void print_code(node *p,int k)
{
    if (p->flag == 0)
    {
        str[k] = '0';
        print_code(p->left,k+1);
        str[k] = '1';
        print_code(p->right,k+1);
    }
    else
    {
        str[k] = '\0';
        printf("\n%d has code : %s",p->data,str);
    }
}


void Huffman_coding(node *p[], int n)
{
    build_heap(p, n);
    int size = n;
    for (int i = 0; i < n - 1; i++)
    {
        node *x = Extract_min(p, &size);
        node *y = Extract_min(p, &size);
        node *t = (node *)malloc(sizeof(node));
        t->data = 0;
        t->frequency = x->frequency + y->frequency;
        t->left = x;
        t->right = y;
        t->flag = 0;
        p[++size] = t;
        decrease_key(p,size);
    }
    int k = 0;
    print_code(p[1],k);
}

int main()
{
    int n;
    printf("\nEnter the total number of items : ");
    scanf("%d", &n);
    node *p[100];
    printf("\nEnter the data for each node : \n");
    insert(p,n);
    Huffman_coding(p,n);
    return 0;
}