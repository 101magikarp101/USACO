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

int N, Q;
vt<ll> v, h;

pll solve(ll x, ll y, int idxx, int idxy, ll t, ll tar) {
    if (t%2==1) {
        if (idxx == v.size()-1) {
            return pll(x+tar-t, y);
        }
        ll d = v[idxx+1] - v[idxx];
        if (d >= tar-t) {
            return pll(x+tar-t, y);
        } else {
            return solve(x+d, y, idxx+1, idxy, t+d, tar);
        }
    } else {
        if (idxy == h.size()-1) {
            return pll(x, y+tar-t);
        }
        ll d = h[idxy+1] - h[idxy];
        if (d >= tar-t) {
            return pll(x, y+tar-t);
        } else {
            return solve(x, y+d, idxx, idxy+1, t+d, tar);
        }
    }
}

int main () {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        char c;
        ll x;
        cin >> c >> x;
        if (c == 'V') {
            v.push_back(x);
        } else {
            h.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    while (Q--) {
        ll x, y, tar;
        cin >> x >> y >> tar;
        ll t = 0;
        int idxx = lower_bound(v.begin(), v.end(), x) - v.begin();
        int idxy = lower_bound(h.begin(), h.end(), y) - h.begin();
        if (binary_search(v.begin(), v.end(), x)) {
            ll d = h[idxy] - y;
            if (h.size() == 0 || idxy == h.size() || d >= tar) {
                cout << x << " " << y+tar << endl;
                continue;
            } else {
                y+=d;
                t+=d;
            }
        } else {
            ll d = v[idxx] - x;
            if (v.size() == 0 || idxx == v.size() || d >= tar) {
                cout << x+tar << " " << y << endl;
                continue;
            } else {
                x+=d;
                t+=d;
            }
        }
        pll ans = solve(x, y, idxx, idxy, t, tar);
        cout << ans.first << " " << ans.second << endl;
    }
}