#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> s;
        int N = s.size();
        char c = s[0];
        int cnt = 0;
        int hm = 0;
        int tot = 0;
        for (int i = 0; i < N; i++) {
            if (s[i]==c) {
                cnt++;
            } else {
                hm++;
                if (hm == 2) {
                    tot++;
                    hm = 0;
                    cnt = 0;
                } else {
                    hm++;
                    cnt = 0;
                }
            }
        }
        if (cnt == 0) {
            cout 
        }
    }
    return 0;
}