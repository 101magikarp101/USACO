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

struct nei {
    ll l, r;
};

struct particle {
    ll x, v;
};

struct state {
    ll val;
    ll l, r;
    bool operator<(const state& s) const {
        return val < s.val;
    }
    bool operator>(const state& s) const {
        return val > s.val;
    }
};

int T;
ll N;
particle a[200005];
ll ans[200005];
nei neis[200005];

ll calc(int n, int m) {
    ll x = a[n].x;
    ll v1 = a[n].v;
    ll y = a[m].x;
    ll v2 = a[m].v;
    if (n%2==0) {
        return ceil((double)(y-x)/(v1+v2))*2-1;
    } else {
        return ceil((double)(y-x)/(v1+v2))*2;
    }
}

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i].x;
        }
        for (int i = 0; i < N; i++) {
            cin >> a[i].v;
        }
        for (int i = 0; i < N; i++) {
            neis[i].l = i>0?i-1:-1;
            neis[i].r = i<N-1?i+1:-1;
        }
        priority_queue<state, vt<state>, greater<state>> pq;
        for (int i = 0; i < N-1; i++) {
            pq.push({calc(i, i+1), i, i+1});
        }
        while (!pq.empty()) {
            state s = pq.top();
            pq.pop();
            // cout << s.val << " " << s.l << " " << s.r << endl;
            if (neis[s.l].r!=s.r || neis[s.r].l!=s.l) {
                continue;
            }
            ans[s.l] = s.val;
            ans[s.r] = s.val;
            if (neis[s.l].l!=-1) {
                neis[neis[s.l].l].r = neis[s.r].r;
                if (neis[s.r].r!=-1) {
                    pq.push({calc(neis[s.l].l, neis[s.r].r), neis[s.l].l, neis[s.r].r});
                }
            } else {
                neis[s.r].l = -1;
            }
            if (neis[s.r].r!=-1) {
                neis[neis[s.r].r].l = neis[s.l].l;
                if (neis[s.l].l!=-1) {
                    pq.push({calc(neis[s.l].l, neis[s.r].r), neis[s.l].l, neis[s.r].r});
                }
            } else {
                neis[s.l].r = -1;
            }
            neis[s.l].l = -1;
            neis[s.l].r = -1;
            neis[s.r].l = -1;
            neis[s.r].r = -1;
        }
        for (int i = 0; i < N; i++) {
            cout << ans[i];
            if (i<N-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}