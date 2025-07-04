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
set<int> s;
map<int, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        s.clear();
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int mex = 0;
        for (int i = 0; i < N; i++) {
            if (s.find(mex) != s.end()) {
                mex++;
            } else {
                break;
            }
        }
        if (mex == 0) {
            cout << 1 << endl;
            continue;
        }
        m.clear();
        int r = -1;
        for (int i = 0; i < N; i++) {
            if (a[i] < mex) {
                m[a[i]]++;
            }
            if (m.size() == mex) {
                r = i;
                break;
            }
        }
        int ans = r+1;
        for (int i = 1; i < N; i++) {
            if (m.count(a[i-1])) {
                m[a[i-1]]--;
                if (m[a[i-1]] == 0) {
                    m.erase(a[i-1]);
                }
            }
            while (r < N-1 && m.size() < mex) {
                r++;
                if (a[r] < mex) {
                    m[a[r]]++;
                }
            }
            if (m.size() < mex) {
                break;
            }
            // cout << "i: " << i << " r: " << r << endl;
            ans = min(ans, r-i+1);
        }
        cout << ans << endl;
    }
    return 0;
}