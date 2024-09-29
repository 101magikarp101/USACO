#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

int T, N;
int a[200005];

string tobin(int x) {
    string s = "";
    for (int i = 0; i < 3; i++) {
        s += (x%2)+'0';
        x /= 2;
    }
    reverse(all(s));
    return s;
}

vt<vt<char>> makeboard(string s) {
    vt<vt<char>> board(3,vt<char>(3,'.'));
    for (int i = 0; i < 9; i++) {
        if (s[i]=='1') {
            board[i/3][i%3] = 'O';
        }
    }
    for (int i = 9; i < 18; i++) {
        if (s[i]=='1' && s[i-9]=='1') {
            board[(i-9)/3][(i-9)%3] = 'X';
        }
    }
    return board;
}

bool win(vt<vt<char>> a, char c) {
    for (int i = 0; i < 3; i++) {
        if (a[i][0]==c && a[i][1]==c && a[i][2]==c) return 1;
        if (a[0][i]==c && a[1][i]==c && a[2][i]==c) return 1;
    }
    if (a[0][0]==c && a[1][1]==c && a[2][2]==c) return 1;
    if (a[0][2]==c && a[1][1]==c && a[2][0]==c) return 1;
    return 0;
}

bool draw(vt<vt<char>> a) {
    bool good = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j]=='.') good = 0;
        }
    }
    return good;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        string s; cin >> s;
        s = s.substr(1,sz(s)-1);
        // cout << "s: " << s << endl;
        string bin = "";
        for (char c : s) {
            bin += tobin(c-'0');
        }
        if (sz(bin)>19) {
            bin = bin.substr(sz(bin)-19,19);
        } else {
            bin = string(19-sz(bin),'0')+bin;
        }
        reverse(all(bin));
        // cout << "bin: " << bin << endl;
        vt<vt<char>> board = makeboard(bin);
        // cout << "board: " << endl;
        // for (int i = 0; i < 3; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         cout << board[i][j];
        //     }
        //     cout << endl;
        // }
        bool ans = 0;
        if (bin[18]=='1') {
            ans = win(board,'O');
            if (ans) {
                cout << "O wins" << endl;
                continue;
            } else if (!ans) {
                if (draw(board)) {
                    cout << "Cat's" << endl;
                } else {
                    cout << "In progress" << endl;
                }
            }
        } else {
            ans = win(board,'X');
            if (ans) {
                cout << "X wins" << endl;
                continue;
            } else if (!ans) {
                if (draw(board)) {
                    cout << "Cat's" << endl;
                } else {
                    cout << "In progress" << endl;
                }
            }
        }
    }
    return 0;
}