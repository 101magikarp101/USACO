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

struct hm {
    int z, o;
};

int T, N;
hm a[100005];

int main () {
    cin >> T;
    for (int t = 0; t < T; t++) {
        string s; cin >> s;
        int z = 0, o = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') z++;
            else o++;
        }
        a[t] = {z, o};
    }
    sort(a, a+T, [](hm a, hm b) {
        return a.z < b.z;
    });
    int ow = a[0].z, oi = 0;
    int zw = INT_MAX, zi = -1;
    for (int i = 1; i < T; i++) {
        if (a[i].o < zw) {
            zw = a[i].o;
            zi = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < T; i++) {
        if (i == zi) {
            ans += a[i].o;
        } else if (i == oi) {
            ans += a[i].z;
        } else {
            ans += min(a[i].z, a[i].o);
        }
    }
    sort(a, a+T, [](hm a, hm b) {
        return a.o < b.o;
    });
    zw = a[0].o, zi = 0;
    ow = INT_MAX, oi = -1;
    for (int i = 1; i < T; i++) {
        if (a[i].z < ow) {
            ow = a[i].z;
            oi = i;
        }
    }
    int ans2 = 0;
    for (int i = 0; i < T; i++) {
        if (i == zi) {
            ans2 += a[i].o;
        } else if (i == oi) {
            ans2 += a[i].z;
        } else {
            ans2 += min(a[i].z, a[i].o);
        }
    }
    cout << min(ans, ans2) << endl;
}