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
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
pii a[51];
unordered_map<int, int> m;

ll solve(int i, vt<int> v) {
    if (i == N) {
        m.clear();
        int sum = 0;
        for (int j = 0; j < v.size(); j++) {
            sum += v[j];
            m[sum]++;
        }
        sum = 0;
        for (int j = v.size()-1; j >= 0; j--) {
            sum += v[j];
            m[sum]++;
        }
        int cnt = 0;
        for (auto& p : m) {
            if (p.second == 2) cnt++;
            if (cnt > 1) return 0;
            if (p.second > 2) return 0;
        }
        return 1;
    }
    ll ans = 0;
    for (int j = a[i].first; j <= a[i].second; j++) {
        v.push_back(j);
        ans += solve(i+1, v);
        v.pop_back();
    }
    if (i == 3) cout << ans << endl;
    return ans;
}

int main () {
    // auto start = chrono::high_resolution_clock::now();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll ans = solve(0, {});
    cout << ans << endl;
    // auto end = chrono::high_resolution_clock::now();
    // cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;
}