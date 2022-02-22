#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli c=0;
lli partition(lli arr[], lli start, lli end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    c++;
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);

        }
    }

    return pivotIndex;
}
void quicksort(lli arr[], lli l, lli r) {
    if(l < r) {
        lli recur_index = partition(arr, l, r);

        quicksort(arr, l, recur_index-1);
        quicksort(arr, recur_index+1, r);

    }

}
int main()
{
    lli n;
    cin >> n;
    lli arr[n];
    for(lli i=0; i<n; i++) cin >> arr[i];

    quicksort(arr, 0, n-1);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << c << endl;
    return 0;
}
