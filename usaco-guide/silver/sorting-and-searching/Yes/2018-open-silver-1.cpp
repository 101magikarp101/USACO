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

struct hmm {
    int a, b, i;
};

int N;
int a[100005];

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> N;
    map<int, int> m;
    vt<hmm> v;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        m[a[i]]++;
        v.push_back({a[i], m[a[i]], i});
    }
    sort(v.begin(), v.end(), [](hmm a, hmm b) {
        if (a.a==b.a) return a.b < b.b;
        return a.a < b.a;
    });
    // cout << "v: " << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << v[i].a << " " << v[i].b << " " << v[i].i << endl;
    // }
    int ans = 1;
    for (int i = 0; i < N; i++) {
        if (v[i].i>i) {
            ans = max(ans, v[i].i-i+1);
        }
    }
    cout << ans << endl;
    return 0;
}