#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    lli n;
    lli max=1;
    cin >> n;
    string str;
    cin >> str;
    string longest = "", temp="";
    for(lli i=1; i<=str.size(); i++) {
        if(i == 1) temp += str[0];
        if(str[i]-'0' == str[i-1]-'0') {
            temp += str[i];
        }
        else {
            if(temp.size() > max) {
                max = temp.size();
                longest = temp;
            }
            temp = str[i];
        }

    }
    cout << longest << endl;

    return 0;
}
