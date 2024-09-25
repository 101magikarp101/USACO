#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

struct node {
    int v;
    vt<node> c;
};

int N, K;
vt<node> s;

void add(node &n, int v) {
    if (v<n.v) {
        if (n.c[0].v==0) {
            node x = {v, vt<node>(2)};
            n.c[0] = x;
        } else {
            add(n.c[0], v);
        }
    } else {
        if (n.c[1].v==0) {
            node x = {v, vt<node>(2)};
            n.c[1] = x;
        } else {
            add(n.c[1], v);
        }
    }
}

bool same(node &n, node&m) {
    bool res = 1;
    if (n.c[0].v!=0 && m.c[0].v!=0) {
        res &= same(n.c[0], m.c[0]);
    } else if (n.c[0].v==0 && m.c[0].v==0) {
        res &= 1;
    } else {
        res &= 0;
    }
    if (n.c[1].v!=0 && m.c[1].v!=0) {
        res &= same(n.c[1], m.c[1]);
    } else if (n.c[1].v==0 && m.c[1].v==0) {
        res &= 1;
    } else {
        res &= 0;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        node n = {0, vt<node>(2)};
        cin >> n.v;
        for (int j = 1; j < K; j++) {
            int x;
            cin >> x;
            add(n, x);
        }
        bool diff = 1;
        for (int j = 0; j < s.size(); j++) {
            if (same(n, s[j])) {
                diff = 0;
                break;
            }
        }
        if (diff) {
            s.push_back(n);
        }
    }
    cout << s.size() << endl;
    return 0;
}