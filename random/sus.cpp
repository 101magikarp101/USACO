#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
char a[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int hm = (N*N+1)/2;
    cout << hm << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i+j)%2 ==0) {
                cout << "C";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    return 0;
}