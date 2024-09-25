#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        string n = to_string(N);
        vt<pii> ans;
        for (int a = 1; a <= 10000; a++) {
            int l = ceil(log10(a+1));
            string temp = "";
            for (int i = 0; i < 30; i++) {
                temp += n[i%n.size()];
                int b = a*n.size()-i-1;
                if (b <= 0) continue;
                if (a*N-b == stoi(temp)) {
                    ans.push_back({a, b});
                    break;
                }
                if (a*N-b < stoi(temp)) break;
            }
        }
        cout << ans.size() << "\n";
        for (pii p : ans) {
            cout << p.x << " " << p.y << "\n";
        }
    }
    return 0;
}