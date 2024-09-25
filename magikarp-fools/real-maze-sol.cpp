#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int a = 0, b = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c; cin >> c;
            if (c == '#') {
                a++;
            } else {
                b++;
            }
        }
    }
    cout << (a^b)+7 << '\n';
    return 0;
}