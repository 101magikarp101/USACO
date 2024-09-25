#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;

pll dx[4] = {{1,1},{1,-1},{-1,1},{-1,-1}};

pll op(pll x, int i) {
    return {x.y+dx[i].x-dx[i].y, -x.x+dx[i].x+dx[i].y};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vt<pll> v;
    vt<pll> v2;
    v.push_back({0,0});
    for (int i = 1; i <= 10; i++) {
        v2.clear();
        for (auto x: v) {
            for (int j = 0; j < 4; j++) {
                v2.push_back(op(x,j));
            }
        }
        v = v2;
    }
    cout << v.size() << '\n';
    int cnt = 0;
    for (auto x: v) {
        if (x.x==0||x.y==0) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}