#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int hm[] = {0,1,0,0,1,1};
    for (int i = 21; i <= 50; i++) {
        cout << hm[i%6] << endl;
    }
    return 0;
}