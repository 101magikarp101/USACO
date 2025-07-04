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
#include <unordered_map>
#include <deque>
#include <climits>
#include <random>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string sf = "0123456789ABCDEF";
string s1 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz,.!@#$%^&*()_+-=";

vt<int> hextobin(string s) {
    vt<int> ans;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i]-'0';
        if (x > 9) x -= 7;
        for (int j = 3; j >= 0; j--) {
            ans.push_back((x&(1<<j))>>j);
        }
    }
    return ans;
}

int main () {
    string hex, s;
    // cin >> hex >> s;
    uniform_int_distribution<int> dist(0, 15);
    uniform_int_distribution<int> dist1(0, s1.size()-1);
    random_device rd;
    mt19937 rng(rd());
    for (int i = 0; i < 1000000; i++) {
        hex += sf[dist(rng)];
    }
    for (int i = 0; i < 4000000; i++) {
        s += s1[dist1(rng)];
    }
    freopen("input.txt", "w", stdout);
    cout << hex << "\n" << s << "\n";
    fclose(stdout);
    freopen("output.txt", "w", stdout);
    vt<int> bin = hextobin(hex);
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i] == 1) {
            cout << s[i];
        }
    }
    cout << "\n";
    fclose(stdout);
}