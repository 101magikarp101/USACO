#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    ll times[200000];
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        times[i] = a;
        ans += b-a;
    }
    sort(times, times + N);
    for (int i = 0; i < N; i++) {
        ans -= times[i] * (N - i - 1);
    }
    cout << ans << endl;
}