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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int T, C;
unordered_set<int> c;
int pos[100005];
string s;
map<int, vector<int>> m;
map<int, map<int, int>> m1;
map<int, int> m2;
int ans;

void test(int n) {
    vector<int> res = vector<int>(C);
    int cur = n;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'L') {
            cur--;
            res[i] = INT_MAX;
        } else if (s[i] == 'R') {
            cur++;
            res[i] = INT_MAX;
        } else {
            if (c.find(cur) != c.end()) {
                // cout << "n: " << n << " i: " << i << " cur: " << cur << endl;
                res[i] = cur;
                m1[n][cur]++;
            } else {
                res[i] = INT_MAX;
            }
        }
        if (n == 0) {
            pos[i] = cur;
        }
    }
    m[n] = res;
}

void solve(int start, int end, char c1, char c2) {
    // cout << "start: " << start << " end: " << end << " c1: " << c1 << " c2: " << c2 << endl;
    m2.clear();
    for (auto it = m1[end].begin(); it != m1[end].end(); it++) {
        m2[it->first] = it->second;
    }
    for (int i = 0; i < s.length(); i++) {
        if (c2 == 'F') {
            if (i > 0) {
                if (m[end][i-1] != INT_MAX) {
                    m2[m[end][i-1]]--;
                    if (m2[m[end][i-1]] == 0) {
                        m2.erase(m[end][i-1]);
                    }
                }
                if (m[start][i-1] != INT_MAX) {
                    m2[m[start][i-1]]++;
                }
            }
            int p = pos[i] + end;
            if (c.find(p) != c.end()) {
                m2[p]++;
            }
            if (s[i] == c1) {
                ans = max(ans, (int)m2.size());
            }
            if (c.find(p) != c.end()) {
                m2[p]--;
                if (m2[p] == 0) {
                    m2.erase(p);
                }
            }
        } else if (c1 == 'F') {
            if (m[end][i] != INT_MAX) {
                m2[m[end][i]]--;
                if (m2[m[end][i]] == 0) {
                    m2.erase(m[end][i]);
                }
            }
            if (i > 0 && m[start][i-1] != INT_MAX) {
                m2[m[start][i-1]]++;
            }
            if (s[i] == c1) {
                ans = max(ans, (int)m2.size());
            }
        } else {
            if (m[end][i] != INT_MAX) {
                m2[m[end][i]]--;
                if (m2[m[end][i]] == 0) {
                    m2.erase(m[end][i]);
                }
            }
            if (i > 0 && m[start][i-1] != INT_MAX) {
                m2[m[start][i-1]]++;
            }
            if (s[i] == c1) {
                ans = max(ans, (int)m2.size());
            }
        }
    }
}

int main() {
    cin >> T >> C;
    for (int i = 0; i < T; i++) {
        int a;
        cin >> a;
        c.insert(a);
    }
    cin >> s;
    for (int i = -2; i <= 2; i++) {
        test(i);
    }
    // cout << "m: " << endl;
    // for (auto it = m.begin(); it != m.end(); it++) {
    //     cout << it->first << ": ";
    //     for (int i = 0; i < it->second.size(); i++) {
    //         cout << it->second[i] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "m1: " << endl;
    // for (auto it = m1.begin(); it != m1.end(); it++) {
    //     cout << it->first << ": ";
    //     for (auto it1 = it->second.begin(); it1 != it->second.end(); it1++) {
    //         cout << it1->first << " " << it1->second << " " << endl;
    //     }
    // }
    // L to R
    ans = m1[0].size();
    solve(0, 2, 'L', 'R'); // L to R
    solve(0, -2, 'R', 'L'); // R to L
    solve(0, 1, 'L', 'F'); // L to F
    solve(0, -1, 'R', 'F'); // R to F
    solve(0, -1, 'F', 'L'); // F to L
    solve(0, 1, 'F', 'R'); // F to R
    cout << ans << endl;
}