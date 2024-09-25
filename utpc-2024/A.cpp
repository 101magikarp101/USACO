#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, M;
string a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    getline(cin, a[0]);
    for (int i = 0; i < N; i++) {
        getline(cin, a[i]);
    }
    ll pos = -1;
    for (int i = 0; i < M; i++) {
        ll x; cin >> x;
        pos += x+1;
        cout << a[pos%N] << endl;
    }
    return 0;
}