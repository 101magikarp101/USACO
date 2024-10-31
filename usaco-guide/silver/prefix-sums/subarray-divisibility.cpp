#include <iostream>
#include <map>

using namespace std;

int main () {
    long long n;
    cin >> n;
    long long a[200000], s[200000];
    map<long long, long long> m;
    m[0] = 1;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = ((i == 0 ? 0 : s[i - 1]) + a[i]) % n;
        if (s[i] < 0) {
            s[i] += n;
        }
        count += (m[s[i]]);
        m[s[i]]++;
    }
    cout << count << endl;
}