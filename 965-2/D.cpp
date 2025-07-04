#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
vt<int> in[200005], out[200005];
int t[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            in[i].clear();
            out[i].clear();
            t[i] = N+1;
        }
        t[0] = -1;
        for (int i = 0; i <= N-1; i++) {
            out[i].push_back(i+1);
            in[i+1].push_back(i);
        }
        for (int i = 0; i < M; i++) {
            int x, y; cin >> x >> y;
            in[y].push_back(x);
            out[x].push_back(y);
        }
        set<int> s;
        s.insert(1);
        string ans = "";
        for (int i = 1; i <= N-1; i++) {
            int hm = *s.rbegin();
            // cout << "i: " << i << " hm: " << hm << endl;
            if (hm > i) {
                ans += '0';
            } else {
                ans += '1';
            }
            for (int j : in[i]) {
                t[i] = min(t[i], t[j]+1);
            }
            for (int j : out[i]) {
                s.insert(j-(t[i]+1));
                // cout << "j: " << j << " t[j]: " << t[j] << " j-(t[j]+1): " << j-(t[j]+1) << endl;
                // cout << "insert: " << j-(t[j]+1) << endl;
            }
        }
        // cout << "t: ";
        // for (int i = 1; i <= N-1; i++) {
        //     cout << t[i] << " ";
        // }
        // cout << endl;
        cout << ans << endl;
    }
    return 0;
}