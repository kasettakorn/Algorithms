#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int matrix_chain(int arr[], int n) {
    int dp[n][n];
    memset(dp, -1, sizeof(dp));
    //diagonal zero
    for(int i=0; i<n; i++) {
        dp[i][i] = 0;
    }
/*
    //calculate 2 matrices
    for(int i=0; i<n-1; i++) {
        dp[i][i+1] = arr[i] * arr[i+1] * arr[i+2];
    }

    //calculate 3 matrices
    /*
        #1 (A1 x A2) x A3 p0p2p3
        #2  A1 x (A2 x A3) p0p1p3
        
    /*
    for(int i=0; i<n-2; i++) {
        dp[i][i+2] = min(dp[i][i+1] + dp[i+2][i+2] + (arr[i]*arr[i+2]*arr[i+3]),
                         dp[i][i] + dp[i+1][i+2] + (arr[i]*arr[i+1]*arr[i+3]));
    }

    //calculate 4 matrices
    for(int i=0; i<n-3; i++) {
        dp[i][i+3] = min(dp[i][i+2] + dp[i+3][i+3] + (arr[i]*arr[i+3]*arr[i+4]),
                     min(dp[i][i+1] + dp[i+2][i+3] + (arr[i]*arr[i+2]*arr[i+4]),
                         dp[i][i] + dp[i+1][i+3] + (arr[i]*arr[i+1]*arr[i+4])));
    }
    
    //calculate 5 matrices
    for(int i=0; i<n-4; i++) {
        dp[i][i+4] = min(dp[i][i+3] + dp[i+4][i+4] + (arr[i]*arr[i+4]*arr[i+5]),
                     min(dp[i][i+2] + dp[i+3][i+4] + (arr[i]*arr[i+3]*arr[i+5]),
                     min(dp[i][i+1] + dp[i+2][i+4] + (arr[i]*arr[i+2]*arr[i+5]),
                         dp[i][i] + dp[i+1][i+4] + (arr[i]*arr[i+1]*arr[i+5]))));
    }

*/
    //calculate N matrices
    for(int k=1; k<n; k++) {
        for(int i=0; i<n-k; i++) {
            int MIN = 99999;
            for(int j=k; j>0; j--) {
                if(dp[i][i+(j-1)] + dp[i+j][i+k] + (arr[i]*arr[i+j]*arr[i+(k+1)]) < MIN) {
                    MIN = dp[i][i+(j-1)] + dp[i+j][i+k] + (arr[i]*arr[i+j]*arr[i+(k+1)]);
                }
            }
            dp[i][i+k] = MIN;
        }

    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[0][n-1];
}

int main() {
    int arr[] = {4,10,3,12,20,7};
    int n = sizeof(arr) / sizeof(int);
    cout << matrix_chain(arr, n-1) << endl;

    return 0;
}
