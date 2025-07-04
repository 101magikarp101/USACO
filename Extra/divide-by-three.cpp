#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
string s;
int a[100005];

int sub(int j, int k) {
    return ((j-k)%3+3)%3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    N = s.length();
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        a[i] = s[i]-'0';
        sum += a[i];
    }
    sum%=3;
    if (sum == 0) {
        cout << s << endl;
    } else if (sum == 1) {
        vt<bool> use(N, 1);
        bool good = 0;
        for (int i = 1; i < N; i++) {
            if (a[i]%3 == 1) {
                use[i] = 0;
                good = 1;
                break;
            }
        }
        if (good) {
            for (int i = 0; i < N; i++) {
                if (use[i]) {
                    cout << a[i];
                }
            }
            return 0;
        }
        int cnt = 0;
        for (int i = 1; i < N; i++) {
            if (a[i]%3 == 2) {
                use[i] = 0;
                cnt++;
                if (cnt == 2) {
                    good = 1;
                    break;
                }
            }
        }
        if (good) {
            for (int i = 0; i < N; i++) {
                if (use[i]) {
                    cout << a[i];
                }
            }
            return 0;
        }
        for (int i = 1; i < N; i++) {
            if ()
        }
    }
    return 0;
}