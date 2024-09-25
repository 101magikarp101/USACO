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
    cin >> N;
    vt<vt<int>> ans(3,vt<int>(3,0));
    int h = 0;
    for (int i = 0; i < 31; i++) {
        if (N & (1 << i)) {
            h=i;
        }
    }
    h++;
    ans[0][0] = N|(1<<h);
    ans[1][0] = N;
    ans[0][1] = (1<<h);
    ans[1][1] = N|(1<<h);
    ans[2][1] = N;
    ans[2][2] = N;
    cout << "3 3\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}