#include <iostream>
#include <map>

using namespace std;

int main () {
    string s;
    cin >> s;
    int n = s.length();
    int a[200000];
    int pows[200000];
    int sum[200000];
    pows[0] = 1;
    map<int, int> m;
    for (int i = 1; i < 200000; i++) {
        pows[i] = (pows[i - 1] * 10) % 2019;
    }
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    long long count = 0;
    sum[0] = (pows[n - 1] * a[0]) % 2019;
    m[sum[0]]++;
    for (int i = 1; i < n; i++) {
        sum[i] = (sum[i - 1] + pows[n - i - 1] * a[i]) % 2019;
        m[sum[i]]++;
    }
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->first == 0) {
            count += it->second;
        }
        count += (it->second * (it->second - 1)) / 2;
    }
    cout << count << endl;
}