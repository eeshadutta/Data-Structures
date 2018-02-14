#include <stdio.h>

int n;
int arr[100000];

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}

void heapify(int i){
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left <= n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest]){
        largest = right;
    }
    swap(&arr[i], &arr[largest]);
    if (largest != i){
        heapify(largest);
    }
    return;
}

void buildHeap(){
    int i;
    for (i = n; i >= 1; i--){
        heapify(i);
    }
    return;
}

void insert(int val){
    int ind = n + 1;
    arr[ind] = val;
    n++;
    while (ind != 1){
        if (arr[ind] > arr[ind / 2]){
            swap(&arr[ind], &arr[ind / 2]);
        }
        ind /= 2;
    }
    return;
}

void pop(){
    swap(&arr[1], &arr[n]);
    n--;
    heapify(1);
    return;
}

void heapSort(){
    int temp = n;
    while (n != 0){
        printf("%d ", arr[1]);
        swap(&arr[1], &arr[n]);
        n--;
        heapify(1);
    }
    printf("\n");
    n = temp;
    return;
}

void delete(int val){
    int i;
    for (i = 1; i <= n; i++){
        if (arr[i] == val){
            break;
        }
    }
    swap(&arr[i], &arr[n]);
    n--;
    buildHeap();
    return;
}

void print(){
    int i;
    for (i = 1; i <= n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

int main(){
    printf("How many elements? ");
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    buildHeap();
    print();
    int flag;
    printf("0)Exit 1)Insert 2)Pop 3)Sort 4)Delete\n");
    scanf("%d", &flag);
    while (flag != 0){
        if (flag == 1){
            int val;
            scanf("%d", &val);
            insert(val);
            print();
        }
        else if (flag == 2){
            pop();
            print();
        }
        else if (flag == 3){
            heapSort();
            buildHeap();
        }
        else if (flag == 4){
            int val;
            printf("Element to be deleted: ");
            scanf ("%d", &val);
            delete(val);
            print();
        }
        printf("0)Exit 1)Insert 2)Pop 3)Sort 4)Delete\n");
        scanf("%d", &flag);
    }
    return 0;
}