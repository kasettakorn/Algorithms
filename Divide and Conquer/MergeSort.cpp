#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r) {
    int left_size = m-l+1;
    int right_size = r-m;
    int left_array[left_size];
    int right_array[right_size];

    for(int i=0; i<left_size; i++) left_array[i] = arr[l+i];
    for(int i=0; i<right_size; i++) right_array[i] = arr[m+1+i];

    int i=0, j=0, k=l;
    while(i < left_size && j < right_size) {
        if (left_array[i] <= right_array[j]) {
            arr[k] = left_array[i];
            i++;
        }
        else {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }
    while(i < left_size) {
        arr[k] = left_array[i];
        i++;
        k++;
    }
    while(j < right_size) {
        arr[k] = right_array[j];
        j++;
        k++;
    }


}
void mergesort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l)/2;
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    merge(arr, l, mid, r);

}
int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr)/sizeof(int);
    mergesort(arr, 0, n-1);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
