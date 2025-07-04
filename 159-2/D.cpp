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

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

pii operator+(const pii& a, const pii& b) {
    return {a.first+b.first, a.second+b.second};
}

pii operator-(const pii& a, const pii& b) {
    return {a.first-b.first, a.second-b.second};
}

int N, Q;
pii pos[200005];
map<pii, vector<int>> mp;

bool find(pii p, int l, int r) {
    if (mp.find(p) == mp.end()) return false;
    auto it = lower_bound(mp[p].begin(), mp[p].end(), l);
    return it != mp[p].end() && *it <= r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    string s;
    cin >> s;
    pos[0] = {0, 0};
    for (int i = 1; i <= N; i++) {
        pos[i].first = pos[i-1].first+(s[i-1]=='R')-(s[i-1]=='L');
        pos[i].second = pos[i-1].second+(s[i-1]=='U')-(s[i-1]=='D');
    }
    for (int i = 0; i <= N; i++) {
        mp[pos[i]].push_back(i);
    }
    for (int i = 0; i < Q; i++) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        pii p = {x, y};
        p = pos[r]+pos[l-1]-p;
        if (find({x,y}, 0, l-1) || find({x,y}, r, N) || find(p, l, r-1)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}