#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void printArray(lli arr[], lli n) {
    for(lli i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion_sort(lli arr[], lli n) {
    for (lli i=1; i<n; i++) {
        printArray(arr, n);
        lli temp = arr[i];
        lli j=i-1;

        while(j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    printArray(arr, n);
}


int main() {
    lli arr[10000], n=0;
    while(true) {
        string str;
        cin >> str;

        if(str == "i") {
            insertion_sort(arr, n);
            break;
        }
        else {
            arr[n] = stoi(str);
            n++;
        }

    }

    return 0;
}

