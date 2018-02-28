#include <stdio.h>
#include <stdlib.h>

typedef struct deque{
    int data;
    struct deque * prev;
    struct deque * next;
}deque;

deque * front = NULL;
deque * end = NULL;

void push_front(int val){
    deque * temp = (deque*)malloc(sizeof(deque));
    temp->data = val;
    if (front!=NULL){
        front->prev = temp;
    }
    temp->prev=NULL;
    temp->next=front;
    front = temp;
    if (end == NULL){
        end = front;
    }
    return;
}

void push_end(int val){
    deque * temp = (deque*)malloc(sizeof(deque));
    temp->data = val;
    if (end!=NULL){
        end->next = temp;
    }
    temp->prev=end;
    temp->next=NULL;
    end = temp;
    if (front == NULL){
        front = end;
    }
    return;
}

int pop_front(){
    deque * temp = front;
    if (front==NULL){
        return -1;
    }
    front = front->next;
    if (front == NULL){
        end = NULL;
    }
    else {
        front->prev = NULL;
    }
    int val = temp->data;
    free(temp);
    return val;
}

int pop_end(){
    deque * temp= end;
    if (front==NULL){
        return -1;
    }
    end = end->prev;
    if (end == NULL){
        front = NULL;
    }
    else {
        end->next = NULL;
    }
    int val = temp->data;
    free(temp);
    return val;
}

void print(){
    for (deque * temp = front; temp!=NULL; temp=temp->next){
        printf("%d ", temp->data);
    }
    printf("\n");
    return;
}

int main(){
    int flag;
    int val;
    printf("0)Exit 1)Push_Front 2)Push_End 3)Pop_Front 4)Pop_End 5)Print\n");
    scanf("%d", &flag);
    while(flag!=0){
        if (flag==1){
            printf("Value: ");
            scanf("%d", &val);
            push_front(val);
        }
        else if(flag==2){
            printf("Value: ");
            scanf("%d", &val);
            push_end(val);
        }
        else if(flag==3){
            val = pop_front();
            printf("Popped value: %d\n", val);
        }
        else if (flag==4){
            val = pop_end();
            printf("Popped value: %d\n", val);
        }
        else if (flag==5){
            print();
        }
        printf("0)Exit 1)Push_Front 2)Push_End 3)Pop_Front 4)Pop_End 5)Print\n");
        scanf("%d", &flag);
    }
    return 0;
}