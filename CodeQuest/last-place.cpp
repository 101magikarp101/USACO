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

struct point {
    int x, y;
    point () {}
    point (int x, int y) : x(x), y(y) {}
};

struct seg {
    point p1, p2;
    seg () {}
    seg (point p1, point p2) : p1(p1), p2(p2) {}
};

int T;

pair<bool, seg> intersect(seg s1, seg s2) {
    int m1 = (s1.p2.y-s1.p1.y)/(s1.p2.x-s1.p1.x);
    int m2 = (s2.p2.y-s2.p1.y)/(s2.p2.x-s2.p1.x);
    if (m1 == m2) {
        if (-m1*s1.p1.x+s1.p1.y == -m2*s2.p1.x+s2.p1.y) {
            seg s;
            if (s1.p2.y > s2.p2.y) {
                s.p2 = s2.p2;
            } else {
                s.p2 = s1.p2;
            }
            if (s1.p1.y < s2.p1.y) {
                s.p1 = s2.p1;
            } else {
                s.p1 = s1.p1;
            }
            return {true, s};
        } else {
            return {false, seg()};
        }
    } else {
        int x = (m1*s1.p1.x-s1.p1.y-m2*s2.p1.x+s2.p1.y)/(m1-m2);
        int y = m1*(x-s1.p1.x)+s1.p1.y;
        if (x >= min(s1.p1.x, s1.p2.x) && x <= max(s1.p1.x, s1.p2.x) && x >= min(s2.p1.x, s2.p2.x) && x <= max(s2.p1.x, s2.p2.x) && y >= min(s1.p1.y, s1.p2.y) && y <= max(s1.p1.y, s1.p2.y) && y >= min(s2.p1.y, s2.p2.y) && y <= max(s2.p1.y, s2.p2.y)) {
            return {true, seg(point(x, y), point(x, y))};
        } else {
            return {false, seg()};
        }
    }
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main () {
    cin >> T;
    for (int t = 0; t < T; t++) {
        ll x1, y1, d1, x2, y2, d2, x3, y3, d3;
        cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2 >> x3 >> y3 >> d3;
        seg a[4], b[4], c[4];
        for (int i = 0; i < 4; i++) {
            a[i] = seg(point(x1+d1*dx[i], y1+d1*dy[i]), point(x1+d1*dx[(i+1)%4], y1+d1*dy[(i+1)%4]));
            b[i] = seg(point(x2+d2*dx[i], y2+d2*dy[i]), point(x2+d2*dx[(i+1)%4], y2+d2*dy[(i+1)%4]));
            c[i] = seg(point(x3+d3*dx[i], y3+d3*dy[i]), point(x3+d3*dx[(i+1)%4], y3+d3*dy[(i+1)%4]));
            if (a[i].p1.y > a[i].p2.y) swap(a[i].p1, a[i].p2);
            if (b[i].p1.y > b[i].p2.y) swap(b[i].p1, b[i].p2);
            if (c[i].p1.y > c[i].p2.y) swap(c[i].p1, c[i].p2);
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    pair<bool, seg> p = intersect(a[i], b[j]);
                    if (p.first) {
                        // cout << "(" << p.second.p1.x << "," << p.second.p1.y << "),(" << p.second.p2.x << "," << p.second.p2.y << ")" << endl;
                        pair<bool, seg> q = intersect(p.second, c[k]);
                        if (q.first) {
                            cout << "(" << q.second.p1.x << "," << q.second.p1.y << ")" << endl;
                        }
                    }
                }
            }
        }
        end:;
    }
}