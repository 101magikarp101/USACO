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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct point {
    int x, y;
};

int C, P;
int a[102];

vt<vt<point>> pieces[7];

bool good (int x, int y) {
    return x >= 0 && x < C && y >= 0;
}

int main () {
    // pieces[0].push_back({{0, 0}, {0, 1}, {0, 2}, {0, 3}});
    // pieces[1].push_back({{0, 0}, {0, 1}, {1, 0}, {1, 1}});
    // pieces[2].push_back({{0, 0}, {1, 0}, {1, 1}, {2, 1}});
    // pieces[2].push_back({{0, 0}, {0, 1}, {1, 0}, {1, -1}});
    // pieces[3].push_back({{0, 0}, {1, 0}, {1, -1}, {2, -1}});
    // pieces[3].push_back({{0, 0}, {0, 1}, {1, 1}, {1, 2}});
    // pieces[4].push_back({{0, 0}, {1, 0}, {1, 1}, {2, 0}});
    // pieces[4].push_back({{0, 0}, {0, 1}, {0, 2}, {1, 1}});
    // pieces[4].push_back({{0, 0}, {1, 0}, {1, -1}, {2, 0}});
    // pieces[4].push_back({{0, 0}, {0, 1}, {0, 2}, {-1, 1}});
    // pieces[5].push_back({{0, 0}, {1, 0}, {2, 0}, {2, 1}});
    // pieces[5].push_back({{0, 0}, {1, 0}, {1, -1}, {1, -2}});
    // pieces[5].push_back({{0, 0}, {0, 1}, {0, 2}, {1, 0}});
    // pieces[5].push_back({{0, 0}, {0, 1}, {1, 1}, {2, 1}});
    // pieces[6].push_back({{0, 0}, {0, 1}, {1, 0}, {2, 0}});
    // pieces[6].push_back({{0, 0}, {0, 1}, {0, 2}, {1, 2}});
    // pieces[6].push_back({{0, 0}, {1, 0}, {2, 0}, {2, -1}});
    // pieces[6].push_back({{0, 0}, {1, 0}, {1, 1}, {1, 2}});
    //keep only the minimum y value for every piece
    pieces[0].push_back({{0, 0}});
    pieces[0].push_back({{0, 0}, {1, 0}, {2, 0}, {3, 0}});
    pieces[1].push_back({{0, 0}, {1, 0}});
    pieces[2].push_back({{0, 0}, {1, 0}, {2, 1}});
    pieces[2].push_back({{0, 0}, {1, -1}});
    pieces[3].push_back({{0, 0}, {1, -1}, {2, -1}});
    pieces[3].push_back({{0, 0}, {1, 1}});
    pieces[4].push_back({{0, 0}, {1, 0}, {2, 0}});
    pieces[4].push_back({{0, 0}, {1, 1}});
    pieces[4].push_back({{0, 0}, {1, -1}});
    pieces[4].push_back({{0, 0}, {1, -1}, {2, 0}});
    pieces[5].push_back({{0, 0}, {1, 0}, {2, 0}});
    pieces[5].push_back({{0, 0}, {1, -2}});
    pieces[5].push_back({{0, 0}, {1, 0}});
    pieces[5].push_back({{0, 0}, {1, 1}, {2, 1}});
    pieces[6].push_back({{0, 0}, {1, 0}, {2, -1}});
    pieces[6].push_back({{0, 0}, {1, 2}});
    pieces[6].push_back({{0, 0}, {1, 0}});
    pieces[6].push_back({{0, 0}, {1, 0}, {2, 0}});
    cin >> C >> P;
    P--;
    for (int i = 0; i < C; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < C; i++) {
        for (auto p : pieces[P]) {
            bool ok = true;
            for (auto q : p) {
                if (!good(i + q.x, a[i] + q.y)) {
                    ok = false;
                    break;
                }
                if (a[i+q.x] != a[i]+q.y) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}