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
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main () {
    string s;
    cin >> s;
    if (s == "Anthony" || s == "Fikky" || s == "Shawn" || s == "Tony") {
        cout << "YES" << endl;
    } else if (s == "Victor") {
        cout << "SOMETIMES" << endl;
    } else {
        cout << "NO" << endl;
    }
}