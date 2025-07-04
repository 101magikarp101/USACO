#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        int a, b, c;
        cout << "? 1 1" << endl;
        cout.flush();
        cin >> a;
        cout << "? " << N << " 1" << endl;
        cout.flush();
        cin >> b;
        cout << "? " << N << " " << M << endl;
        cout.flush();
        cin >> c;
        int x = N-b+a+1;
        if (x%2==0) {
            int y = -x/2+a+2;
            if (abs(x-N)+abs(y-M) == c) {
                cout << "! " << x << " " << y << endl;
                cout.flush();
                continue;
            }
        }
        int xx = (2*N+M-b-1-c)/2;
        int yy = xx+-N+b+1;
        cout << "! " << xx << " " << yy << endl;
        cout.flush();
    }
    return 0;
}