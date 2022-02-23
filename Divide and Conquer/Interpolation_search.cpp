#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void interpolation_search(lli arr[], lli l, lli r, lli x) {
    lli pos = l + (((x-arr[l])*(r-l)) / (arr[r]-arr[l]));
    cout << l << "," << pos << "," << r << " ";
    if(l > r || x < arr[l] || x > arr[r]) {
        cout << "No" << endl;
        return;
    }
    if(arr[pos] ==  x) {
        cout << "Yes" << endl;
        return;
    }
    if(arr[pos] > x) {
        return interpolation_search(arr, l, pos-1, x);
    }
    return interpolation_search(arr, pos+1, r, x);
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
        else if(c[0] == "s") interpolation_search(sortarr, 0, n-1, stoi(c[1]));
        else {
            arr[n] = stoi(c[0]);
            sortarr[n] = stoi(c[0]);
            n++;
            sort(sortarr, sortarr+n);
        }

    }

    return 0;
}
