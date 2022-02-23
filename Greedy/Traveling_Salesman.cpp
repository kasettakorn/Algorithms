#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void travelling_salesman(lli dist[][500], lli n) {
    bool visited[n];
    memset(visited, false, sizeof(visited));
    lli sum = 0;

    //start vertex 1
    cout << "Path = 1";
    lli key = dist[0][0], min;
    for(lli i=0; i<n; i++) {
        if(dist[0][i] < key) {
            key = dist[0][i];
            min = i;
        }
    }

    visited[0] = true;
    visited[min] = true;
    sum += dist[0][min];


    for(lli i=1; i<n; i++) {
        lli temp=0;
        lli minv = 99999;
        for(lli j=0; j<n; j++) {
            if(dist[min][j] == 9999 || visited[j]) continue;
            if(dist[min][j] < minv) {
                minv = dist[min][j];
                temp = j;
            }
        }
        sum += dist[min][temp];
        cout << " -> " << min+1;
        min = temp;
        visited[min] = true;
    }
    cout << "\nMaximum distance = " << sum << endl;

}
int main()
{
    lli n;
    cin >> n;
    lli dist[500][500];
    memset(dist, 0, sizeof(dist));
    for(int i=0; i<n; i++) {
        lli temp[n];
        for(int j=0; j<n; j++) {
            cin >> temp[i];
            dist[i][j] = temp[i];
        }
    }
    travelling_salesman(dist, n);

    return 0;
}
