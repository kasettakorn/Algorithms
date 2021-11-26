#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main()
{
    ull n;
    cin >> n;
    ull dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(ull i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << "Fibo(" << n << ") = " << dp[n] << endl;


}

