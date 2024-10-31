#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    int p[100000];
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] != i + 1) s.insert(i + 1);
    }
    tuple<int, int, int> wormholes[100000];
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        wormholes[i] = make_tuple(a, b, t);
    }
    sort(wormholes, wormholes + m, [](tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<2>(a) < get<2>(b);
    });
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a = get<0>(wormholes[i]);
        int b = get<1>(wormholes[i]);
        int t = get<2>(wormholes[i]);
        if (s.find(a) != s.end()) {
            s.insert(b);
            ans += t;
            continue;
        }
        if (s.find(b) != s.end()) {
            s.insert(a);
            ans += t;
            continue;
        }
        if (p[a - 1] < p[b - 1]) {
            s.insert(a);
            ans += t;
        } else {
            s.insert(b);
            ans += t;
        }
    }
}