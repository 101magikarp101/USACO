#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

struct line {
    ll y, x;
    bool operator<(const line& l) const {
        if (y==l.y) return x<l.x;
        return y<l.y;
    }
};

int T, N, K;
map<line, ll> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        m.clear();
        cin >> N >> K;
        ll a, b; cin >> a >> b;
        ll z = 0;
        for (int i = 0; i < N; i++) {
            ll x, y; cin >> x >> y;
            x-=a;
            y-=b;
            if (x==0) {
                if (y>0) m[{1, 0}]++;
                else if (y<0) m[{-1, 0}]++;
                else z++;
            } else if (y==0) {
                if (x>0) m[{0, 1}]++;
                else if (x<0) m[{0, -1}]++;
            } else {
                ll g = gcd(abs(x), abs(y));
                x/=g;
                y/=g;
                m[{y, x}]++;
            }
        }
        vt<ll> v;
        for (auto i : m) {
            v.push_back(i.second);
        }
        sort(v.begin(), v.end(), greater<ll>());
        ll ans = 0;
        for (int i = 0; i < min((int)v.size(), K); i++) {
            ans += v[i];
        }
        cout << ans+z << '\n';
    }
    return 0;
}