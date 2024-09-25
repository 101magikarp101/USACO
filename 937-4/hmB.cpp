#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int ans = N+1;
    bool good = true;
    while (true) {
        for (int i = 2; i*i <= ans; i++) {
            if (ans%i==0) {
                ans++;
                good = false;
                break;
            }
        }
        if (good) {
            cout << ans << endl;
            return 0;
        }
        good = true;
    }
    return 0;
}