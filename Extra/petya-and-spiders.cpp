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
    if (N < M) swap(N, M);
    vt<vt<int>> a(N, vt<int>(1<<M, 0));
    for (int i = 0; i < 1<<M; i++) {
        a[0][i] = 1;
    }
    return 0;
}