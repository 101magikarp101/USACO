#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

int iswin(int a, int b, int c, int d) {
    int res = 0;
    if (a > b) res++;
    else if (a<b) res--;
    if (c > d) res++;
    else if (c<d) res--;
    return res > 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a>b) swap(a, b);
        if (c>d) swap(c, d);
        int ans = 0;
        ans += iswin(a, c, b, d);
        ans += iswin(a, d, b, c);
        ans += iswin(b, c, a, d);
        ans += iswin(b, d, a, c);
        cout << ans << endl;
    }
    return 0;
}