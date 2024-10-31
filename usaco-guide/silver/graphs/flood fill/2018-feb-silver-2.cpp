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

struct boot {
    ll s, d;
};

ll N, B;
ll a[250];
vector<boot> b;
bool vis[250][250];

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < B; i++) {
        ll s, d;
        cin >> s >> d;
        b.push_back({s, d});
    }
    ll ans = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; // boot, pos
    pq.push({0, 0});
    while (!pq.empty()) {
        pii c = pq.top();
        pq.pop();
        if (vis[c.first][c.second]) continue;
        vis[c.first][c.second] = true;
        // cout << "boot: " << c.first << " pos: " << c.second << endl;
        if (c.second == N-1) {
            ans = c.first;
            break;
        }
        for (int i = c.second+1; i <= min(N-1, c.second+b[c.first].d); i++) {
            if (a[i] <= b[c.first].s) {
                // cout << "pushing depth " << c.first << " pos " << i << endl;
                pq.push({c.first, i});
            }
        }
        for (int i = c.first+1; i < B; i++) {
            if (a[c.second] <= b[i].s) {
                // cout << "pushing boot " << i << " pos " << c.second << endl;
                pq.push({i, c.second});
            }
        }
    }
    cout << ans << endl;
}