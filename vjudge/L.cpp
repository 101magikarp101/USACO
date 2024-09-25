#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, M;
int d[40005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 40005; i++) {
        d[i] = 0;
    }
    cin >> N >> M;
    queue<pii> q;
    q.push({N, 0});
    d[N] = 1;
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        if (p.x == M) {
            cout << p.y << endl;
            return 0;
        }
        if (p.x > 1 && !d[p.x-1]) {
            d[p.x-1] = 1;
            q.push({p.x-1, p.y+1});
        }
        if (p.x*2 <= 40000 && !d[p.x*2]) {
            d[p.x*2] = 1;
            q.push({p.x*2, p.y+1});
        }
        // cout << p.x << " " << p.y << endl;
    }
    return 0;
}