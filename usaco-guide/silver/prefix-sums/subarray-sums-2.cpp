#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    map<long long, long long> m;
    m[0] = 1;
    long long a[200000], s[200000];
    long long count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = (i == 0 ? 0 : s[i - 1]) + a[i];
        count += (m[s[i] - x]);
        m[s[i]]++;
    }
    cout << count << endl;
}