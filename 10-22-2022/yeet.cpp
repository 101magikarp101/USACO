#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string input;
    cin >> input;
    vector<bool> v = {};
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        if (input[i] == 'G' && input[i + 1] == 'H') {
            v.push_back(0);
        }
        else if (input[i] == 'H' && input[i + 1] == 'G'){
            v.push_back(1);
        }
    }
    ans += !v[0];
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
            ans++;
        }
    }
    int ans0
    std::cout << ans << std::endl;
}