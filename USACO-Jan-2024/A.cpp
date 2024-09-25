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
vt<bool> vf, hf;
ll vd[200005], hd[200005];
vt<ll> vd1, hd1;

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
    for (int i = 0; i < v.size(); i++) {
        if (i == 0 || v[i]%2 != v[i-1]%2) vf.push_back(true);
        else vf.push_back(false);
    }
    for (int i = 0; i < h.size(); i++) {
        if (i == 0 || h[i]%2 != h[i-1]%2) hf.push_back(true);
        else hf.push_back(false);
    }
    for (int i = 0; i < v.size(); i++) {
        int idx = i-1;
        while (idx >= 0 && v[idx]%2 != v[i]%2) {
            vd[idx] = v[i] - v[idx];
            if (vf[idx]) {
                
            }
            idx--;
        }
    }
    for (int i = 0; i < h.size(); i++) {
        int idx = i-1;
        while (idx >= 0 && h[idx]%2 != h[i]%2) {
            hd[idx] = h[i] - h[idx];
            idx--;
        }
    }
    while (Q--) {
        ll x, y, tar;
        cin >> x >> y >> tar;
        ll t = 0;
        int idxx = lower_bound(v.begin(), v.end(), x) - v.begin();
        int idxy = lower_bound(h.begin(), h.end(), y) - h.begin();
        if (binary_search(v.begin(), v.end(), x)) {
            if (h.size() == 0) {
                cout << x << " " << y+tar << endl;
                continue;
            }
            if (idxy == h.size()) {
                cout << x << " " << y+tar << endl;
                continue;
            }
            ll d = h[idxy] - y;
            if (d >= tar) {
                cout << x << " " << y+tar << endl;
                continue;
            } else {
                y+=d;
                t+=d;
            }
        } else {
            if (v.size() == 0) {
                cout << x+tar << " " << y << endl;
                continue;
            }
            if (idxx == v.size()) {
                cout << x+tar << " " << y << endl;
                continue;
            }
            ll d = v[idxx] - x;
            if (d >= tar) {
                cout << x+tar << " " << y << endl;
                continue;
            } else {
                x+=d;
                t+=d;
            }
        }
        cout << "x: " << x << " y: " << y << " t: " << t << endl;
        if (!vf[idxx] || !hf[idxy]) {
            ll d = vd[idxx]+hd[idxy];
            if (t+d <= tar) {
                if (t%2==1) {
                    if (t+vd[idxx] >= tar) {
                        cout << x+tar-t << " " << y << endl;
                    } else {
                        cout << x+vd[idxx] << " " << y+tar-t-vd[idxx] << endl;
                    }
                } else {
                    if (t+hd[idxy] >= tar) {
                        cout << x << " " << y+tar-t << endl;
                    } else {
                        cout << x+tar-t-hd[idxy] << " " << y+hd[idxy] << endl;
                    }
                }
                continue;
            }
        }

    }
}