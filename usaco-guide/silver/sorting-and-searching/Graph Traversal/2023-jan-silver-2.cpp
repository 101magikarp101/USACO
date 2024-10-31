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
#define LLONG_MAX 9223372036854775807
#define MOD 998244353

using namespace std;

int N;
int a[1501][1501];
ll val[1501][1501];
ll ver[1501];
ll hor[1501];

//R -> 1; D -> 0
bool good(int i, int j) {
    return i >= 1 && i <= N && j >= 1 && j <= N;
}
void fill() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (a[i][j] == 1 && good(i, j+1)) {
                val[i][j+1] += val[i][j];
            } else if (a[i][j] == 0 && good(i+1, j)) {
                val[i+1][j] += val[i][j];
            }
        }
    }
}

ll run(int i, int j, ll v) {
    // cout << "run: " << i << " " << j << " " << v << endl;
    if (a[i][j] == 1) {
        if (good(i, j+1)) {
            val[i][j+1] += v;
            return run(i, j+1, v);
        } else {
            return ver[i];
        }
    } else {
        if (good(i+1, j)) {
            val[i+1][j] += v;
            return run(i+1, j, v);
        } else {
            return hor[j];
        }
    }
}

ll rev(int i, int j) {
    ll res = 1;
    if (good(i, j-1) && a[i][j-1] == 1) {
        res += rev(i, j-1);
    }
    if (good(i-1, j) && a[i-1][j] == 0) {
        res += rev(i-1, j);
    }
    return res;
}

int main() {
    // freopen("1.in", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            val[i][j] = 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            if (s[j-1] == 'R') a[i][j] = 1;
            else a[i][j] = 0;
        }
        ll x;
        cin >> x;
        ver[i] = x;
    }
    for (int j = 1; j <= N; j++) {
        ll x;
        cin >> x;
        hor[j] = x;
    }
    // cout << "ver: ";
    // for (int i = 1; i <= N; i++) {
    //     cout << ver[i] << " ";
    // }
    // cout << endl;
    // cout << "hor: ";
    // for (int i = 1; i <= N; i++) {
    //     cout << hor[i] << " ";
    // }
    // cout << endl;
    // cout << "input done" << endl;
    fill();
    // cout << "fill done" << endl;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i][N] == 1) {
            ans += rev(i, N)*ver[i];
        }
        if (a[N][i] == 0) {
            ans += rev(N, i)*hor[i];
        }
    }
    cout << ans << endl;
    ll Q;
    cin >> Q;
    while (Q--) {
        ll r, c;
        cin >> r >> c;
        ll res1 = run(r, c, -1*val[r][c]);
        a[r][c] = 1-a[r][c];
        ll res2 = run(r, c, val[r][c]);
        // cout << "res1: " << res1 << " res2: " << res2 << endl;
        ans += (res2-res1)*val[r][c];
        cout << ans << endl;
    }
}