#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        int n;
        cin >> n;
        int toll1[n], toll2[n];
        for(int i=0; i<n; i++) {
            cin >> toll1[i];
        }
        for(int i=0; i<n; i++) {
            cin >> toll2[i];
        }
        int change1[n-1], change2[n-1];
        for(int i=0; i<n-1; i++) {
            cin >> change1[i];
        }
         for(int i=0; i<n-1; i++) {
            cin >> change2[i];
        }

        int dp[2][n];
        memset(dp, INT_MIN, sizeof(dp));

        //initial first toll
        dp[0][0] = toll1[0];
        dp[1][0] = toll2[0];

        for(int j=1; j<n; j++) {
            for(int i=0; i<2; i++) {
                if (i == 0) {
                    dp[i][j] = min(dp[0][j-1]+toll1[j], dp[1][j-1]+change2[j-1]+toll1[j]);
                }
                else {
                    dp[i][j] = min(dp[1][j-1]+toll2[j], dp[0][j-1]+change1[j-1]+toll2[j]);
                }
            }
        }

        cout << "Case #" << t << ": ";
        if(dp[0][n-1] <= dp[1][n-1]) cout << dp[0][n-1] << endl;
        else cout << dp[1][n-1] << endl;


    }


}
