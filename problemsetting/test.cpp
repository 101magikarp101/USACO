#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
struct pii {int x, y;};
struct pll {
    ll x, y;
    pll operator+(pll b) {
        return {x+b.x, y+b.y};
    }
    pll operator-(pll b) {
        return {x-b.x, y-b.y};
    }
    pll operator*(ll b) {
        return {x*b, y*b};
    }
    pll operator/(ll b) {
        return {x/b, y/b};
    }
    bool operator>(pll b) {
        return x > b.x && y > b.y;
    }
};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //[[-3,2,1,1],[-3,1,5,1],[-3,3,1,1]]
    vt<vt<int>> a = {{-3,2,1,1},{-3,1,5,1},{-3,3,1,1}};
    for (int i = 0; i < 3; i++) {
        sort(all(a[i]), greater<int>());
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}