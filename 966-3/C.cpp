#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        cin >> M;
        while (M--) {
            string s; cin >> s;
            if (s.size() != N) {
                cout << "NO" << endl;
                continue;
            }
            map<int, int> b;
            vt<int> c(26,INT_MAX);
            bool good = 1;
            for (int i = 0; i < N; i++) {
                if (b.find(a[i]) == b.end()) {
                    if (c[s[i]-'a'] == INT_MAX) {
                        b[a[i]] = s[i]-'a';
                        c[s[i]-'a'] = a[i];
                    } else {
                        good = 0;
                        break;
                    }
                } else {
                    if (b[a[i]] != s[i]-'a') {
                        good = 0;
                        break;
                    }
                }
            }
            cout << (good ? "YES" : "NO") << endl;
        }
    }
    return 0;
}