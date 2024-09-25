#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << "1\n20\n";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 38);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cout << dis(gen) << " ";
        }
        cout << endl;
    }
    return 0;
}