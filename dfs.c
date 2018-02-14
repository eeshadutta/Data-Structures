#include <stdio.h>
#include <stdlib.h>
int visited[10000];

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

void dfs (int u, int p){
    printf("%d ", u);
    LIST *temp = g[u];
    while (temp!=NULL){
        if (temp->val != p){
            dfs(temp->val,u);
        }
        temp = temp->link;
    }
    return;
}

int main()
{
    int v, e;
    scanf("%d %d", &v, &e);
    int i;
    int a, b;
    for (i = 1; i <= e; i++)
    {
        scanf("%d %d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    for (i = 1; i <= v; i++)
    {
        printf("Adjacency List of %d: ", i);
        print(g[i]);
    }
    
    dfs(1, -1);
    printf("\n");
    return 0;
}