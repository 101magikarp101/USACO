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

int N, K;
map<int, int> m;
int a[500005];
bool vis[500005];

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        m[a] = i;
        vis[a] = true;
    }
    int ans = 0;
    map<int, int> m1;
    for (int i = 0; i < K; i++) {
        cin >> a[i];
        vis[a[i]] = true;
        if (m.find(a[i]) != m.end()) {
            int idx = m[a[i]];
            if (idx >= i) {
                m1[idx-i]++;
            } else {
                m1[K-i+idx]++;
            }
        }
    }
    for (auto it = m1.begin(); it != m1.end(); it++) {
        ans = max(ans, it->second);
    }
    reverse(a, a+K);
    m1.clear();
    for (int i = 0; i < K; i++) {
        if (m.find(a[i]) != m.end()) {
            int idx = m[a[i]];
            if (idx >= i) {
                m1[idx-i]++;
            } else {
                m1[K-i+idx]++;
            }
        }
    }
    for (auto it = m1.begin(); it != m1.end(); it++) {
        ans = max(ans, it->second);
    }
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}