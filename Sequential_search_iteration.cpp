#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void sequential_search(lli arr[], lli n, lli x) {
    for(lli i=0; i<n; i++) {
        if(arr[i] == x) {
            cout << x << " Yes" << endl;
            return;
        }
        else {
            cout << arr[i] << " ";
        }
    }
    cout << "No" << endl;
}
void printArray(lli arr[], lli n) {
    for(lli i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    lli arr[10000], n=0;
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
        else if(c[0] == "s") sequential_search(arr, n, stoi(c[1]));
        else {
            arr[n] = stoi(c[0]);
            n++;
        }

    }

    return 0;
}
