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

int T, N;
int a[200005];
map<int, vt<int>> m;

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        m.clear();
        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;
            a[i] = x;
            if (a[i-1] != x) {
                m[x].push_back(i);
            }
        }
        int ans = 0;
        int res1 = 0, res2 = 0;
        for (auto i : m) {
            for (int j = 0; j < i.second.size(); j++) {
                if (res1 == 0) {
                    res1 = i.second[j];
                } else {
                    if (res2 == 0) {
                        if (i.second[j] > res1) {
                            res2 = i.second[j];
                        } else {
                            res1 = i.second[j];
                        }
                    } else {
                        if (res1 >= res2) {
                            if (i.second[j] > res2 && i.second[j] < res1) {
                                res1 = i.second[j];
                            } else if (i.second[j] < res2) {
                                res2 = i.second[j];
                            } else if (i.second[j] > res1) {
                                ans++;
                            }
                        } else {
                            if (i.second[j] > res1 && i.second[j] < res2) {
                                res2 = i.second[j];
                            } else if (i.second[j] < res1) {
                                res1 = i.second[j];
                            } else if (i.second[j] > res2) {
                                ans++;
                            }
                        }
                    }
                }
                cout << "res1: " << res1 << " res2: " << res2 << endl;
                cout << "ans: " << ans << endl;
            }
        }
        cout << ans << endl;
    }
}