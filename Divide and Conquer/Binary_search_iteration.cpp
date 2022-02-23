#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void binary_search(lli arr[], lli l, lli r, lli x) {
    lli mid = l+(r-l)/2;

    if(l > r) {
        cout << "No" << endl;
        return;
    }
    cout << l << "," << mid << "," << r << " ";
    if(arr[mid] ==  x) {
        cout << "Yes" << endl;
        return;
    }
    if(arr[mid] > x) {
        return binary_search(arr, l, mid-1, x);
    }
    return binary_search(arr, mid+1, r, x);
}
void printArray(lli arr[], lli n) {
    for(lli i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    lli arr[10000], sortarr[10000], n=0;
    while(true) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        string word, c[1000];

        int m=0;
        while (ss >> word)
        {
            c[m] = word;
            m++;
        }
        if(c[0] == "o") break;
        else if(c[0] == "p") printArray(arr, n);
        else if(c[0] == "s") binary_search(sortarr, 0, n-1, stoi(c[1]));
        else {
            arr[n] = stoi(c[0]);
            sortarr[n] = stoi(c[0]);
            sort(sortarr, sortarr+n);
            n++;
        }

    }

    return 0;
}
