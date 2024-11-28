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

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int N;
vector<ll> adj[200005];
ll tot[200005];
ll num[200005];
bool vis[200005];
ll ans[200005];

ll fill_num (ll node) {
    if (vis[node]) return 0;
    vis[node] = true;
    ll res = 1;
    for (ll i : adj[node]) {
        if (!vis[i]) {
            res += fill_num(i);
        }
    }
    num[node] = res;
    return res;
}

ll fill_tot (ll node) {
    if (vis[node]) return 0;
    vis[node] = true;
    ll res = 0;
    for (ll i : adj[node]) {
        if (!vis[i]) {
            res += fill_tot(i);
            res += num[i];
        }
    }
    tot[node] = res;
    return res;
}

void solve (ll n, ll in, ll cnt) {
    if (vis[n]) return;
    vis[n] = true;
    vector<int> v = {};
    ll total = cnt+1;
    for (ll i : adj[n]) {
        if (!vis[i]) {
            total += num[i];
            v.push_back(i);
        }
    }
    ans[n] = tot[n] + in;
    if (v.size() == 0) {
        return;
    } else {
        for (ll i = 0; i < v.size(); i++) {
            ll in1 = in + tot[n] - (tot[v[i]] + num[v[i]]) + total-num[v[i]];
            ll cnt1 = total - num[v[i]];
            solve(v[i], in1, cnt1);
        }
    }
}

int main() {
    cin >> N;
    if (N==1) {
        cout << 0 << endl;
        return 0;
    }
    for (ll i = 1; i <= N-1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill_num(1);
    memset(vis, false, sizeof(vis));
    fill_tot(1);
    memset(vis, false, sizeof(vis));
    solve(1, 0, 0);
    for (ll i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
}