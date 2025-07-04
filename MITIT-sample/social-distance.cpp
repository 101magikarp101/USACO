#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct edge {
    int to;
    ll w;
};

struct state {
    int n, c, prev;
    ll d;
};

int N, M;
vt<edge> a[200005];
int ans[200005];
ll dist[200005];

bool check(ll x) {
    cout << "x: " << x << endl;
    unordered_set<int> st;
    for (int i = 1; i <= N; i++) {
        ans[i] = -1;
        st.insert(i);
        dist[i] = 1e18;
    }
    queue<state> q;
    deque<state> dq;
    q.push({1, 0, -1, 0});
    st.erase(1);
    ans[1] = 0;
    dist[1] = 0;
    while (!q.empty()) {
        while (!q.empty()) {
            state t = q.front();
            q.pop();
            dq.push_back({t.n, t.c, -1, 0});
        }
        state s = dq.front();
        while (!dq.empty()) {
            state t = dq.front();
            dq.pop_front();
            cout << "s.c: " << s.c << " t.n: " << t.n << " t.d: " << t.d << endl;
            for (edge e : a[t.n]) {
                cout << "e.to: " << e.to << " e.w: " << e.w << endl;
                if (t.d+e.w < x) {
                    if (ans[e.to] == -1 && t.d+e.w < dist[e.to]) {
                        ans[e.to] = s.c^1;
                        dq.push_back({e.to, s.c^1, t.n, t.d+e.w});
                        q.push({e.to, s.c^1, t.n, t.d+e.w});
                        st.erase(e.to);
                        dist[e.to] = t.d+e.w;
                    } else if (e.to != t.prev && ans[e.to] == s.c) {
                        cout << "ans[e.to]: " << ans[e.to] << endl;
                        return false;
                    }
                }
            }
        }
        cout << "ans: ";
        for (int i = 1; i <= N; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        if (q.empty() && !st.empty()) {
            q.push({*st.begin(), 0, -1, 0});
            ans[*st.begin()] = 0;
            st.erase(st.begin());
        }
    }
    return true;
}

int main () {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        a[x].push_back({y, w});
        a[y].push_back({x, w});
    }
    ll low = 0, high = 1e9;
    while (low < high) {
        ll mid = (low+high+1)/2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid-1;
        }
    }
    cout << low << endl;
}