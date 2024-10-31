#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<char, int> m;
    char arr[100005];
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        m[c]++;
        arr[i] = c;
    }
    int l = 0;
    int r = 0;
    int min = INT32_MAX;
    map<char, int> m2;
    while (true) {
        while (r < n && m2.size() < m.size()) {
            m2[arr[r]]++;
            r++;
        }
        while (l < r && m2.size() == m.size()) {
            if (r - l < min) {
                min = r - l;
            }
            m2[arr[l]]--;
            if (m2[arr[l]] == 0) {
                m2.erase(arr[l]);
            }
            l++;
        }
        if (r == n) {
            break;
        }
    }
    cout << min << endl;
}