#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void printArray(lli arr[], lli n) {
    for(lli i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(lli arr[], lli n) {
    for(lli i=0; i<n; i++) {
        printArray(arr, n);
        for(lli j=0; j<n-i-1; j++) {
            if(arr[j+1] < arr[j]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
   /* lli arr[10000], n=0;
    while(true) {
        string str;
        cin >> str;

        if(str == "b") {
            bubble_sort(arr, n);
            break;
        }
        else {
            arr[n] = stoi(str);
            n++;
        }

    }*/
    
      int arr[] = {2,7,5,4,1,10,8,11,36,77}, n=10;
  XXX(arr, n);
  printArray(arr, n);
    return 0;
}

