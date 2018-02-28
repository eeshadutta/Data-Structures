#include <stdio.h>
#include <stdlib.h>
long long q, p;

typedef struct node{
    int val;
    struct node * left;
    struct node * right;
    int height;
    int freq;
}avl;

avl * root = NULL;

long long MAX(long long a, long long b){
    if (a>b){
        return a;
    }
    else {
        return b;
    }
}

int height(avl *node){
    if (node == NULL){
        return -1;
    }
    else{
        return node->height;
    }
}

void updateHeight(avl * node){
    if (node==NULL){
        return;
    }
    else {
        node->height = 1+MAX(height(node->left), height(node->right));
    }
}

avl* rightRotate(avl * ptr){
    avl * z= ptr;
    avl * y = ptr->left;
    avl * t = y->right;
    y->right =z;
    z->left=t;
    updateHeight(z);
    updateHeight(y);
    return y;
}

avl * leftRotate(avl * ptr){
    avl * z= ptr;
    avl * y = ptr->right;
    avl * t = y->left;
    y->left =z;
    z->right=t;
    updateHeight(z);
    updateHeight(y);
    return y;
}

avl* insert(avl * ptr, int val){
    if (ptr==NULL){
        avl* temp=(avl*)malloc(sizeof(avl));
        temp->val=val;
        temp->left=NULL;
        temp->right=NULL;
        temp->height=0;
        temp->freq=1;
        return temp;
    }
    if (ptr->val==val){
        ptr->freq++;
        return ptr;
    }
    if (val<ptr->val){
        ptr->left=insert(ptr->left, val);
    }
    else{
        ptr->right=insert(ptr->right, val);
    }
    updateHeight(ptr);
    int hd=height(ptr->left)-height(ptr->right);
    if (hd>1 && val<ptr->left->val){
        //ll case
        return rightRotate(ptr);
    }
    else if(hd>1 && val>ptr->left->val){
        //lr case
        avl* newroot=leftRotate(ptr->left);
        ptr->left=newroot;
        return rightRotate(ptr);
    }
    else if (hd<-1 && val>ptr->right->val){
        //rr case
        return leftRotate(ptr);
    }
    else if(hd<-1 && val<ptr->right->val){
        //rl case
        avl * newroot=rightRotate(ptr->right);
        ptr->right=newroot;
        return leftRotate(ptr);
    }
    return ptr;
}


avl * balance(avl * ptr)
{
    if(ptr->left==NULL || ptr->right==NULL)return ptr;
    int hd=height(ptr->left)-height(ptr->right);
    if(hd>1)
    {
        int h2d=height(ptr->left->left) - height(ptr->left->right);
        if(height(ptr->left->left) >= height(ptr->left->right))
        {
            //left left
            return rightRotate(ptr);
        }
        else if(height(ptr->left->left) < height(ptr->left->right))
        {
            //left right
            avl* newroot=leftRotate(ptr->left);
            ptr->left=newroot;
            return rightRotate(ptr);
        }
    }
    else if(hd<-1)
    {
        if(height(ptr->right->left) > height(ptr->right->right))
        {
            //right left
            avl * newroot=rightRotate(ptr->right);
            ptr->right=newroot;
            return leftRotate(ptr);
        }
        else if(height(ptr->right->left) <= height(ptr->right->right))
        {
            //right right
            return leftRotate(ptr);
        }
    }
    return ptr;
}

avl* del(avl * ptr, int val){
    if (ptr==NULL){
        return ptr;
    }
    if (val<ptr->val){
        ptr->left=del(ptr->left,val);
        updateHeight(ptr);
        return balance(ptr);
    }
    if (val>ptr->val){
        ptr->right=del(ptr->right, val);
        updateHeight(ptr);
        return balance(ptr);
    }
    if (val==ptr->val){
        if (ptr->freq>1){
            ptr->freq--;
            updateHeight(ptr);
            return balance(ptr);
        }
        else
        {
            if(ptr->right != NULL &&
            ptr->left != NULL){
                avl* temp = ptr->right ;
                while(temp->left != NULL) temp = temp->left ;
                ptr->val = temp->val ;
                temp->freq=1;
                ptr->right = del(ptr->right,temp->val) ;
                updateHeight(ptr);
                return balance(ptr);
            }
            if (ptr->right != NULL){
                avl * temp= ptr->right;
                return temp;
            }
            else{
                avl*temp =ptr->left;
                return temp;
            }
        }
    }
    if(ptr->val < val) ptr->right = del(ptr->right,val) ;
    else ptr->left = del(ptr->left,val) ;
    updateHeight(ptr);
    return balance(ptr);
}

void preorder(avl * root){
    if (root != NULL){
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

int main(){
    int flag;
    printf("0)Exit 1)Insert 2)Delete\n");
    scanf ("%d", &flag);
    while(flag){
        if (flag==1){
            int val;
            printf("Element to insert: ");
            scanf("%d", &val);
            root=insert(root, val);
            preorder(root);
            printf("\n");
        }
        else if (flag==2){
            int val;
            printf("Element to delete: ");
            scanf("%d", &val);
            root=del(root, val);
            preorder(root);
            printf("\n");
        }
        printf("0)Exit 1)Insert 2)Delete\n");
        scanf("%d", &flag);
    }
    return 0;
}

