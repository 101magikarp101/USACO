#include <iostream>
#include <map>

using namespace std;

int main () {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int a[100000];
        string s;
        cin >> s;
        map<int, int> m;
        for (int j = 0; j < n; j++) {
            a[j] = s[j] - '0' - 1;
        }
        int sums[100000];
        sums[0] = a[0];
        m[0]++;
        m[sums[0]]++;
        for (int j = 1; j < n; j++) {
            sums[j] = sums[j - 1] + a[j];
            m[sums[j]]++;
        }
        long long ans = 0;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            ans += (long long)it->second * (it->second - 1) / 2;
            //cout << it->first << " " << it->second << endl;
        }
        cout << ans << endl;
    }
}