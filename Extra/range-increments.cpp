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
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
ll a[100005];
vt<pii> v;

int main () {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    int ans = 0;
    vt<pii> an;
    for (int i = 1; i <= N+1; i++) {
        if (a[i-1] > a[i]) {
            ans += a[i-1] - a[i];
            while (v.size() > 0 && v.back().ff > a[i]) {
                an.push_back({v.back().ss, i-1});
                v.pop_back();
            }
        }
        if (a[i] > a[i-1]) {
            for (int j = a[i-1]+1; j <= a[i]; j++) {
                v.push_back({j, i});
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < an.size(); i++) {
        cout << an[i].ff << " " << an[i].ss << endl;
    }
}