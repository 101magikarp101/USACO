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

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int N;
string a, b;
map<string, string> par;

int main() {
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    cin >> N >> a >> b;
    for (int i = 0; i < N; i++) {
        string x, y;
        cin >> x >> y;
        par[y] = x;
    }
    int cnt = 0;
    string a1 = a, b1 = b;
    map<string, int> a2;
    vector<string> b2;
    a2.insert({a1, 0});
    while (par.find(a1) != par.end()) {
        a1 = par[a1];
        cnt++;
        a2.insert({a1, cnt});
    }
    cnt = 0;
    b2.push_back(b1);
    while (par.find(b1) != par.end()) {
        b1 = par[b1];
        cnt++;
        b2.push_back(b1);
    }
    int res1 = -1, res2 = -1;
    for (int i = 0; i < b2.size(); i++) {
        if (a2.find(b2[i]) != a2.end()) {
            res1 = a2[b2[i]];
            res2 = i;
            break;
        }
    }
    if (res1 == -1 || res2 == -1) {
        cout << "NOT RELATED" << endl;
        return 0;
    } else if (res1 == 0) {
        cout << a << " is the ";
        for (int i = 0; i < res2; i++) {
            if (i == res2-1) {
                cout << "mother";
            } else if (i == res2-2) {
                cout << "grand-";
            } else {
                cout << "great-";
            }
        }
        cout << " of " << b << endl;
    } else if (res2 == 0) {
        cout << b << " is the ";
        for (int i = 0; i < res1; i++) {
            if (i == res1-1) {
                cout << "mother";
            } else if (i == res1-2) {
                cout << "grand-";
            } else {
                cout << "great-";
            }
        }
        cout << " of " << a << endl;
    } else {
        if (res1 == res2 && res1 == 1) {
            cout << "SIBLINGS" << endl;
        } else if (res1 == 1) {
            cout << a << " is the ";
            for (int i = 1; i < res2; i++) {
                if (i == res2-1) {
                    cout << "aunt";
                } else {
                    cout << "great-";
                }
            }
            cout << " of " << b << endl;
        } else if (res2 == 1) {
            cout << b << " is the ";
            for (int i = 1; i < res1; i++) {
                if (i == res1-1) {
                    cout << "aunt";
                } else {
                    cout << "great-";
                }
            }
            cout << " of " << a << endl;
        } else {
            cout << "COUSINS" << endl;
        }
    }
}