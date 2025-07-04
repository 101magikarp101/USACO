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

struct state {
    char c;
    int x, y, z;
};

int T, N;
unordered_map<char, int> mp;

int main () {
    string tmp = "ADFGVX";
    for (int i = 0; i < 6; i++) {
        mp[tmp[i]] = i;
    }
    cin >> T;
    while (T--) {
        int a[6][6];
        for (int i = 0; i < 6; i++) {
            string s; cin >> s;
            for (int j = 0; j < 6; j++) {
                a[i][j] = s[j];
            }
        }
        string key; cin >> key;
        vt<state> v(key.size());
        for (int i = 0; i < key.size(); i++) {
            v[i] = {key[i], i, -1};
        }
        sort(v.begin(), v.end(), [](state a, state b) {
            return a.c < b.c;
        });
        for (int i = 0; i < key.size(); i++) {
            v[i].y = i;
        }
        sort(v.begin(), v.end(), [](state a, state b) {
            return a.x < b.x;
        });
        string fin; cin >> fin;
        string next;
        for (int i = 0; i < fin.size()/key.size(); i++) {
            for (int j = 0; j < key.size(); j++) {
                next += fin[i*key.size() + v[j].y];
            }
        }
        int m = fin.size()%key.size();
        sort(v.begin(), v.begin()+m, [](state a, state b) {
            return a.c < b.c;
        });
        for (int i = 0; i < m; i++) {
            v[i].z = i;
        }
        sort(v.begin(), v.begin()+m, [](state a, state b) {
            return a.x < b.x;
        });
        for (int i = 0; i < m; i++) {
            next += fin[(fin.size()/key.size())*key.size() + v[i].z];
        }
        // cout << next << endl;
        string ans = "";
        for (int i = 0; i < next.size(); i+=2) {
            int x = mp[next[i]], y = mp[next[i+1]];
            ans += a[x][y];
        }
        cout << ans << endl;
    }
}