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

void update(int start, int end, int ind, int diff, int seg_ind){
    if ((ind < start) || (ind > end))
        return;
    segTree[seg_ind] += diff;
    if (start != end){
        int mid = start + (end-start)/2;
        update(start, mid, ind, diff, 2*seg_ind + 1);
        update(mid + 1, end, ind, diff, 2*seg_ind + 2);
    }
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int totalSum = buildSegTree(0, n-1, 0);
    int flag;
    cout << "0)Exit 1)getSum 2)update\n";
    cin >> flag;
    while (flag){
        if (flag == 1){
            int left, right;
            cout << "enter left and right index ";
            cin >> left >> right;
            int sum = getSum(left, right, 0, n-1, 0);
            cout << sum << endl;
        }
        else if (flag == 2){
            cout << "enter update index and value ";
            int ind, val;
            cin >> ind >> val;
            int diff = val - arr[ind];
            arr[ind] = val;
            update(0, n-1, ind, diff, 0);
        }
        cout << "0)Exit 1)getSum 2)update\n";
        cin >> flag;
    }
    return 0;
}