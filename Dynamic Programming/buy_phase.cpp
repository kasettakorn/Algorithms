#include <bits/stdc++.h>
using namespace std;
typedef struct {
    string name;
    int w;
    int h;
}Item;

int main() {
    int n, W;
    cin >> n;
    Item item[n];
    for(int i=0; i<n; i++) {
        cin >> item[i].name >> item[i].w >> item[i].h;
    }
    cin >> W;
    W = (W * 3) / 4;
    int dp[n+1][W+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=W; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(item[i-1].w > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-item[i-1].w]+item[i-1].h);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;

    }



}
