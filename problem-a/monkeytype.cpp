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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set<string> s;
string hm =  "qaqwwqwawsweewesederrerdrfrttrtftgtyytygyhyuuyuhujuiiuijikiooiokoloppoplawasazsaswsesdsxszdedrdfdcdxdsfrftfgfvfcfdgtgyghgbgvgfhyhuhjhnhbhgjujhjnjmjkjikikjkmklkololklpzazszxxzxsxdxccxcdcfcvvcvfvgvbbvbgbhbnnbnhnjnmmnmjmk";
string hm1 = "qaqwwqwawsweewesederrerdrfrttrtftgtyytygyhyuuyuhujuiiuijikiooiokoloppoplaqawasazswsesdsxszsadedrdfdcdxdsfrftfgfvfcfdgtgyghgbgvgfhyhuhjhnhbhgjujijkjmjnjhkikoklkmkjlolplkzazszxxsxdxcxzcdcfcvcxvfvgvbvcbgbhbnbvnhnjnmnbmjmkmn";
int main () {
    string str; cin >> str;
    for (int i = 0; i < hm1.length()-2; i+=2) {
        s.insert(hm1.substr(i, 2));
        cout << hm1.substr(i, 2) << endl;
    }
    bool ans = s.find(str) != s.end();
    reverse(str.begin(), str.end());
    ans |= s.find(str) != s.end();
    ans |= str[0] == str[1];
    cout << (ans ? "YES" : "NO") << "\n";
}