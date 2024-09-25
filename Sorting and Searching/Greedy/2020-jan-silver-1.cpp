#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    int b[1000];
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    int ans = -1;
    for (int i = 1; i <= 1000; i++) {
        int current = 0;
        bool flag = false;
        multiset<int, greater<int>> s(b, b + N);
        for (int j = 1; j <= K/2; j++) {
            auto it = s.begin();
            int val = *it;
            //cout << val << endl;
            if (it == s.end() || val < i) {
                flag = true;
                break;
            } else {
                s.erase(it);
                if (val - i > 0) {
                    s.insert(val - i);
                }
            }
        }
        if (flag) {
            //cout << "flag" << endl;
            continue;
        }
        for (int j = 1; j <= K/2; j++) {
            auto it = s.begin();
            int val = *it;
            if (it == s.end()) {
                break;
            } else {
                current += min(i, val);
                s.erase(it);
                if (val - i > 0) {
                    s.insert(val - i);
                }
            }
        }
        // cout << "s: ";
        // for (auto it = s.begin(); it != s.end(); it++) {
        //     cout << *it << " ";
        // }
        // cout << endl;
        // cout << "i: " << i << " current: " << current << endl;
        if (current > ans) {
            ans = current;
        }
    }
    cout << ans << endl;
}