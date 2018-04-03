#include <stdio.h>
#include <stdlib.h>
int visited[100000];
int count[100000] = {};

typedef struct list
{
    int val;
    struct list *link;
} LIST;

LIST *g[100000];

void insert(int a, int b)
{
    LIST *temp = (LIST *)malloc(sizeof(LIST));
    temp->val = b;
    temp->link = g[a];
    g[a] = temp;
    return;
}

void print(LIST *head)
{
    LIST *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->link;
    }
    printf("\n");
    return;
}

int subtrees(int u, int p)
{
    LIST *temp = g[u];
    while (temp != NULL)
    {
        if (temp->val != p)
        {
            count[u] += subtrees(temp->val, u);
        }
        temp = temp->link;
    }
    count[u] += 1;
    return count[u];;
}

int main()
{
    int n;
    scanf ("%d", &n);
    int i; 
    int a, b;
    for (i=1; i<=n-1; i++){
        scanf("%d %d", &a, &b);
        insert(b, a);
        insert(a, b);
    }
    count[1] = subtrees(1, -1);
    int q;
    scanf ("%d ", &q);
    int node;
    for (i=1; i<=q; i++){
        scanf ("%d", &node);
        printf("%d\n", count[node]);
    }
    
    return 0;
}