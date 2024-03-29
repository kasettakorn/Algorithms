#include <iostream>
#include <algorithm>
using namespace std;
typedef struct {
    int w;
    int v;
} Item;
int knapsack(Item item[], int n, int W) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (item[i-1].w > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], item[i-1].v+dp[i-1][j-item[i-1].w]);
            }
        }
        
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
        
    }
    return dp[n][W];
    
    
} 
int main() {
    int n, W;
    cin >> n;
    Item item[n];
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].w >> item[i].v;
    }
    cin >> W;
    cout << knapsack(item, n, W) << endl;

    return 0;
    
}

/*
#include <iostream>
#include <algorithm>
using namespace std;
void knapsack(int weight[], int value[], int W) {
    int n = 4;
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (weight[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], value[i-1]+dp[i-1][j-weight[i-1]]);
            }
        }

    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;

    }

}
int main() {
    int bag = 7;
    int weight[] = {1,3,4,5};
    int value[] = {1,4,5,7};

    knapsack(weight, value, bag);

    return 0;

}
*/
