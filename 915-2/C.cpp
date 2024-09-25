#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int T, N;
string s;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> s;
        vector<pair<char, int>> dq;
        for (int i = 0; i < N; i++) {
            if (!dq.empty()) {
                if (dq.back().first < s[i]) {
                    while (!dq.empty() && dq.back().first < s[i]) {
                        dq.pop_back();
                    }
                    dq.push_back({s[i], i});
                } else {
                    dq.push_back({s[i], i});
                }
            } else {
                dq.push_back({s[i], i});
            }
        }
        for (int i = 0; i < dq.size(); i++) {
            s[dq[dq.size()-1-i].second] = dq[i].first;
        }
        if (is_sorted(s.begin(), s.end())) {
            int cnt = 0;
            for (int i = 0; i < dq.size(); i++) {
                if (dq[i].first == dq[0].first) {
                    cnt++;
                } else {
                    break;
                }
            }
            cout << dq.size()-cnt << endl;
        } else {
            cout << -1 << endl;
        }
    }
}