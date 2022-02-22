#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli distinct_sum(lli arr[], lli n) {
    lli sum=0;
    unordered_set<lli> sets;
    for(lli i=0; i<n; i++) {
        if(sets.find(arr[i]) == sets.end()) { //Not found
            sum += arr[i];
            sets.insert(arr[i]);
        }
    }

    return sum;
}
int main()
{
    lli n;
    cin >> n;
    lli arr[n];
    for(lli i=0; i<n; i++) cin >> arr[i];

    cout << distinct_sum(arr, n) << endl;

    return 0;
}
