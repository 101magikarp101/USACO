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

struct node {
    int par;
    vt<int> c;
};

int T, N;
node a[200005];
int sz[200005];

void fill(int n) {
    sz[n] = 1;
    for (int i : a[n].c) {
        fill(i);
        sz[n] += sz[i];
    }
}

int solve(int n, int k) {
    int mx = -1;
    int tot = 0;
    for (int i : a[n].c) {
        tot += sz[i];
        if (mx == -1 || sz[i] > sz[mx]) mx = i;
    }
    if (tot == 0) return 0;
    if (sz[mx] - k <= tot-sz[mx]) {
        return (tot-k)/2;
    }
    int add = tot-sz[mx];
    return add + solve(mx, max(0, k+add-1));
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        a[1].par = 0;
        for (int i = 1; i <= N; i++) {
            a[i].c.clear();
        }
        for (int i = 2; i <= N; i++) {
            cin >> a[i].par;
            a[a[i].par].c.push_back(i);
        }
        fill(1);
        int ans = solve(1, 0);
        cout << ans << endl;
    }
}
