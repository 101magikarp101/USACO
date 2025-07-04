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

map<int,vt<vt<int>>> m;
vt<vt<int>> get(int n) {
    vt<vt<int>> v;
    v.push_back({n});
    for (int i = 2; i < n; i++) {
        if (n%i == 0) {
            vt<vt<int>> a = get(i);
            for (int j = 0; j < a.size(); j++) {
                a[j].push_back(n/i);
                v.push_back(a[j]);
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (!is_sorted(v[i].begin(), v[i].end())) {
            v.erase(v.begin()+i);
            i--;
        }
    }
    return v;
}

int main () {
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        vt<int> v;
        for (int i = 1; i*i <= n; i++) {
            if (n%i == 0) {
                v.push_back(i);
                if (i != n/i) {
                    v.push_back(n/i);
                }
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            m[v[i]] = get(v[i]);
        }
        // for (int i = 0; i < v.size(); i++) {
        //     cout << v[i] << ":";
        //     for (int j = 0; j < m[v[i]].size(); j++) {
        //         for (int k = 0; k < m[v[i]][j].size(); k++) {
        //             cout << " " << m[v[i]][j][k];
        //         }
        //         cout << endl;
        //     }
        // }
        if (m[n].size() != 1) {
            cout << n <<"=";
            for (int i = 1; i < m[n].size(); i++) {
                cout <<"(";
                for (int j = m[n][i].size()-1; j >= 0; j--) {
                    cout << m[n][i][j];
                    if (j != 0) {
                        cout << "*";
                    }
                }
                cout << ")";
                if (i != m[n].size()-1) {
                    cout << ",";
                }
            }
            cout << endl;
        }
    }
    return 0;
}