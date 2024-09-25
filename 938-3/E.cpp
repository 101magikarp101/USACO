#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[5005];

bool solve(int x) {
    set<int> s;
    for (int i = 0; i < N; i++) {
        if (s.find(i-1) != s.end()) {
            s.erase(s.begin());
        }
        if ((a[i]+s.size())%2==0) {
            if (i+x-1 >= N) return false;
            s.insert(i+x-1);
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        string s;
        cin >> s;
        for (int i = 0; i < N; i++) {
            a[i] = s[i]-'0';
        }
        for (int l = N; l >= 1; l--) {
            if (solve(l)) {
                cout << l << '\n';
                break;
            }
        }
    }
    return 0;
}