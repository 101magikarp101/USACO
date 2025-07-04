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

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define MOD2 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

ll N;
map<int, vector<ll>> vx, vy; //values along x, values along y
map<int, vector<ll>> dpx, dpy; //sum of values along x, sum of values along y

int main () {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        vx[y].push_back(x);
        vy[x].push_back(y);
    }
    for (auto i : vx) {
        sort(i.second.begin(), i.second.end());
        ll sum = 0;
        for (int j = 0; j < i.second.size(); j++) {
            sum += i.second[j];
            dpx[i.first].push_back(sum);
        }
    }
    for (auto i : vy) {
        sort(i.second.begin(), i.second.end());
        ll sum = 0;
        for (int j = 0; j < i.second.size(); j++) {
            sum += i.second[j];
            dpy[i.first].push_back(sum);
        }
    }
    ll ans = 0;
    for (auto i : vx) {
        for (int j = 0; j < i.second.size(); j++) {
            ll x = i.second[j];
            ll y = i.first;
            ll rsum = dpx[y][dpx[y].size() - 1] - dpx[y][j];
            ll r = dpx[y].size() - j - 1;
            ll lsum, l;
            if (j == 0) {
                lsum = 0;
                l = 0;
            } else {
                lsum = dpx[y][j - 1];
                l = j;
            }
            ll idx = lower_bound(vy[x].begin(), vy[x].end(), y) - vy[x].begin();
            ll usum = dpy[x][dpy[x].size() - 1] - dpy[x][idx];
            ll u = dpy[x].size() - idx - 1;
            ll dsum, d;
            if (idx == 0) {
                dsum = 0;
                d = 0;
            } else {
                dsum = dpy[x][idx - 1];
                d = idx;
            }
            ll res = ((rsum - r*x)%MOD2 + (l*x-lsum)%MOD2)%MOD2;
            ll res1 = ((usum - u*y)%MOD2 + (d*y-dsum)%MOD2)%MOD2;
            ans = (ans + (res*res1)%MOD2)%MOD2;
            // cout << "x: " << x << " y: " << y << endl;
            // cout << "rsum: " << rsum << " r: " << r << " lsum: " << lsum << " l: " << l << endl;
            // cout << "usum: " << usum << " u: " << u << " dsum: " << dsum << " d: " << d << endl;
            // cout << "res: " << res << " res1: " << res1 << endl;
        }
    }
    cout << ans << endl;
}