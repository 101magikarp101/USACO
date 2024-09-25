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

using namespace std;

int T;
int N;
int a[203];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < 2*N; i++) {
            cin >> a[i];
        }
        sort(a,a+2*N);
        int ans = a[N-1] - a[0] + a[2*N-1] - a[N];
        cout << ans << endl;
        for (int i = 0; i < N; i++) {
            cout << a[i] << " " << a[i+N] << endl;
        }
    }
}