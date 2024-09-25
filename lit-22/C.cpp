#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll N, K;
ll a[200005];

bool check(ll n) {
    ll cnt = 0;
    ll s = 0;
    for (int i = 0; i < N/2; i++) {
        s += a[i];
    }
    for (int i = N/2; i < N; i++) {
        if (a[i] > n) s += a[i]-n;
    }
    for (int i = N/2; i < N; i++) {
        cnt += max(0LL,n-a[i]);
        if (cnt*2 > K) return 0;
        if (cnt > s) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a,a+N);
    ll l = a[N/2], r = 2e18;
    while (l<r) {
        ll m = (l+r+1)/2;
        if (check(m)) l = m;
        else r = m-1;
    }
    cout << l << endl;
    return 0;
}