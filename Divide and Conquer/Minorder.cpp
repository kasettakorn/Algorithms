#include<bits/stdc++.h>
using namespace std;

typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    min_heap heap;

    for(int i=0; i<n; i++) heap.push(arr[i]); /// build heap
    for(int i=0; i<k-1; i++) heap.pop();

    cout << heap.top() << endl;

}
