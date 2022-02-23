#include <iostream>
#include <algorithm>
using namespace std;
typedef struct {
    int start;
    int finish;
}Job;
bool sortByFinish(Job j1, Job j2) {
    return j1.finish < j2.finish;
}
int main() {
    int n;
    cin >> n;
    Job job[n];
    for(int i=0; i<n; i++) {
        cin >> job[i].start >> job[i].finish;
    }
    //sort by finish time
    sort(job, job+n, sortByFinish);

    int count = 1;
    int current_job = job[0].finish;
    for(int i=0; i<n; i++) {
        cout << job[i].start << "\t" << job[i].finish << endl;
    }
    for(int i=1; i<n; i++) {
        if (job[i].start >= current_job) {
            count++;
            current_job = job[i].finish;
        }
    }
    cout << count << endl;
}
