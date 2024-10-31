#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    //freopen("stacking.in", "r", stdin);
    //freopen("stacking.out", "w", stdout);
    long n, k;
    cin >> n >> k;
    long a[1000000], s[1000000];
    for (int i = 0; i < k; i++) {
        long start, end;
        cin >> start >> end;
        a[start - 1]++;
        if (end < n) {
            a[end]--;
        }
    }
    s[0] = a[0];
    for (int i = 1; i < n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    sort(s, s + n);
    //cout << s << endl;
    cout << s[n / 2] << endl;
}