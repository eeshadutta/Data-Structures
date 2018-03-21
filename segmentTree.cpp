#include <bits/stdc++.h>
using namespace std;

int n, arr[100000];
int segTree[400000];

int buildSegTree(int start, int end, int index){
    if (start == end){
        segTree[index] = arr[start];
        return segTree[index];
    }
    int mid = start + (end-start)/2;
    segTree[index] = buildSegTree(start, mid, 2*index + 1) + buildSegTree(mid+1, end, 2*index + 2);
    return segTree[index];
}

int getSum(int left, int right, int start, int end, int index){
    if ((left <= start) && (right >= end)){
        return segTree[index];
    }
    else if ((left > end) || (right < start)){
        return 0;
    }
    else {
        int mid = start + (end-start)/2;
        return (getSum(left, right, start, mid, 2*index + 1) + getSum(left, right, mid+1, end, 2*index + 2));
    }
}

int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int totalSum = buildSegTree(0, n-1, 0);
    int left, right;
    cout << "enter left and right index ";
    cin >> left >> right;
    int sum = getSum(left, right, 0, n-1, 0);
    cout << sum << endl;
    return 0;
}