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
struct pii {int x, y;};
struct pll {int x, y;};

struct unit {
    ll c, d, h;
};

int N, M;
ll C;
unit a[300005];


int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> a[i].c >> a[i].d >> a[i].h;
    }
    for (int i = 0; i < M; i++) {
        ll D, H; cin >> D >> H;
    }
    return 0;
}