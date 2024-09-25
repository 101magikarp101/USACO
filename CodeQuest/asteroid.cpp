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
};

int T, N;

int main () {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        vt<point> p(N);
        for (int i = 0; i < N; i++) {
            cin >> p[i].x >> p[i].y;
        }
        sort(p.begin(), p.end(), [](point a, point b) {
            return a.x*a.x+a.y*a.y < b.x*b.x+b.y*b.y;
        });
        for (int i = 0; i < N; i++) {
            cout << p[i].x << " " << p[i].y << endl;
        }
    }
}