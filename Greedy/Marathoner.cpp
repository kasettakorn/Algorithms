#include<bits/stdc++.h>
using namespace std;
typedef struct {
    string number;
    int hour;
    int minute;
}Player;
bool comparator(Player p1, Player p2) {
    if (p1.hour != p2.hour) return p1.hour < p2.hour;

    return p1.minute < p2.minute;

}

int main() {
    int k;
    cin >> k;
    string number[k];
    for(int i=0; i<k; i++) cin >> number[i];
    int n;
    cin >> n;
    Player player[n];
    for (int i=0; i<n; i++) cin >> player[i].number >> player[i].hour >> player[i].minute;

    sort(number, number+k);
    sort(player, player+n, comparator);
    int j=0, count=0;

   // for(int i=0; i<n; i++) cout << player[i].number << " " << player[i].hour << " " << player[i].minute << endl;

    for(int i=0; i<n; i++) {
        for(j=0; j<k; j++) {
            if(player[i].number == number[j]) break;
        }
        if (j == k) continue;
        if (player[i].hour >= 0) {
            if (player[i].hour < 6 || (player[i].hour == 6 && player[i].minute == 0)) {
                if (count == 0) cout << player[i].number << " ";
                count++;
            }
        }
    }
    cout << count << endl;
}
