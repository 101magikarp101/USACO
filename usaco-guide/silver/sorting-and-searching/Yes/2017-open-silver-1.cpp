#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> cows[100005];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cows[i] = {x, y};
    }
    sort(cows, cows + n, [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    int l = 0;
    int r = n - 1;
    int max = INT32_MIN;
    while (l < r) {
        int pairs = min(cows[l].first, cows[r].first);
        if (cows[l].second + cows[r].second > max) {
            max = cows[l].second + cows[r].second;
        }
        cows[l].first -= pairs;
        cows[r].first -= pairs;
        if (cows[l].first == 0) {
            l++;
        }
        if (cows[r].first == 0) {
            r--;
        }
    }
    cout << max << endl;
}