#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

ll N, M;
ll a[10005][65];
pll b[10005];

ll getall(ll x) {
    ll tot = 0;
    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < b[i].y; j++) {
            tot += (j+x)/b[i].y*a[i][j];
        }
    }
    return tot;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    ll tot = 0;
    for (int i = 0; i < M; i++) {
        cin >> b[i].x;
        tot += b[i].x;
    }
    for (int i = 0; i < M; i++) {
        cin >> b[i].y;
    }
    ll cnt = 0;
    ll ans = 0;
    ll cur = 0;
    vt<ll> v(M,0);
    for (ll i = 1; i <= N; i++) {
        ll res = cnt;
        res += N-i+1;
        res += getall(N-i+1);
        ans = max(ans, res);
        cnt++;
        for (int j = 0; j < M; j++) {
            for (int k = b[j].y-1; k >= 0; k--) {
                a[j][k+1] = a[j][k];
            }
            a[j][0] = a[j][b[j].y];
            cnt += a[j][0];
            a[j][b[j].y] = 0;
        }
        ll sum = 0;
        for (int j = 0; j < M; j++) {
            v[j] = (N-i)/b[j].y-b[j].x;
            sum += v[j];
        }
        if (sum > 0) {
            ll each = sum/M;
            sum -= each*M;
            for (int j = 0; j < M; j++) {
                a[j][0] += each;
            }
        }
        ll cursum = 0;
        int r = -1;
        for (int j = 0; j < M; j++) {
            int idx = (j+cur)%M;
            cursum += v[idx];
            if (cursum >= 0) {
                a[idx][0]++;
                cursum--;
                r = idx;
            }
        }
    }
    cout << ans << endl;
    return 0;
}