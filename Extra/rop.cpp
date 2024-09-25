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
#define MOD 1000000007

using namespace std;

ll N, M;
ll a[100002];
vector<ll> b[100002];
bool vis[100002];

ll binexp(ll a, ll b) {
    if (b == 0) {
        return (ll)1;
    }
    ll res = binexp(a, b/2);
    res = (res*res)%MOD;
    if (b%2 == 1) {
        res = (res*a)%MOD;
    }
    return res;
}

int main() {
    // freopen("rop.txt", "r", stdin);
    memset(vis, false, sizeof(vis));
    cin >> N;
    for (ll i = 0; i<N; i++) {
        cin >> a[i];
    }
    cin >> M;
    for (ll i = 0; i<M; i++) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        b[x].push_back(y);
        b[y].push_back(x);
    }
    for (ll i = 0; i<N; i++) {
        if (!vis[i]) {
            vector<ll> c;
            vector<ll> ind;
            queue<ll> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                ll x = q.front();
                q.pop();
                c.push_back(a[x]);
                ind.push_back(x);
                for (ll j = 0; j<b[x].size(); j++) {
                    if (!vis[b[x][j]]) {
                        vis[b[x][j]] = true;
                        q.push(b[x][j]);
                    }
                }
            }
            sort(c.begin(), c.end());
            sort(ind.begin(), ind.end());
            for (ll j = 0; j<c.size(); j++) {
                a[ind[j]] = c[j];
            }
        }
    }
    // cout << "a: ";
    // for (int i = 0; i<N; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    ll ans = 0;
    for (ll i = 0; i<N; i++) {
        ans = (ans + (a[i]*binexp((N-i), (N-i)))%MOD)%MOD;
    }
    cout << ans << endl;
}