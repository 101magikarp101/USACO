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

using namespace std;

struct point {
    ll x, y;
};

int N;
point p[100005];

int main() {
    cin >> N;
    map<ll, vector<ll>> m;
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
        m[p[i].x].push_back(p[i].y);
    }
    sort(p, p + N, [](point a, point b) {
        if (a.y == b.y) {
            return a.x < b.x;
        } else {
            return a.y < b.y;
        }
    });
    ll ans = 0;
    int i = 0;
    while (i < N) {
        ll cur = p[i].y;
        ll l = i;
        ll r = i;
        ll sumx = 0;
        while (i < N && p[i].y == cur) {
            i++;
            r++;
        }
        ll curans = 0;

    }
}