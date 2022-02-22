#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    lli n;
    cin >> n;
    lli arr[n];
    for(lli i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    lli count=0;
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    for(lli i=1; i<=n; i++) {
        if(arr[i]-arr[i-1] != 1) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
