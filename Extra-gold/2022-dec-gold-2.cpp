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
struct pii {int x, y;};
struct pll {int x, y;};

struct frac {
    ll n, d;
};

struct mount {
    int i;
    frac s;
    bool operator<(const mount& m) const {
        return i < m.i;
    }
};

int N, Q;
ll a[2005];
vt<set<mount>> adj;
ll BIG = 2000000000;

bool comp(frac a, frac b) {
    return a.n*b.d >= a.d*b.n;
}

bool comp1(frac a, frac b) {
    return a.n*b.d > a.d*b.n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    adj.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        frac slope = {-BIG, 1};
        for (int j = i+1; j < N; j++) {
            frac s = {a[j]-a[i], j-i};
            if (comp(s, slope)) {
                adj[i].insert({j, s});
                slope = s;
                ans++;
            }
        }
    }
    cin >> Q;
    while (Q--) {
        int n;
        ll x;
        cin >> n >> x;
        n--;
        a[n]+=x;
        for (int i = 0; i < n; i++) {
            frac s = {a[n]-a[i], n-i};
            auto it = adj[i].lower_bound({n, s});
            if (it == adj[i].end()) {
                if (adj[i].size() == 0) {
                    adj[i].insert({n, s});
                    ans++;
                } else if (comp(s, (--it)->s)) {
                    adj[i].insert({n, s});
                    ans++;
                }
                continue;
            }
            auto start = it;
            while (it != adj[i].end() && comp1(s, it->s)) {
                ans--;
                it++;
            }
            adj[i].erase(start, it);
            it = adj[i].lower_bound({n, s});
            if (it == adj[i].end()) {
                if (adj[i].size() == 0) {
                    adj[i].insert({n, s});
                    ans++;
                } else if (comp(s, (--it)->s)) {
                    adj[i].insert({n, s});
                    ans++;
                }
            } else if (comp(it->s, s)) {
                if (it == adj[i].begin()) {
                    adj[i].insert({n, s});
                    ans++;
                } else if (comp(s, (--it)->s)) {
                    adj[i].insert({n, s});
                    ans++;
                }
            }
        }
        ans-=adj[n].size();
        adj[n].clear();
        frac slope = {-BIG, 1};
        for (int i = n+1; i < N; i++) {
            frac s = {a[i]-a[n], i-n};
            if (comp(s, slope)) {
                adj[n].insert({i, s});
                slope = s;
            }
        }
        ans+=adj[n].size();
        cout << ans << endl;
    }
    return 0;
}