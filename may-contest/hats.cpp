#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N;
int a[1000005];

int main() {
    // freopen("input.txt", "w", stdout);
    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<int> n(1, 1000000);
    // int nn = 1000000;
    // cout << nn << endl;
    // for (int i = 0; i < nn; i++) {
    //     int x = n(gen);
    //     if (x>=999999) {
    //         cout << 0 << ' ';
    //     } else {
    //         cout << 1 << ' ';
    //     }
    // }
    // cout << endl;
    // fclose(stdout);
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        if (a[i]!=a[1]) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}