#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T, N;
int a[200005];
int ans[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        set<int> s;
        int mex = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] < 0) {
                ans[i] = mex-a[i];
            } else {
                ans[i] = mex;
            }
            s.insert(ans[i]);
            while (s.count(mex)) {
                mex++;
            }
        }
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}