#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
string isSort(lli arr[], lli n) {
    if (n == 1) return "Yes";
    for(lli i=1; i<n; i++) {
        if (arr[i] < arr[i-1]) return "No";
    }
    return "Yes";
}
int main()
{
    lli n;
    cin >> n;
    lli arr[n];
    for(lli i=0; i<n; i++) cin >> arr[i];

    cout << isSort(arr, n) << endl;

    return 0;
}
