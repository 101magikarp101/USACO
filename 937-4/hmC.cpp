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
ll ans[200005];

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        ans[i] = a[0];
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j*j <= i; j++) {
            if (i%j==0) {
                ans[j-1] += a[i];
                if (j*j!=i) ans[i/j-1] += a[i];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[gcd(i+1, N)-1] << endl;
    }
    return 0;
}