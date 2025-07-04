#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N;
int a[200005], b[200005];
map<int, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        m[a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += m[b[i]];
    }
    cout << ans << "\n";
    return 0;
}