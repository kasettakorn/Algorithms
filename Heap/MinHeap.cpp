#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli size=0;
void printMinHeap(lli arr[]) {
    for(lli i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void enqueue(lli arr[], lli data) {
    size++;
    if (size == 0) {
        arr[0] = data;
        return;
    }
    arr[size-1] = data;
    lli k = size-1;
    while(k > 0) {
        if(arr[(k-1)/2] > arr[k]) {
            swap(arr[(k-1)/2], arr[k]);
            k -= (k-1)/2;
        }
        else return;

    }

}
void dequeue(lli arr[]) {
    if (size == 0) return;
    
    arr[0] = arr[size-1];
    arr[size-1] = -1;
    size--;
    lli k = 0;
    while (2*k+1 < size && 2*k+2 < size) {
        if(arr[2*k+1] < arr[2*k+2] && arr[2*k+1] < arr[k]) {
            swap(arr[2*k+1], arr[k]);
            k = 2*k+1;
        }
        else if(arr[2*k+2] < arr[k]) {
            swap(arr[2*k+2], arr[k]);
            k = 2*k+2;
        }
        else return;

    }
}

int main()
{
    lli arr[] = {10,1,7,3,4,6,8};
    lli n = sizeof(arr)/sizeof(lli);
    lli heap[n];

    for(lli i=0; i<n; i++) {
        enqueue(heap, arr[i]);
    }
    dequeue(heap);
    dequeue(heap);

    printMinHeap(heap);
    return 0;
}
