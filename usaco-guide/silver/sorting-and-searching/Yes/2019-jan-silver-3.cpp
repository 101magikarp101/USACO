#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> mountains[100005];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mountains[i] = {x, y};
    }
    sort(mountains, mountains + n, [](pair<int, int> a, pair<int, int> b) {
        if (a.first + a.second == b.first + b.second) {
            return a.first < b.first;
        } else {
            return a.first + a.second > b.first + b.second;
        }
    });
    // cout << "mountains: ";
    // for (int i = 0; i < n; i++) {
    //     cout << "(" << mountains[i].first << ", " << mountains[i].second << ") ";
    // }
    // cout << endl;
    int ans = 0;
    int max = INT32_MIN;
    int current = -1;
    for (int i = 0; i < n; i++) {
        if (mountains[i].first + mountains[i].second == current) {
            continue;
        } else {
            current = mountains[i].first + mountains[i].second;
            if (mountains[i].second - mountains[i].first > max) {
                ans++;
                max = mountains[i].second - mountains[i].first;
            }
        }
    }
    cout << ans << endl;
}