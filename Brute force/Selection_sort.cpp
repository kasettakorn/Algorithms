#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void printArray(lli arr[], lli n) {
    for(lli i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selection_sort(lli arr[], lli n) {
    for(lli i=0; i<n-1; i++) {
        printArray(arr, n);
        lli min = i;
        for(lli j=i+1; j<n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);

    }
}

int main() {
    lli arr[10000], n=0;
    while(true) {
        string str;
        cin >> str;

        if(str == "s") {
            selection_sort(arr, n);
            break;
        }
        else {
            arr[n] = stoi(str);
            n++;
        }

    }
    return 0;
}

