#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, Q;
int a[200005];
int res[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        res[i] = -1;
    }
    vt<deque<int>> v;
    deque<int> temp;
    for (int i = 1; i <= N; i++) {
        temp.push_back(i);
    }
    v.push_back(temp);
    for (int d = N; d >= 1; d--) {
        for (int i = 0; i < v.size(); i++) {
            deque<int> t;
            while (v[i].size() > d) {
                int x = v[i].back();
                v[i].pop_back();
                if (a[x] < i+2) {
                    res[x] = d;
                } else {
                    if (i == v.size()-1) {
                        t.push_front(x);
                    } else {
                        v[i+1].push_front(x);
                    }
                }
            }
            if (!t.empty()) {
                v.push_back(t);
            }
        }
    }
    // cout << "res: ";
    // for (int i = 1; i <= N; i++) cout << res[i] << " ";
    // cout << "\n";
    while (Q--) {
        int i, x; cin >> i >> x;
        if (x <= res[i]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}