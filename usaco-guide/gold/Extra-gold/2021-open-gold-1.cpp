#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int N;
int a[200005];
int hm[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll cur = 1;
    ll ans = 0;
    hm[a[0]]++;
    for (int i = 1; i < N; i++) {
        ans += cur;
        if (hm[a[i]]!=0) ans--;
        if (hm[a[i]]==0) cur++;
        hm[a[i]]++;
    }
    cout << ans << '\n';
    return 0;
}