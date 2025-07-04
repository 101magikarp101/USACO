#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        vt<vt<char>> ans(N*2, vt<char>(N*2));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((i+j)%2==0) {
                    ans[2*i][2*j] = '#';
                    ans[2*i+1][2*j+1] = '#';
                    ans[2*i][2*j+1] = '#';
                    ans[2*i+1][2*j] = '#';
                } else {
                    ans[2*i][2*j] = '.';
                    ans[2*i+1][2*j+1] = '.';
                    ans[2*i][2*j+1] = '.';
                    ans[2*i+1][2*j] = '.';
                }
            }
        }
        for (int i = 0; i < N*2; i++) {
            for (int j = 0; j < N*2; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}