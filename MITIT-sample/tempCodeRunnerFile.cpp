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

struct node {
    ll res[3000];
    ll pre[3000];
    vt<int> c;
    int l;
};

int N;
node a[3001];
bool vis[3001];
ll ans = 0;

ll add(ll x, ll y) {
    return (x + y) % MOD;
}

ll sub(ll x, ll y) {
    return (x - y + MOD) % MOD;
}

ll mul(ll x, ll y) {
    return (x * y) % MOD;
}

int fill(int n, int l) {
    a[n].l = l;
    vis[n] = true;
    for (int i = 0; i < a[n].c.size(); i++) {
        int c = a[n].c[i];
        if (!vis[c]) {
            l = fill(c, l + 1);
        }
    }
    return l;
}

void solve(int n, int dir) {
    // cout << "n: " << n << " dir: " << dir << endl;
    // cout<< "size: " << a[n].c.size() << endl;
    if (a[n].c.size() == 1 && n != 1) {
        // cout << "n: " << n << endl;
        // cout << "pre: " << a[n].pre[2999] << endl;
        ans = add(ans, a[n].pre[2999]);
    }
    if (dir == 1) {
        for (int i = 0; i < a[n].c.size(); i++) {
            if (a[n].l > a[a[n].c[i]].l) {
                continue;
            }
            int c = a[n].c[i];
            // cout << "n: " << n << " c: " << c << endl;
            for (int j = 1; j < a[c].l; j++) {
                a[c].res[j] = a[n].pre[j - 1];
            }
            for (int j = 0; j < 3000; j++) {
                if (j == 0) {
                    a[c].pre[j] = a[c].res[j];
                } else {
                    a[c].pre[j] = add(a[c].pre[j - 1], a[c].res[j]);
                }
            }
            // cout << "c: " << c << " res: ";
            // for (int j = 0; j < 10; j++) {
            //     cout << a[c].res[j] << " ";
            // }
            // cout << endl;
            solve(c, !dir);
        }
    } else {
        for (int i = 0; i < a[n].c.size(); i++) {
            if (a[n].l > a[a[n].c[i]].l) {
                continue;
            }
            int c = a[n].c[i];
            // cout << "n: " << n << " c: " << c << endl;
            for (int j = 0; j < a[c].l; j++) {
                a[c].res[j] = sub(a[n].pre[2999], j==0?0:a[n].pre[j - 1]);
            }
            for (int j = 0; j < 3000; j++) {
                if (j == 0) {
                    a[c].pre[j] = a[c].res[j];
                } else {
                    a[c].pre[j] = add(a[c].pre[j - 1], a[c].res[j]);
                }
            }
            // cout << "c: " << c << " res: ";
            // for (int j = 0; j < 10; j++) {
            //     cout << a[c].res[j] << " ";
            // }
            // cout << endl;
            solve(c, !dir);
        }
    }
}

int main () {
    cin >> N;
    for (int i = 1; i < N; i++) {
        int x, y;
        cin >> x >> y;
        a[x].c.push_back(y);
        a[y].c.push_back(x);
    }
    a[1].res[0] = 1;
    for (int i = 0; i < 3000; i++) {
        a[1].pre[i] = a[1].res[0];
    }
    fill(1, 1);
    memset(vis, 0, sizeof(vis));
    // cout << "l: " << endl;
    // for (int i = 1; i <= N; i++) {
    //     cout << a[i].l << " ";
    // }
    // cout << endl;
    solve(1, 1);
    ans = mul(ans, 2);
    cout << ans << endl;
}