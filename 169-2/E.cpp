#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[10000005];
ll b[300005];

void init(int x) {
    for (int i = 0; i < x; i++) {
        a[i] = -1;
    }
    for (int i = 0; i < x; i+=2) {
        a[i] = 0;
    }
    a[1] = 1;
    int cnt = 2;
    for (int i = 3; i < x; i++) {
        if (a[i] == -1) {
            a[i] = cnt;
            for (int j = i; j < x; j+=i) {
                if (a[j]==-1) {
                    a[j] = cnt;
                }
            }
            cnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init(10000005);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        int x = 0;
        for (int i = 0; i < N; i++) {
            x ^= a[b[i]];
        }
        cout << (x?"Alice":"Bob") << endl;
    }
    return 0;
}