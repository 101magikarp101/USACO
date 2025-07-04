#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

struct node {
    int w, x, y, z;
};

struct event {
    int t, x;
    node n;
};

int T, N;
node a[100005];

bool solve() {
    vt<event> e;
    for (int i = 0; i < N; i++) {
        e.push_back({a[i].w, 1, a[i]});
        e.push_back({a[i].x, 0, a[i]});
    }
    sort(e.begin(), e.end(), [](event a, event b) {
        if (a.t == b.t) {
            return a.x > b.x;
        }
        return a.t < b.t;
    });
    // cout << "e: ";
    // for (event i : e) {
    //     cout << i.t << " " << i.x << " " << i.n.w << " " << i.n.x << " " << i.n.y << " " << i.n.z << "\n";
    // }

    multiset<int> s, en;
    for (event i : e) {
        // cout << i.t << " " << i.x << " " << i.n.w << " " << i.n.x << " " << i.n.y << " " << i.n.z << "\n";
        if (i.x == 1) {
            if (!s.empty()) {
                // cout << *s.begin() << " " << *s.rbegin() << " " << i.n.y << " " << i.n.z << "\n";
                if (*s.rbegin() > i.n.z || *en.begin() < i.n.y) {
                    return 0;
                }
            }
            s.insert(i.n.y);
            en.insert(i.n.z);
        } else {
            s.erase(s.find(i.n.y));
            en.erase(en.find(i.n.z));
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i].w >> a[i].x >> a[i].y >> a[i].z;
    }
    int ans1 = solve();
    // cout << "ans1: " << ans1 << "\n";
    for (int i = 0; i < N; i++) {
        swap(a[i].w, a[i].y);
        swap(a[i].x, a[i].z);
    }
    int ans2 = solve();
    if (ans1 && ans2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    return 0;
}