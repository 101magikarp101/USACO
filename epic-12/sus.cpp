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
    cin >> N;
    int s = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        s += x;
    }
    cout << s << endl;
    return 0;
}