#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
void LCS(char x[], char y[]) {
     int dp[strlen(x)+1][strlen(y)+1];

     for(int i=0; i<=strlen(x); i++) {
        for(int j=0; j<=strlen(y); j++) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if (x[i] == y[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
     }

    for(int i=0; i<=strlen(x); i++) {
        for(int j=0; j<=strlen(y); j++) {
                cout << dp[i][j] << " ";
        }
        cout << endl;
     }
}
int main() {
    char x[] = "acbcf";
    char y[] = "abcdaf";
    LCS(x, y);
}
