#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int a[21][21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 21; i++) {
        string s; cin >> s;
        for (int j = 0; j < 21; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    int ans = 0;
    //max 4x4 sum
    int pre[21][21];
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            pre[i][j] = a[i][j];
            if (i > 0) pre[i][j] += pre[i-1][j];
            if (j > 0) pre[i][j] += pre[i][j-1];
            if (i > 0 && j > 0) pre[i][j] -= pre[i-1][j-1];
        }
    }
    for (int i = 3; i < 21; i++) {
        for (int j = 3; j < 21; j++) {
            int sum = pre[i][j];
            if (i > 3) sum -= pre[i-4][j];
            if (j > 3) sum -= pre[i][j-4];
            if (i > 3 && j > 3) sum += pre[i-4][j-4];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}