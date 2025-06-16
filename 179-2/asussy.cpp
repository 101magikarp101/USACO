#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    int n = 200000;
    int q = 200000;

    // Print number of test cases
    cout << t << "\n";

    // Print n and q
    cout << n << " " << q << "\n";

    // Print a string of length n consisting entirely of 'c'
    string s(n, 'c');
    cout << s << "\n";

    // First 100000 operations: "c b"
    for (int i = 0; i < 100000; i++) {
        cout << "c b\n";
    }
    // Next 100000 operations: "b a"
    for (int i = 0; i < 100000; i++) {
        cout << "b a\n";
    }

    return 0;
}
