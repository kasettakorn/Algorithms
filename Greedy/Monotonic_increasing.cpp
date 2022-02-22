#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string monotonic(string str) {
    int dp[str.length()];
    dp[0] = 1;

    for (int i = 1; i < str.length(); i++)
    {
        if (str[i]-'0' >= str[i-1]-'0') {
            dp[i] = dp[i-1] + 1;
        }
        else {
            dp[i] = 1;
        }
    }
    int maxIndex, maximumSubsequence = *max_element(dp, dp+str.length());
    for (int i = 0; i < sizeof(dp)/sizeof(int); i++)
    {
        if (dp[i] == maximumSubsequence) {
            maxIndex = i;
            break;
        }
    }

    return str.substr(maxIndex-maximumSubsequence+1, maxIndex+1);
}
int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    cout << monotonic(str) << endl;

    return 0;
}
