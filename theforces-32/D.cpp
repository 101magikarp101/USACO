#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
string s;
vt<int> sec0, sec1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> s;
        bool all1 = 1, all0 = 1;
        for (int i = 0; i < N; i++) {
            if (s[i] == '0') {
                all1 = 0;
            } else if (s[i] == '1') {
                all0 = 0;
            }
        }
        if (all1) {
            for (int i = N-1; i >= -1; i--) {
                cout << max(0, i) << " ";
            }
            cout << endl;
            continue;
        }
        if (all0) {
            for (int i = -1; i < N; i++) {
                cout << max(0, i) << " ";
            }
            cout << endl;
            continue;
        }
        int trail0 = 0, trail1 = 0;
        sec0.clear();
        sec1.clear();
        int l = -1;
        int o = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '0') {
                if (l == -1) {
                    l = i;
                }
            } else if (l != -1) {
                if (l != 0) {
                    sec0.push_back(i-l);
                } else {
                    trail0+=i;
                }
                l = -1;
            }
        }
        if (l != -1) {
            trail0+=N-l;
        }
        l = -1;
        for (int i = 0; i < N; i++) {
            if (s[i] == '1') {
                if (l == -1) {
                    l = i;
                }
            } else if (l != -1) {
                if (l != 0) {
                    sec1.push_back(i-l);
                    o+=i-l-1;
                } else {
                    trail1+=i;
                    o+=i-1;
                }
                l = -1;
            }
        }
        if (l != -1) {
            trail1+=N-l;
            o+=N-l-1;
        }
        sort(sec0.begin(), sec0.end());
        vt<int> ans(N+1, 0);
        ans[0] = o;
        int cur = 1;
        for (int i = 0; i < sec0.size(); i++) {
            for (int j = 0; j < sec0[i]; j++) {
                if (j == sec0[i]-1) {
                    ans[cur] = ans[cur-1]+2;
                } else {
                    ans[cur] = ans[cur-1]+1;
                }
                cur++;
            }
        }
        for (int i = 0; i < trail0; i++) {
            ans[cur] = ans[cur-1]+1;
            cur++;
        }
        for (int i = 0; i < trail1; i++) {
            ans[cur] = ans[cur-1]-1;
            cur++;
        }
        sort(sec1.begin(), sec1.end(), greater<int>());
        for (int i = 0; i < sec1.size(); i++) {
            for (int j = 0; j < sec1[i]; j++) {
                if (j == 0) {
                    ans[cur] = ans[cur-1]-2;
                } else {
                    ans[cur] = ans[cur-1]-1;
                }
                cur++;
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}