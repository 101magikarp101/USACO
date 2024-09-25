#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "w", stdout);
    //set seed for random number generator
    srand(time(0));
    cout << 10 << '\n';
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            cout << rand()%100+1 << " ";
        }
        cout << '\n';
    }
    return 0;
}