#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, K;
int a[500005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    vt<int> b(K+1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    vt<int> v;
    for (int x : b) {
        if (x) v.push_back(x);
    }
    sort(v.begin(), v.end());
    int l = v[v.size()-1];
    int r = 2*l;
    while (l < r) {
        
    }
    return 0;
}