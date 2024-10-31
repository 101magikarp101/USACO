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

int N; 
map<int, vt<int>> m;

int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        for (int j = 2; j*j <= a; j++) {
            if (a%j == 0) {
                int cnt = 0;
                while (a%j == 0) {
                    a /= j;
                    cnt++;
                }
                m[j].push_back(cnt);
            }
        }
        if (a > 1) {
            m[a].push_back(1);
        }
    }
    ll ans = 1;
    for (auto i : m) {
        if (i.second.size() == N || i.second.size() == N-1) {
            sort(i.second.begin(), i.second.end());
        } else {
            continue;
        }
        if (i.second.size() == N) {
            ans *= pow(i.first, i.second[1]);
        } else if (i.second.size() == N-1) {
            ans *= pow(i.first, i.second[0]);
        }
    }
    cout << ans << endl;
}