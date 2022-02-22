#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef struct {
    lli v;
    lli w;
    double ratio;
}Item;
bool sortByRatio(Item i1, Item i2) {
    return i1.ratio > i2.ratio;
}
double fractionalKnapsack(Item item[], lli W, lli n) {
    for(int i=0; i<n; i++) item[i].ratio = double(item[i].v)/double(item[i].w);
    sort(item, item+n, sortByRatio);
    for(int i=0; i<n; i++) cout << item[i].v << "\t" << item[i].w << "\t" << item[i].ratio << endl;
    double total = 0.0;
    for(int i=0; i<n; i++) {
        if(item[i].w <= W) {
            W -= item[i].w;
            total += item[i].v;
        }
        else  {
            total += double(item[i].v*W) / double(item[i].w);
            break;
        }
    }


    return total;
}
int main() {

    lli n, W;
    cin >> n;
    Item item[n];
    for(int i=0; i<n; i++) {
        cin >> item[i].v >> item[i].w;
    }
    cin >> W;
    cout << fractionalKnapsack(item, W, n) << endl;

}
/*
5
66 30
20 10
30 20
60 50
40 40
100
*/
