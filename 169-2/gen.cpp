#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << 1 << endl;
    int n = 200000;
    cout << n << " " << 1000000000 << endl;
    vt<ll> v;
    v.push_back(1000000000);
    v.push_back(999999999);
    for (ll i = 2; i < n; i++) {
        v.push_back((778890+i)*1000+888888);
        v.push_back((778889+i)*1000+888889);
    }

    shuffle(v.begin(), v.end(), default_random_engine(52345));
    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i<n-1) cout << " ";
    }
    cout << endl;
    return 0;
}