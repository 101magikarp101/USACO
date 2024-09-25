#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string row; cin >> row;
    vt<int> res;
    for (int i = 0; i < row.size(); i++) {
        if (row[i] == 'R') {
            res.push_back(0);
        } else if (row[i] == 'G') {
            res.push_back(1);
        } else {
            res.push_back(2);
        }
    }
    vt<int> hm;
    hm.push_back(2);
    for (int i = 0; i < 10; i++) {
        int x = hm.back();
        hm.push_back(x*3-2);
    }
    int cur = 10;
    while (res.size() > 1) {
        while (res.size() < hm[cur]) {
            cur--;
            cout << "cur: " << cur << endl;
        }
        vt<int> res1;
        for (int i = 0; i+hm[cur]-1 < res.size(); i++) {
            res1.push_back((6-res[i]-res[i+hm[cur]-1])%3);
        }
        res = res1;
    }
    if (res[0] == 0) {
        cout << "R" << endl;
    } else if (res[0] == 1) {
        cout << "G" << endl;
    } else {
        cout << "B" << endl;
    }
    return 0;
}