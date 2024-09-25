#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }
    sort(events.begin(), events.end());
    int max = 0;
    int curr = 0;
    for (int i = 0; i < events.size(); i++) {
        curr += events[i].second;
        if (curr > max) {
            max = curr;
        }
    }
    cout << max << endl;
}
