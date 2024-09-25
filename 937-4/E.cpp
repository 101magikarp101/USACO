#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T, N;
int a[200005];
string s;

bool check (int x) {
    map<string, int> m;
    // cout << "s: " << s << " x: " << x << endl;
    for (int i = 0; i <= N-x; i+=x) {
        // cout << "i: " << i << " x: " << x << endl;
        string t = s.substr(i, x);
        m[t]++;
    }
    if (m.size() > 2) return false;
    if (m.size() == 1) return true;
    if (m.size() == 2) {
        string s1 = m.begin()->first;
        int cnt1 = m.begin()->second;
        string s2 = (++m.begin())->first;
        int cnt2 = (++m.begin())->second;
        if (cnt1 == 1 || cnt2 == 1) {
            int d = 0;
            for (int i = 0; i < s1.length(); i++) {
                if (s1[i] != s2[i]) {
                    d++;
                }
            }
            return d <= 1;
        } else {
            return false;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> s;
        int ans = N;
        for (int i = 1; i*i <= N; i++) {
            if (N % i == 0) {
                if (check(i)) {
                    ans = min(ans, i);
                }
                if (check(N/i)) {
                    ans = min(ans, N/i);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}