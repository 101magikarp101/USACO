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

struct cow {
    ll w, x;
    int d;
};

struct meet {
    ll t;
    int d;
};

int N;
ll L;
cow a[50005];

int main() {
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
        cin >> N >> L;
        vt<meet> m;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i].w >> a[i].x >> a[i].d;
            sum += a[i].w;
        }
        sort(a, a+N, [](cow a, cow b) {
            return a.x < b.x;
        });
        for (int i = 0; i < N; i++) {
            if (a[i].d==1) {
                m.push_back({L-a[i].x, 1});
            } else {
                m.push_back({a[i].x, -1});
            }
        }
        sort(m.begin(), m.end(), [](meet a, meet b) {
            return a.t < b.t;
        });
        int l = 0, r = N-1;
        ll t = 0;
        ll tsum = 0;
        for (int i = 0; i < N; i++) {
            if (m[i].d==1) {
                tsum += a[r--].w;
            } else {
                tsum += a[l++].w;
            }
            if (tsum >= (sum+1)/2) {
                t = m[i].t;
                break;
            }
        }
        // cout << t << endl;
        ll ans = 0;
        set<ll> s;
        for (int i = 0; i < N; i++) {
            if (a[i].d==1) {
                s.insert(a[i].x);
            } else {
                while (!s.empty() && *s.begin() < a[i].x-2*t) {
                    s.erase(s.begin());
                }
                ans += s.size();
            }
        }
        cout << ans << endl;
}