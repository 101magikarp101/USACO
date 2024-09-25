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

int check(vt<int> &v) {
    vt<vt<int>> a(3, vt<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = v[i*3+j];
        }
    }
    int s1 = a[0][0]+a[1][1]+a[2][2];
    int s2 = a[0][0]+a[0][1]+a[0][2];
    int s3 = a[0][0]+a[1][0]+a[2][0];
    return s1 == s2 && s2 == s3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vt<int> v = {1,2,3,4,5,6,7,8,9};
    int ans = 0;
    do {
        ans += check(v);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}