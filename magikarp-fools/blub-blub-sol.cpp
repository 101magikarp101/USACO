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

void bubble() {
    for (int i = 1; i < N; i++) {
        if (a[i] > a[i+1]) {
            swap(a[i], a[i+1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    bubble();
    bubble();
    for (int i = 1; i <= N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}