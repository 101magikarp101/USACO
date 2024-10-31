#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    set<int> lights;
    lights.insert(0);
    lights.insert(x);
    map<int, int, greater<int>> lengths;
    lengths[x] = 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        int leftmost = *prev(lights.upper_bound(t));
        int rightmost = *lights.upper_bound(t);
        lengths[rightmost - leftmost]--;
        if (lengths[rightmost - leftmost] == 0) {
            lengths.erase(rightmost - leftmost);
        }
        lengths[rightmost - t]++;
        lengths[t - leftmost]++;
        // cout << "leftmost: " << leftmost << " rightmost: " << rightmost << endl;
        // cout << "lengths: ";
        // for (auto p : lengths) {
        //     cout << p.first << " " << p.second << " " << endl;
        // }
        // cout << endl;
        lights.insert(t);
        cout << lengths.begin()->first << " ";
    }
}